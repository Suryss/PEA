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
		cout << "3. Podaj wielkoœæ populacji" << endl;
		cout << "4. Podaj wspó³czynnik mutacji" << endl;
		cout << "5. Podaj wspó³czynnik krzy¿owania" << endl;
		cout << "6. Wybierz metodê krzy¿owania" << endl;
		cout << "7. Wybierz metodê mutacji" << endl;
		cout << "8. Uruchom algorytm" << endl;


		cout << "0. Zakoñcz" << endl;
		cout << endl << "Podaj numer: ";
		cin >> nr;

		switch (nr) {
		case 1: {
			cout << "Podaj nazwê pliku(.xml): ";
			cin >> filename;
			data.readFile(filename);
		}break;
		case 2: {
			cout << "Podaj po ilu sekundach algorytm ma zakoñczyæ dzia³anie: ";
			cin >> stop;
		}break;
		case 3: {
			cout << "Podaj rozmiar populacji: ";
			cin >> populationSize;
		}break;
		case 4: {
			cout << "Podaj wspó³czynnik mutacji: ";
			cin >> mutationRate;
		}break;
		case 5: {
			cout << "Podaj wspó³czynnik krzy¿owania: ";
			cin >> crossRate;
		}break;
		case 6: {
			int n;
			cout << "Wybierz metodê krzy¿owania: " << endl;
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