#include <iostream>
#include <string>
#include <cstdarg>
#include <fstream>

using namespace std;

void rozdzielNaHex(string plikWejscie, int liczbaWyjsc, string plikWyjscie1, ...) {
    int temp = 0;
    int i = 0;

    fstream fileIn;
    fstream *fileOut = new fstream[liczbaWyjsc];

    fileIn.open(plikWejscie, fstream::in);

    va_list ap;
    va_start(ap, plikWyjscie1);

    fileOut[0].open(plikWyjscie1, fstream::out);
    fileOut[0].setf(ios::hex, ios::basefield);
    fileOut[0].setf(fileOut[0].uppercase);

    for (i = 1; i < liczbaWyjsc; i++) {
        fileOut[i].open(va_arg(ap, char *), fstream::out);
        fileOut[i].setf(ios::hex, ios::basefield);
        fileOut[i].setf(fileOut[i].uppercase);
    }

    i = 0;

    while (fileIn >> temp) {
        fileOut[i] << temp << endl;

        ++i %= liczbaWyjsc;
    }

    for (i = 0; i < liczbaWyjsc; i++)
    {
        fileOut[i].setf(ios::hex, ios::basefield);
        fileOut[i].setf(fileOut[i].uppercase);
        fileOut[i].close();
    }

    delete[] fileOut;

    fileIn.close();

    va_end(ap);
}

void polaczNaDec(string plikWyjscie, int liczbaWejsc, string plikWejscie1, ...) {
    unsigned int temp = 0;
    int posTemp = 0;
    int i = 0;

    fstream *fileIn = new fstream[liczbaWejsc];
    fstream fileOut;

    fileOut.open(plikWyjscie, fstream::out);

    va_list ap;
    va_start(ap, plikWejscie1);

    fileIn[0].open(plikWejscie1, fstream::in);
    fileIn[0].setf(ios::hex, ios::basefield);

    for (i = 1; i < liczbaWejsc; i++)
    {
        fileIn[i].open(va_arg(ap, char *), fstream::in);
        fileIn[i].setf(ios::hex, ios::basefield);
    }

    i = 0;

    while (fileIn[i] >> temp)
    {
        posTemp |= temp;
        fileOut << posTemp << endl;
        posTemp = 0;

        ++i %= liczbaWejsc;
    }

    for (i = 0; i < liczbaWejsc; i++)
    {
        fileIn[i].setf(ios::hex, ios::basefield);
        fileIn[i].close();
    }

    delete[] fileIn;

    fileOut.close();

    va_end(ap);
}

int main() {
    rozdzielNaHex("plikWejscie.txt", 3, "plikWyjscie1.txt", "plikWyjscie2.txt", "plikWyjscie3.txt");

    polaczNaDec("plikWejscie1.txt", 3, "plikWyjscie1.txt", "plikWyjscie2.txt", "plikWyjscie3.txt");

    return 0;
}