#include <iostream>
#include <string>

using namespace std;

void Display(unsigned char binary) {
    for (int i = 128; i > 0; i /= 2) {
        if (binary & i) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }

    cout << endl;
}

//funkcja zamienia napis złożony z ośmiu zer i jedynek na jego binarną
//reprezentację w zmiennej char. Do dostępu do poszczególnych liter stringa można
//wykorzystać [] lub *.
unsigned char zakoduj(string napisBinarny) {
    unsigned char reprezentacjaBinarna = 0;
    int bit = 1;
    int i = 0;

    bit <<= napisBinarny.size() - 1;

    while (bit != 0) {
        if (napisBinarny[i] == '1') {
            reprezentacjaBinarna |= bit;
        }

        bit >>= 1;
        i++;
    }

    return reprezentacjaBinarna;
}

//jest odwrotnością poprzedniej funkcji. Do dostępu do poszczególnych liter stringa można wykorzystać [] lub *.
string odkoduj(unsigned char reprezentacjaBinarna) {
    string napisBinarny = "";
    int bit = 128;

    while (bit != 0) {
        if (reprezentacjaBinarna & bit) {
            napisBinarny += "1";
        }
        else {
            napisBinarny += "0";
        }

        bit >>= 1;
    }

    return napisBinarny;
}

//szyfrowanie XOR-em, NIE UŻYWAJ OPERATORA ^.
unsigned char zaszyfruj(unsigned char tekst, unsigned char klucz) {
    unsigned char kod = 0;

    kod = (tekst & (~klucz)) | ((~tekst) & klucz);

    return kod;
}

//odszyfrowywanie XOR-em, NIE UŻYWAJ OPERATORA ^. Czy zamiana argumentów coś
//zmienia? Czy ta funkcja potrzebna?
unsigned char odszyfruj(unsigned char kod, unsigned char klucz) {
    unsigned char tekst = 0;

    tekst = (kod & (~klucz)) | ((~kod) & klucz);

    return tekst;
}

//funkcja szyfruje XOR-em tekst złożony z dowolnej liczby zer i jedynek za pomocą klucza
//(zakładamy, że tej samej długości co tekst).
//Napisz program wykonujący tą funkcję z argumentami wywołania main-a.
string zaszyfruj(string tekst, string klucz) {
    string kod = "";
    unsigned char wartoscTekst = 0;
    unsigned char wartoscKlucz = 0;

    int dlugosc = tekst.size() / 8;
    int i = 0;

    for (i = 0; i < dlugosc; i++) {
        wartoscTekst = zakoduj(tekst.substr(i * 8, 8));
        wartoscKlucz = zakoduj(klucz.substr(i * 8, 8));

        wartoscTekst ^= wartoscKlucz;

        kod += odkoduj(wartoscTekst);
    }

    dlugosc = tekst.size() % 8;

    if (dlugosc > 0) {
        wartoscTekst = zakoduj(tekst.substr(i * 8, dlugosc));
        wartoscKlucz = zakoduj(klucz.substr(i * 8, dlugosc));

        wartoscTekst ^= wartoscKlucz;

        kod += odkoduj(wartoscTekst).substr(8 - dlugosc, dlugosc);
    }

    return kod;
}

//jest odwrotnością poprzedniej funkcji. Napisz program wykonujący tą funkcję z
//argumentami wywołania main-a.
string odszyfruj(string kod, string klucz) {
    string tekst;
    unsigned char wartoscKod = 0;
    unsigned char wartoscKlucz = 0;

    int dlugosc = kod.size() / 8;
    int i = 0;

    for (i = 0; i < dlugosc; i++) {
        wartoscKod = zakoduj(kod.substr(i * 8, 8));
        wartoscKlucz = zakoduj(klucz.substr(i * 8, 8));

        wartoscKod ^= wartoscKlucz;

        tekst += odkoduj(wartoscKod);
    }

    dlugosc = kod.size() % 8;

    if (dlugosc > 0) {
        wartoscKod = zakoduj(kod.substr(i * 8, dlugosc));
        wartoscKlucz = zakoduj(klucz.substr(i * 8, dlugosc));

        wartoscKod ^= wartoscKlucz;

        tekst += odkoduj(wartoscKod).substr(8 - dlugosc, dlugosc);
    }

    return tekst;
}

//szyfrowanie Państwa własnym algorytmem. Ma on wykorzystywać XOR i operator przesunięcia.
unsigned char zaszyfruj2(unsigned char tekst, unsigned char klucz) {
    unsigned char kod = 0;

    if (klucz < 128) {
        klucz >>= 2;
    }
    else {
        klucz <<= 1;
    }

    kod = tekst ^ klucz;

    return kod;
}

//odwrotność poprzedniej funkcji.
unsigned char odszyfruj2(unsigned char kod, unsigned char klucz) {
    unsigned char tekst = 0;

    if (klucz < 128) {
        klucz >>= 2;
    }
    else {
        klucz <<= 1;
    }

    tekst = kod ^ klucz;

    return tekst;
}

//”czyta” tekst o dowolnej długości złożony z zer i jedynek
//przykładowo dla argumentu "1010101011" zwracany jest napis
//"jeden zero jeden zero jeden zero jeden zero jeden jeden".
//Napisz program wykonujący tą funkcję z argumentami wywołania main-a.
string przeczytaj(string tekst) {
    string napis = "";

    unsigned char wartoscTekst = 0;

    int dlugosc = tekst.size() / 8;
    int bit = 1;
    int i = 0;

    for (i = 0; i < dlugosc; i++) {
        wartoscTekst = zakoduj(tekst.substr(i * 8, 8));

        bit = 128;
        
        while (bit != 0) {
            if (bit & wartoscTekst) {
                napis += "jeden ";
            }
            else {
                napis += "zero ";
            }

            bit >>= 1;
        }
    }

    dlugosc = tekst.size() % 8;

    if (dlugosc > 0) {
        wartoscTekst = zakoduj(tekst.substr(i * 8, dlugosc));

        bit = 1;
        bit <<= dlugosc - 1;

        while (bit != 0) {
            if (bit & wartoscTekst) {
                napis += "jeden ";
            }
            else {
                napis += "zero ";
            }

            bit >>= 1;
        }
    }

    return napis;
}

int main(int argc, char* argv[]) {
    string tekst = "10101011";
    string klucz = "00100010";
    unsigned char reprezentacjaBinarna = 0;

    reprezentacjaBinarna = zakoduj(tekst);
    tekst = odkoduj(reprezentacjaBinarna);

    reprezentacjaBinarna = zaszyfruj(reprezentacjaBinarna, 64);
    reprezentacjaBinarna = odszyfruj(reprezentacjaBinarna, 64);

    reprezentacjaBinarna = zaszyfruj2(reprezentacjaBinarna, 64);
    reprezentacjaBinarna = odszyfruj2(reprezentacjaBinarna, 64);

    for (int i = 1; i < argc; i += 2) {
        cout << zaszyfruj(argv[i], argv[i + 1]) << endl;
    }

    for (int i = 1; i < argc; i += 2) {
        cout << odszyfruj(argv[i], argv[i + 1]) << endl;
    }

    for (int i = 1; i < argc; i++) {
        cout << przeczytaj(argv[i]) << endl;
    }

    return 0;
}