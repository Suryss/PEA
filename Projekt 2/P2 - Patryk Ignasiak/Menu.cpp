#include "Menu.h"
#include "SA.h"
#include "TS.h"



void Menu::mainMenu() {
	bool isMainMenu = true; 
	int nr;
	Data data = Data();

	while (isMainMenu) {
		cout << endl << "Menu:" << endl;
		cout << "1. Dodaj plik z danymi" << endl;
		cout << "2. Podaj kryterium stopu" << endl;
		cout << "3. Wybierz definicjê s¹siedztwa" << endl;
		cout << "4. Uruchom TabuSearch" << endl;
		cout << "5. Ustaw wspó³czynnik zmiany temperatury SW" << endl;
		cout << "6. Uruchom Symulowane wy¿arzanie" << endl;
		cout << "7. Zapisz œcie¿kê" << endl;
		cout << "8. Wczytaj œcie¿kê i oblicz drogê" << endl;


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
			cout << "1. Zamiana dwóch miast" << endl;
			cout << "2. Zamiana trzech miast" << endl;
			cout << "3. Odwrócenie fragmentu trasy" << endl;
			cout << "Wybierz definicjê s¹siedztwa: ";
			cin >> choice;
		}break;
		case 4: {
			if (data.size > 1) {
				TS ts = TS();
				ts.TabuSearch(data.matrix, data.size, stop, choice);
				ts.showResult(data.size);
				pathTS = ts.bestPath;
				alg = "TS_";
			}
			else {
				cout << "Nie wybrano pliku z danymi!!!" << endl;
			}
			
		}break;
		case 5: {
			cout << "Podaj wspó³czynnik zmiany temperatury: ";
			cin >> a;
		}break;
		case 6: {
			
			if (data.size > 1) {
				SA sa = SA();
				double T;
				cout << "Podaj temperaturê pocz¹tkow¹: ";
				cin >> T;
				cout << "Schematy ch³odzenia:" << endl;
				cout << "1. Z instrukcji" << endl;
				cout << "2. Liniowy (Cauchy'ego)" << endl;
				cout << "3. Logarytmiczny (Boltzmanna)" << endl;
				cout << "Wybierz schemat sch³adzania: ";
				cin >> nr;
				switch (nr) {
				case 2: sa.annealingLine(data.matrix, data.size, stop, a, T);  break;
				case 3: sa.annealingLog(data.matrix, data.size, stop, a, T);  break;
				default: {sa.annealingIns(data.matrix, data.size, stop, a, T); }
				}
				sa.showResult(data.size);
				path = sa.bestPath;
				alg = "SA_";
			}
			else {
				cout << "Nie wybrano pliku z danymi!!!" << endl;
			}
		}break;
		case 7: {
			
			if (data.size > 1) {
				if (alg == "SA_") {
					data.savePath(path, alg, filename);
				}
				else {
					data.savePathTS(pathTS, alg, filename);
				}
			}
			else {
				cout << "Nie wybrano pliku z danymi!!!" << endl;
			}
			
		}break;
		case 8: {
			if (data.size > 1) {
				string fn;
				cout << "Podaj nazwê pliku ze œcie¿k¹: ";
				cin >> fn;
				data.loadPath(fn);
			}
			else {
				cout << "Nie wybrano pliku z danymi!!!" << endl;
			}
		}break;
		default: isMainMenu = false; break;
		}
	}
}