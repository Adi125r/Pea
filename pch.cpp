// pch.cpp: plik źródłowy odpowiadający wstępnie skompilowanemu nagłówkowi, niezbędny do powodzenia kompilacji

#include "pch.h"


using namespace std;
void dane ::  wczytaj(string nazwa)         //wczytuje dane z pliku
	{

		fstream plik;
		plik.open(nazwa, ios::in);
		if (plik.good() == false) {

			cout << "Nie udalo sie otworzyc pliku";
			exit(0);
		}
		if (plik.good() == true)
		{
			plik >> liczba;
			tab1 = new int *[liczba];
			for (int i = 0; i < liczba; i++)
			{
				tab1[i] = new int[liczba];
			}

			for (int i = 0; i < liczba; i++)
			{
				for (int j = 0; j < liczba; j++)
				{
					plik >> tab1[i][j];
				}

			}

		}plik.close();
	}
	void dane:: wyswietl() {
		for (int i = 0; i < liczba; i++)
		{
			for (int j = 0; j < liczba; j++)
				cout << tab1[i][j] << " ";
			cout << "\n";
		}
	}
