#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	//liczba rozgrywek

	float aWygrane = 0;
	float bWygrane = 0;
	float cWygrane = 0;
	float dWygrane = 0;

	float aRemisy = 0;
	float bRemisy = 0;
	float cRemisy = 0;
	float dRemisy = 0;;

	float aPrzegrane = 0;
	float bPrzegrane = 0;
	float cPrzegrane = 0;
	float dPrzegrane = 0;

	int aLiczbaGier = 0;
	int bLiczbaGier = 0;
	int cLiczbaGier = 0;
	int dLiczbaGier = 0;
	//statystyki graczy

	char idGraczaPierwszy;
	char idGraczaDrugi;
	//gracze w danej rundzie

	char wyborPierwszy;
	char wyborDrugi;
	//wybory graczy

	int silaPierwsza = 0;
	int silaDruga = 0;
	//sily wyborow graczy

	int wygrany = 0;
	//gracz wygrany

	cin >> i;

	while (i > 0)
	{
		cin >> idGraczaPierwszy >> wyborPierwszy >> silaPierwsza >> idGraczaDrugi >> wyborDrugi >> silaDruga;

		if (wyborPierwszy == wyborDrugi && silaPierwsza == silaDruga) wygrany = 0;
		else if (wyborPierwszy == wyborDrugi && silaPierwsza > silaDruga) wygrany = 1;
		else if (wyborPierwszy == wyborDrugi && silaPierwsza < silaDruga) wygrany = 2;
		else
		{
			if (wyborPierwszy == 'J' && wyborDrugi == 'P') wygrany = 1;
			else if (wyborPierwszy == 'P' && wyborDrugi == 'J') wygrany = 2;

			if (wyborPierwszy == 'J' && wyborDrugi == 'S') wygrany = 1;
			else if (wyborPierwszy == 'S' && wyborDrugi == 'J') wygrany = 2;

			if (wyborPierwszy == 'K' && wyborDrugi == 'J') wygrany = 1;
			else if (wyborPierwszy == 'J' && wyborDrugi == 'K') wygrany = 2;

			if (wyborPierwszy == 'K' && wyborDrugi == 'N') wygrany = 1;
			else if (wyborPierwszy == 'N' && wyborDrugi == 'K') wygrany = 2;

			if (wyborPierwszy == 'N' && wyborDrugi == 'J') wygrany = 1;
			else if (wyborPierwszy == 'J' && wyborDrugi == 'N') wygrany = 2;

			if (wyborPierwszy == 'N' && wyborDrugi == 'P') wygrany = 1;
			else if (wyborPierwszy == 'P' && wyborDrugi == 'N') wygrany = 2;

			if (wyborPierwszy == 'P' && wyborDrugi == 'K') wygrany = 1;
			else if (wyborPierwszy == 'K' && wyborDrugi == 'P') wygrany = 2;

			if (wyborPierwszy == 'P' && wyborDrugi == 'S') wygrany = 1;
			else if (wyborPierwszy == 'S' && wyborDrugi == 'P') wygrany = 2;

			if (wyborPierwszy == 'S' && wyborDrugi == 'K') wygrany = 1;
			else if (wyborPierwszy == 'K' && wyborDrugi == 'S') wygrany = 2;

			if (wyborPierwszy == 'S' && wyborDrugi == 'N') wygrany = 1;
			else if (wyborPierwszy == 'N' && wyborDrugi == 'S') wygrany = 2;
		}
		//system rozstrzygajacy


		if (idGraczaPierwszy == 'a')
		{
			aLiczbaGier++;

			if (wygrany == 0) aRemisy++;
			else if (wygrany == 1) aWygrane++;
			else if (wygrany == 2) aPrzegrane++;
		}
		else if (idGraczaPierwszy == 'b')
		{
			bLiczbaGier++;

			if (wygrany == 0) bRemisy++;
			else if (wygrany == 1) bWygrane++;
			else if (wygrany == 2) bPrzegrane++;
		}
		else if (idGraczaPierwszy == 'c')
		{
			cLiczbaGier++;

			if (wygrany == 0) cRemisy++;
			else if (wygrany == 1) cWygrane++;
			else if (wygrany == 2) cPrzegrane++;
		}
		else if (idGraczaPierwszy == 'd')
		{
			dLiczbaGier++;

			if (wygrany == 0) dRemisy++;
			else if (wygrany == 1) dWygrane++;
			else if (wygrany == 2) dPrzegrane++;
		}


		if (idGraczaDrugi == 'a')
		{
			aLiczbaGier++;

			if (wygrany == 0) aRemisy++;
			else if (wygrany == 2) aWygrane++;
			else if (wygrany == 1) aPrzegrane++;
		}
		else if (idGraczaDrugi == 'b')
		{
			bLiczbaGier++;

			if (wygrany == 0) bRemisy++;
			else if (wygrany == 2) bWygrane++;
			else if (wygrany == 1) bPrzegrane++;
		}
		else if (idGraczaDrugi == 'c')
		{
			cLiczbaGier++;

			if (wygrany == 0) cRemisy++;
			else if (wygrany == 2) cWygrane++;
			else if (wygrany == 1) cPrzegrane++;
		}
		else if (idGraczaDrugi == 'd')
		{
			dLiczbaGier++;

			if (wygrany == 0) dRemisy++;
			else if (wygrany == 2) dWygrane++;
			else if (wygrany == 1) dPrzegrane++;
		}
		//system przyznawania statystyk

		i--;
	}



	if (aWygrane == 0 && aRemisy == 0 && aPrzegrane == 0);
	else
	{
		cout << "gracz a" << endl;

		if (aWygrane > 0) cout << "   wygrane: " << (aWygrane / aLiczbaGier) * 100 << "%" << endl;
		if (aRemisy > 0) cout << "    remisy: " << (aRemisy / aLiczbaGier) * 100 << "%" << endl;
		if (aPrzegrane > 0) cout << "    przegrane: " << (aPrzegrane / aLiczbaGier) * 100 << "%" << endl;
		cout << endl;
	}

	if (bWygrane == 0 && bRemisy == 0 && bPrzegrane == 0);
	else
	{
		cout << "gracz b" << endl;

		if (bWygrane > 0) cout << "    wygrane: " << (bWygrane / bLiczbaGier) * 100 << "%" << endl;
		if (bRemisy > 0) cout << "    remisy: " << (bRemisy / bLiczbaGier) * 100 << "%" << endl;
		if (bPrzegrane > 0) cout << "    przegrane: " << (bPrzegrane / bLiczbaGier) * 100 << "%" << endl;
		cout << endl;
	}

	if (cWygrane == 0 && cRemisy == 0 && cPrzegrane == 0);
	else
	{
		cout << "gracz c" << endl;

		if (cWygrane > 0) cout << "    wygrane: " << (cWygrane / cLiczbaGier) * 100 << "%" << endl;
		if (cRemisy > 0) cout << "    remisy: " << (cRemisy / cLiczbaGier) * 100 << "%" << endl;
		if (cPrzegrane > 0) cout << "    przegrane: " << (cPrzegrane / cLiczbaGier) * 100 << "%" << endl;
		cout << endl;
	}

	if (dWygrane == 0 && dRemisy == 0 && dPrzegrane == 0);
	else
	{
		cout << "gracz d" << endl;

		if (dWygrane > 0) cout << "    wygrane: " << (dWygrane / dLiczbaGier) * 100 << "%" << endl;
		if (dRemisy > 0) cout << "    remisy: " << (dRemisy / dLiczbaGier) * 100 << "%" << endl;
		if (dPrzegrane > 0) cout << "    przegrane: " << (dPrzegrane / dLiczbaGier) * 100 << "%" << endl;
		cout << endl;
	}
	//wypisywanie wynikow z uwzglednieniem warunkow

	return 0;
}
