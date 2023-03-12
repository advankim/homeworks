#include<iostream>

using namespace std;

void wypiszW(int dlugosc, double wynikowyW[]) {
    cout << "W(x) = ";

    if (dlugosc <= 0) cout << "0\n";
    else {
        int potega = dlugosc - 1;
        int i = 0;

        if (potega > 1) cout << wynikowyW[0] << "x" << potega << " ";
        else if (potega == 1) cout << wynikowyW[0] << "x ";
        else if (potega == 0) cout << wynikowyW[0];

        potega--;

        for (i = 1; i < dlugosc; i++) {
            if (wynikowyW[i] < 0) cout << "- " << wynikowyW[i] * -1;
            else if (wynikowyW[i] > 0) cout << "+ " << wynikowyW[i];

            if (wynikowyW[i] != 0) {
                if (potega > 1) cout << "x" << potega << " ";
                else if (potega == 1) cout << "x ";
                else if (potega == 0);
            }

            potega--;
        }

        cout << endl;
    }
}

void sumaW(int dlugoscPierwszyW, int dlugoscDrugiW, double pierwszyW[], double drugiW[]) {
    double wynikowyW[100] = {};
    int i = 0;

    if (dlugoscPierwszyW > dlugoscDrugiW) {
        for (i = 0; i < dlugoscPierwszyW; i++) {
            wynikowyW[i] = pierwszyW[i];
        }

        int roznicaDlugosc = dlugoscPierwszyW - dlugoscDrugiW;

        for (i = 0; i < dlugoscDrugiW; i++) {
            wynikowyW[i + roznicaDlugosc] += drugiW[i];
        }

        wypiszW(dlugoscPierwszyW, wynikowyW);
    }
    else if (dlugoscPierwszyW < dlugoscDrugiW) {
        for (i = 0; i < dlugoscDrugiW; i++) {
            wynikowyW[i] = drugiW[i];
        }

        int roznicaDlugosc = dlugoscDrugiW - dlugoscPierwszyW;

        for (i = 0; i < dlugoscPierwszyW; i++) {
            wynikowyW[i + roznicaDlugosc] += pierwszyW[i];
        }

        wypiszW(dlugoscDrugiW, wynikowyW);
    }
    else {
        for (i = 0; i < dlugoscPierwszyW; i++) {
            wynikowyW[i] = pierwszyW[i] + drugiW[i];
        }

        wypiszW(dlugoscPierwszyW, wynikowyW);
    }

}

int main()
{
    int dlugoscPierwszyW = 0;
    int dlugoscDrugiW = 0;

    double pierwszyW[100] = {};
    double drugiW[100] = {};

    int i = 0;

    cin >> dlugoscPierwszyW;
    
    for (i = 0; i < dlugoscPierwszyW; i++) {
        cin >> pierwszyW[i];
    }

    cin >> dlugoscDrugiW;

    for (i = 0; i < dlugoscDrugiW; i++) {
        cin >> drugiW[i];
    }

    sumaW(dlugoscPierwszyW, dlugoscDrugiW, pierwszyW, drugiW);

    return 0;
}
