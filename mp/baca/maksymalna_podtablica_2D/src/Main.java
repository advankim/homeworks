//Mateusz Rozdzinski - 5

import java.util.Scanner;

//Program wyznacza w zadanej tablicy dwuwymiarowej maksymalna podtablice 2D elementow o najmniejszej liczbie elementow.
//Maksymalna podtablica jest okreslona jako taka podtablica, ktorej suma elementow jest najwieksza, a jednoczesnie posiadajac mozliwie najmniejsze wymiary.
//Program zaimplementowany z uzyciem jezyka Java obsluguje jedna klase Source, w ktorej zawarte sa 3 metody: inputSet, maxArrayTwoDimensionalSum oraz main.
//Algorytm (maxArrayTwoDimensionalSum) jednoczesnie ma zlozonosc w pesymistycznym scenariuszu (tablica kwadratowa) O(n^3). Przy nieregularnych wymiarach ta zlozonosc jest mniejsza.

class Source {
    //Deklaracja zmiennej klasy Scanner, umozliwiajaca wczytywanie danych
    public static Scanner in = new Scanner(System.in);

    //Metoda wczytuje liczby do tablicy 2D typu boolean, false w przypadku tablicy pustej (wszystkie liczby < 0), prawda w przypadku tablicy niepustej
    public static boolean inputSet(int[][] setsArray, int [][] tempArray, int n, int m) {
        boolean emptiness = true;

        //Wczytanie danych w petli n * m razy
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //Wywolanie metody klasy Scanner, wczytanie liczby
                setsArray[i][j] = in.nextInt();
                //Uzupelnianie tablicy sum prefiksowych
                tempArray[i + 1][j] = tempArray[i][j] + setsArray[i][j];

                //Jezeli niepusta, metoda zwroci false
                if (setsArray[i][j] >= 0) {
                    emptiness = false;
                }
            }
        }

        return emptiness;
    }

    //Metoda obsluguje zmodyfikowany algorytm Kadane dla tablicy 2D, wykorzystuje pomocniczo tablice sum prefiksowych
    public static void maxArrayTwoDimensionalSum(int[][] setsArray, int[][] tempArray, int n, int m, int setIndex) {
        //Zmienne beda przyjmowac parametry podtablicy - suma, indeksy wiersza, indeksy kolumny
        int sum = -1;
        int rowFirst = 0;
        int rowLast = 0;
        int columnFirst = 0;
        int columnLast = 0;

        //Zmienne pomocnicze, rowCount okresla ilosc uzywanych wierszy, elemCount bedzie przyjmowac ilosc elementow w podtablicy
        int rowCount = 1;
        int elemCount = 0;

        //Trzy petle n * n * m, maksymalna zlozonosc to O(max(n, m)^3) w przypadku tablicy kwadratowej, przy mniejszej ilosci wierszy zlozonosc sie zmniejsza
        //Zewnetrzna petla zarzadza kombinacjami tablicy sum prefiksowych
        for (int i = 0; i < n; i++) {
            //Reset ilosci uzywanych wierszy
            rowCount = 1;
            //Petla srodkowa zarzadza wierszami w danym "ulozeniu" tablicy sum prefiksowych
            for (int j = i; j < n; j++) {
                //Zmienna dodaje wartosci komorek
                int curr = 0;
                //Wskazywanie na poczatkowa kolumne w wyznaczanej podtablicy
                int firstColOfRow = 0;
                //Zmienna pomocnicza przyjmuje wielkosc podtablicy na dany moment
                int elemCountTemp = 0;
                //Zmienna pomocnicza boolean umozliwia pomijanie wartosci ujemnych i zerowych, na przyklad w pierwszych kolumnach
                boolean flag = true;

                //Petla wewnetrzna wykonuje algorytm Kadane dla danego wiersza
                for (int k = 0; k < m; k++) {
                    //Warunek sprawdzajacy (w momencie ustawionej zmiennej flag na true) czy obecna pozycja jest ujemna badz zerowa, jezeli tak to pomija te komorke
                    if ((tempArray[j + 1][k] - tempArray[i][k]) <= 0 && flag == true) {
                        //W specyficznym przypadku samych liczb ujemnych i zer warunek znajduje pierwsze zero, jakie napotka.
                        if (tempArray[j + 1][k] - tempArray[i][k] == 0 && sum == -1) {
                            //Ustawienie dla powyzszego spelnionego warunku parametrow podtablicy
                            sum = 0;
                            rowFirst = j;
                            rowLast = j;
                            columnFirst = k;
                            columnLast = k;
                        }

                        //Inkrementacja przesuwa pierwsza pozycje potencjalnej podtablicy
                        firstColOfRow = k + 1;

                        continue;
                    }
                    else {
                        //Else oznacza element dodatni, flaga zostaje ustawiona na false, poniewaz podtablica moze zawierac liczby zerowe badz ujemne,
                        //jednak w przypadku wykorzystywania tablicy sum prefiksowych nigdy sie w takim przypadku od nich nie zaczyna. Sama podtablica w
                        //rezultacie moze sie od liczb ujemnych i zerowych zaczynac.
                        flag = false;
                    }

                    //Dodanie do zmiennej curr obecnej komorki, w zaleznosci od etapu przyjmuje komorke z oryginalnej tablicy,
                    //a maksymalnie sume calej kolumny
                    curr += tempArray[j + 1][k] - tempArray[i][k];

                    //Dodanie liczby elementow do zmiennej pomocniczej
                    elemCountTemp++;

                    //Jezeli curr <= 0 to nastepuje wyzerowanie i szukanie podtablicy od nowa
                    if (curr <= 0) {
                        //Wyzerowanie curr, ustawienie nowego indeksu nowej podtablicy, ustawienie flag na true (mozliwosc ponownych i niepotrzebnych w wyznaczaniu ujemnych i zer)
                        curr = 0;
                        firstColOfRow = k + 1;
                        elemCountTemp = 0;

                        flag = true;
                    }
                    //Jezeli chwilowa suma jest wieksza od wyznaczonej dotychczas sumy
                    else if (sum < curr) {
                        //Ustawienie parametrow obecnej podtablicy
                        sum = curr;
                        //Zmienne przyjmuja indeksy podtablicy w zaleznosci od wartosci zmiennych petli for
                        rowFirst = i;
                        rowLast = j;
                        columnFirst = firstColOfRow;
                        columnLast = k;

                        //Ustawienie obecnej ilosci elementow, powoduje to brak mozliwosci wyznaczenia wiekszej tablicy lub o takiej samej sumie, ktora znajduje sie dalszym porzadku leksykograficznym
                        elemCount = elemCountTemp * rowCount;
                    }
                    //Sytuacja, w ktorej suma jest taka sama jak poprzedniej podtablicy, ale nowa podtablica jest mniejsza
                    else if (sum == curr && elemCountTemp * rowCount < elemCount) {
                        //Ustawienie parametrow obecnej podtablicy
                        sum = curr;
                        //Zmienne przyjmuja indeksy podtablicy w zaleznosci od wartosci zmiennych petli for
                        rowFirst = i;
                        rowLast = j;
                        columnFirst = firstColOfRow;
                        columnLast = k;

                        //Ustawienie obecnej ilosci elementow, powoduje to brak mozliwosci wyznaczenia wiekszej tablicy lub o takiej samej sumie, ktora znajduje sie dalszym porzadku leksykograficznym
                        elemCount = elemCountTemp * rowCount;
                    }
                    //Sytuacja, w ktorej jedna komorka tablicy pomocniczej (moze byc to cala kolumna) ma te sama sume co wczesniejsza wieksza podtablica
                    else if (sum == tempArray[j + 1][k] - tempArray[i][k] && rowCount < elemCount) { //warunek, wykonujacy operacje kiedy podtablica zrownala sie z suma (umozliwia znajdowanie sum o mniejszej ilosci elementow)
                        //Ustawienie parametrow obecnej podtablicy, obecnie jest to roznica w zaleznosci od parametrow petli for (od jednego elementu do calej kolumny)
                        sum = tempArray[j + 1][k] - tempArray[i][k];
                        //Zmienne przyjmuja indeksy podtablicy w zaleznosci od wartosci zmiennych petli for
                        rowFirst = i;
                        rowLast = j;
                        //Zmienne przyjmuja te same parametry, jest to spowodowane tylko jedna kolumna
                        columnFirst = k;
                        columnLast = k;

                        //Kolejne iteracje beda mogly wyznaczyc podtablice o wiekszej sumie poprzez start od obecnie ustawionej podtablicy
                        firstColOfRow = k;

                        //Ustawienie obecnej ilosci elementow, jest to ilosc rzedow w zaleznosci od wartosci rowCount (1 - m)
                        elemCount = rowCount;
                    }
                }

                //Zwiekszenie wraz z iteracja petli liczby uzywanych kolumn w tablicy sum prefiksowych
                rowCount++;
            }
        }

        //Komunikat wyswietla parametry wyznaczonej podtablicy
        System.out.printf("%d: n = %d m = %d, ms = %d, mst = a[%d..%d][%d..%d]\n", setIndex, n, m, sum, rowFirst, rowLast, columnFirst, columnLast);
    }

    public static void main(String[] args) {
        //Wczytanie liczby zestawow do zmiennej
        int setsCount = in.nextInt();

        //Petla wykonuje sie w ilosci zadanych zestawow, przyjmuje rozmiar tablicy, wywoluje metode wczytywania, wywoluje metode wyznaczania podtablicy
        for (int i = 0; i < setsCount; i++) {
            //Wczytanie numberu zestawu i wymiarow n x m
            int setIndex = in.nextInt();
            in.next();
            int n = in.nextInt();
            int m = in.nextInt();

            //Tablica n x m, otrzymuje wczytane wartosci
            int[][] setsArray = new int[n][m];
            //Tablica sum prefiksowych, jest wyznaczana wraz z wczytywaniem danych. Sumuje kolejne rzedy tablicy, zostaje wykorzystywana do zmniejszenia zlozonosci algorytmu
            int tempArray[][] = new int[n + 1][m];

            //Wywolanie metody w warunku, jest typu boolean, false oznacza tablice pusta (wszystkie wartosci < 0), prawda niepusta
            if (inputSet(setsArray, tempArray, n, m)) {
                //Wypisanie komunikatu o pustej tablicy, jezeli jest pusta
                System.out.printf("%d: n = %d m = %d, ms = 0, mst is empty\n", setIndex, n, m);
            }
            else { //Jezeli tablica nie jest pusta
                //Wywolanie metody wyznaczajacej najmniejsza podtablice o najwiekszej sumie
                //Przekazywana jest tablica, tablica pomocnicza, wymiary i numer zestawu
                maxArrayTwoDimensionalSum(setsArray, tempArray, n, m, setIndex);
            }
        }
    }
}

//test.in
//25
//1 : 2 2
//4 0
//0 1
//2 : 5 2
//-2 -2
//-3 -3
//-1 -2
//-1 0
//-3 0
//3 : 4 9
//0 -4 0 -1 4 4 1 -4 -2
//-2 0 4 -3 2 0 -4 1 -4
//-3 -3 4 4 -1 3 4 -2 -4
//1 -4 0 -2 -2 -2 -4 -4 4
//4 : 6 9
//-2 -2 0 1 0 -3 1 0 -3
//-3 1 0 -1 0 -3 4 0 2
//-1 0 2 4 1 3 4 -2 -2
//-3 -3 2 0 -1 0 0 3 0
//0 4 3 0 0 0 0 -1 0
//0 3 4 2 4 0 -2 0 3
//5 : 2 10
//0 -1 -4 -2 -2 -1 3 -4 -2 0
//-2 2 0 -1 -1 -2 0 0 3 1
//6 : 5 9
//4 4 0 0 -2 -4 3 2 -1
//3 0 4 4 -2 2 -4 -4 4
//-2 2 4 -4 2 -1 0 2 -2
//0 -1 1 4 2 3 4 -2 4
//-4 4 -2 -3 4 0 4 -4 -1
//7 : 5 2
//1 -2
//-1 -4
//-4 -2
//0 2
//-2 0
//8 : 7 3
//-4 -3 -2
//4 1 1
//-2 -3 -2
//4 1 4
//3 4 4
//4 -2 -2
//4 -3 -1
//9 : 8 6
//-4 2 1 0 -4 -2
//-4 4 -2 -3 4 -2
//3 0 3 0 -1 1
//-2 -3 2 -2 -4 -2
//1 -3 2 -2 -4 0
//-3 -2 -2 4 0 4
//4 -3 -3 2 2 3
//2 -4 -1 -3 -1 0
//10 : 6 6
//3 3 -4 1 -1 2
//-1 1 3 -3 0 -2
//-3 -1 2 -3 2 -3
//-3 3 -1 3 4 0
//0 -2 1 1 0 1
//0 1 -2 0 2 -1
//11 : 4 5
//4 -3 1 0 -2
//0 -2 -3 3 0
//4 -1 2 1 4
//0 3 -4 -2 1
//12 : 5 1
//-1
//4
//-3
//-3
//2
//13 : 8 2
//-3 0
//2 -1
//2 1
//-1 3
//-1 4
//0 0
//-1 3
//1 2
//14 : 7 1
//1
//2
//-4
//-1
//1
//0
//3
//15 : 3 10
//-4 -4 -4 0 1 1 -1 -3 -2 0
//0 3 -2 -4 -1 2 1 0 -4 -1
//2 2 0 2 1 -1 -4 -3 -1 0
//16 : 3 1
//-2
//2
//-4
//17 : 7 2
//0 0
//-2 -1
//2 2
//2 -2
//3 1
//1 4
//-3 0
//18 : 10 7
//2 0 -2 -4 0 0 -4
//-3 3 -1 -2 4 0 -3
//2 4 -2 -1 3 2 0
//4 -2 2 -4 4 -1 0
//3 3 -4 -1 4 -4 -2
//-3 0 1 -2 -2 0 -2
//2 3 -3 -1 0 -4 1
//-4 0 1 0 4 0 -4
//-1 1 -2 -2 1 -2 -2
//-2 0 1 1 -4 -4 1
//19 : 9 10
//3 -1 3 -4 -1 3 -1 -3 2 1
//-4 4 -1 2 2 2 4 -2 1 3
//-2 0 0 3 -2 -2 0 1 -1 0
//2 -3 4 4 2 -1 3 -1 0 -1
//3 2 4 1 -1 1 4 1 2 -4
//4 4 4 4 -3 -2 3 -1 4 0
//-3 0 -1 -1 0 4 -3 1 -4 -2
//-1 4 -4 4 1 3 -3 0 0 4
//-1 0 -3 4 -4 -3 -4 -4 0 1
//20 : 2 10
//-1 2 -4 0 1 0 2 2 2 2
//1 0 0 -4 0 1 4 3 -1 2
//21 : 2 10
//0 3 0 -2 2 -1 4 1 -4 -4
//-3 0 -1 -4 1 -4 0 -2 4 1
//22 : 9 8
//-2 -4 3 -1 -2 3 -2 4
//3 -2 -4 4 4 -3 -4 1
//2 -1 1 -4 -4 -1 -3 -4
//1 4 3 -1 0 -4 2 3
//-3 -1 -4 1 2 0 -4 -2
//3 3 -1 -3 4 1 -2 -3
//3 2 3 -4 0 -1 0 3
//-3 0 -4 -3 0 0 -2 -3
//4 3 -1 1 1 2 1 4
//23 : 2 2
//-1 0
//0 -1
//24 : 2 2
//-1 -1
//-1 0
//25 : 1 5
//0 1 2 0 3

//test.out
//1: n = 2 m = 2, ms = 5, mst = a[0..1][0..1]
//2: n = 5 m = 2, ms = 0, mst = a[3..3][1..1]
//3: n = 4 m = 9, ms = 21, mst = a[0..2][2..6]
//4: n = 6 m = 9, ms = 34, mst = a[1..5][1..8]
//5: n = 2 m = 10, ms = 4, mst = a[1..1][8..9]
//6: n = 5 m = 9, ms = 29, mst = a[0..4][0..6]
//7: n = 5 m = 2, ms = 2, mst = a[3..3][1..1]
//8: n = 7 m = 3, ms = 20, mst = a[3..4][0..2]
//9: n = 8 m = 6, ms = 15, mst = a[5..6][3..5]
//10: n = 6 m = 6, ms = 11, mst = a[1..5][1..4]
//11: n = 4 m = 5, ms = 10, mst = a[2..2][0..4]
//12: n = 5 m = 1, ms = 4, mst = a[1..1][0..0]
//13: n = 8 m = 2, ms = 14, mst = a[1..7][0..1]
//14: n = 7 m = 1, ms = 4, mst = a[4..6][0..0]
//15: n = 3 m = 10, ms = 7, mst = a[1..2][0..1]
//16: n = 3 m = 1, ms = 2, mst = a[1..1][0..0]
//17: n = 7 m = 2, ms = 13, mst = a[2..5][0..1]
//18: n = 10 m = 7, ms = 18, mst = a[1..8][4..4]
//19: n = 9 m = 10, ms = 50, mst = a[0..5][0..8]
//20: n = 2 m = 10, ms = 18, mst = a[0..1][4..9]
//21: n = 2 m = 10, ms = 7, mst = a[0..0][1..7]
//22: n = 9 m = 8, ms = 18, mst = a[1..8][0..1]
//23: n = 2 m = 2, ms = 0, mst = a[0..0][1..1]
//24: n = 2 m = 2, ms = 0, mst = a[1..1][1..1]
//25: n = 1 m = 5, ms = 6, mst = a[0..0][1..4]