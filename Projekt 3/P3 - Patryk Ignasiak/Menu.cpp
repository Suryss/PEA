#include "Menu.h"
#include "Algorithm.h"




void Menu::mainMenu() {
	bool isMainMenu = true; 
	int nr;
	Data data = Data();

	while (isMainMenu) {
		cout << endl << "Menu:" << endl;
		cout << "1. Dodaj plik z danymi" << endl;
		cout << "2. Podaj kryterium stopu" << endl;
		cout << "3. Podaj wielko�� populacji" << endl;
		cout << "4. Podaj wsp�czynnik mutacji" << endl;
		cout << "5. Podaj wsp�czynnik krzy�owania" << endl;
		cout << "6. Wybierz metod� krzy�owania" << endl;
		cout << "7. Wybierz metod� mutacji" << endl;
		cout << "8. Uruchom algorytm" << endl;


		cout << "0. Zako�cz" << endl;
		cout << endl << "Podaj numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			cout << "Podaj nazw� pliku(.xml): ";
			cin >> filename;
			data.readFile(filename);
		}break;
		case 2: {
			cout << "Podaj po ilu sekundach algorytm ma zako�czy� dzia�anie: ";
			cin >> stop;
		}break;
		case 3: {
			cout << "Podaj rozmiar populacji: ";
			cin >> populationSize;
		}break;
		case 4: {
			cout << "Podaj wsp�czynnik mutacji: ";
			cin >> mutationRate;
		}break;
		case 5: {
			cout << "Podaj wsp�czynnik krzy�owania: ";
			cin >> crossRate;
		}break;
		case 6: {
			int n;
			cout << "Wybierz metod� krzy�owania: " << endl;
			cout << "1. Order Crossover: " << endl;
			cout << "2. Partially Mapped Crossover" << endl;
			cout << "Wybierz: ";
			cin >> n;
			if (n == 2)oX = false;
			else oX = true;
		}break;
		case 7: {
			cout << "Podaj rozmiar populacji: ";
			cin >> populationSize;
			
		}break;
		case 8: {
			if (data.size > 1) {
				Algorithm a = Algorithm();
				a.genetic(data.matrix, data.size, stop, populationSize, mutationRate, crossRate, oX);
				cout <<"Najlepszy wynik: "<< a.bestResult << endl;
				cout << "Droga:" << endl;
				for (int i = 0; i < data.size; i++) {
					cout << a.bestPath[i] << ", ";
				}
			}
			else {
				cout << "Nie wybrano pliku z danymi!!!" << endl;
			}
		}break;
		default: isMainMenu = false; break;
		}
	}
}