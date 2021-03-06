

#include "pch.h"
#include <ctime>
#include <windows.h>
long long int read_QPC() //funkcja do pomiaru czasu
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}
int main()
{
	dane d; //wywołanie klasy do pobierania danych
	Brute b; //wywołanmie klasy z algorytmem Brute Forca
	Problem p; //wywołanie klasy z algorytmem Branch and Bound
	string nazwa;
	
	
	
	int licz = 1;
	int opcja;

	cout << "1.Wczytanie danych z pliku\n";
	cout << "2.Wyswietlenie wczytanych danych\n";
	cout << "3.Uruchomienie  Brute Force  \n";
	cout << "4.Uruchomienie  Branch and Bound  \n";

	while (licz > 0)
	{
		cout << "Podaj czynosc jaka chcesz czynosc wykonac jesli chcesz wyjsc nacisnij 0 \n";
		cin >> opcja;
		if (opcja == 0)
		{
			exit(0);
		}
		if (opcja == 1)
		{
			cout << "Podaj nazwe pliku z rozszezeniem :";
			cin>>nazwa ;
			d.wczytaj(nazwa);
			b.wczytaj(nazwa);
			p.wczytaj(nazwa);
		}
		if (opcja == 2)
		{
			cout << "Wyswietlanie danych \n";
			d.wyswietl();
		}
		if (opcja == 3)
		{
			long long int frequency, start, elapsed;
			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = read_QPC();
			b.wynik();
			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
				frequency << endl;
			cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
				frequency << endl;
			cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
				frequency << endl << endl;
			

		}
		if (opcja == 4)
		{
			long long int frequency, start, elapsed;
			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = read_QPC();
			p.Branch();
			elapsed = read_QPC() - start;
			cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
				frequency << endl;
			cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
				frequency << endl;
			cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
				frequency << endl << endl;
		}
	}

}


