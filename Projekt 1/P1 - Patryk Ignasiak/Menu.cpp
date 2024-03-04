#include "Menu.h"

using namespace std;

void Menu::mainMenu() {
	bool isMainMenu = true;
	int nr;
	Data data = Data();
	
	while (isMainMenu) {
		cout << endl << "Menu:" << endl;
		cout << "1. Dodaj plik z danymi" << endl;
		cout << "2. Generuj dane" << endl;
		cout << "3. Zapisz dane do pliku" << endl;
		cout << "4. Wyœwietl macierz s¹siedztwa" << endl;
		cout << "5. Algorytm - Brute Force" << endl;
		cout << "6. Algorytm - Branch and Bound - metoda Low Cost" << endl;
		cout << "7. Algorytm - Branch and Bound - metoda DFS" << endl;
		cout << "8. Algorytm - Dynamic programming" << endl;
		cout << "9. Testy" << endl;
		cout << "0. Zakoñcz" << endl;
		cout << endl << "Podaj numer: ";
		cin >> nr;

		switch (nr) {
			case 1: {				
				string filename;
				cout << "Podaj nazwê pliku: ";
				cin >> filename;
				data.importData(filename);
			}break;
			case 2: {
				int min, max, size;
				cout << "Podaj minimaln¹ wartoœæ: ";
				cin >> min;
				cout << "Podaj maksymaln¹ wartoœæ: ";
				cin >> max;
				cout << "Podaj rozmiar grafu: ";
				cin >> size;
				if (max <= 0) {
					cout << "podano wartoœæ drogi mniejsz¹ od 1!" << endl;
				}
				else if (size <= 1) {
					cout << "Podano zbyt ma³y rozmiar grafu!" << endl;
				}
				else {
					data.generateData(min, max, size);
				}
			}break;
			case 3: {
				if (data.size > 1) {
					string filename;
					cout << "Podaj nazwê pliku: ";
					cin >> filename;
					data.saveAsFile(filename);
				}
				else {
					cout << "Brak danych do zapisania!!!" << endl;
				}
			}break;
			case 4: data.showMatrix(); break;
			case 5: { 
				if (data.size > 1) {
					cout << "Szukanie rozwi¹zania..." << endl;
					BF bf = BF();
					
					auto start = chrono::steady_clock::now();
					bf.findShortestPath(data.matrix, data.size);
					auto end = chrono::steady_clock::now();

					auto duration = end - start;

					
				
					bf.showResult();
					cout << "Algorytm Bruce Force dla "<< data.size<<" wierzcho³ków zajmuje ";
					cout << chrono::duration_cast<chrono::microseconds>(duration).count() << " us, ";
					cout << chrono::duration_cast<chrono::seconds>(duration).count() <<" s" << endl << endl;
					
					
				}
				else {
					cout << "Brak danych do zbadania!!!" << endl;
				}
			}break;
			case 6: {
				if (data.size > 1) {
					cout << "Szukanie rozwi¹zania..." << endl;
					BB bb = BB();
					
					auto start = chrono::steady_clock::now();
					bb.findShortestPathLC(data.matrix, data.size);
					auto end = chrono::steady_clock::now();

					auto duration = end - start;
					
					bb.showResult();

					cout << "Algorytm Branch and Bound(Low Cost) dla " << data.size << " wierzcho³ków zajmuje ";
					cout << chrono::duration_cast<chrono::microseconds>(duration).count() << " us, ";
					cout << chrono::duration_cast<chrono::seconds>(duration).count() << " s" << endl << endl;
					

				}
				else {
					cout << "Brak danych do zbadania!!!" << endl;
				}
			}break;
			case 7: {
				if (data.size > 1) {
					cout << "Szukanie rozwi¹zania..." << endl;
					BB bb = BB();
					
					auto start = chrono::steady_clock::now();
					bb.findShortestPathDFS(data.matrix, data.size);
					auto end = chrono::steady_clock::now();

					auto duration = end - start;
					
 					bb.showResult();

					cout << "Algorytm Branch and Bound(DFS) dla " << data.size << " wierzcho³ków zajmuje ";
					cout << chrono::duration_cast<chrono::microseconds>(duration).count() << " us, ";
					cout << chrono::duration_cast<chrono::seconds>(duration).count() << " s" << endl << endl;
					

				}
				else {
					cout << "Brak danych do zbadania!!!" << endl;
				}
			}break;
			case 8: {
				
				if (data.size > 1) {
					cout << "Szukanie rozwi¹zania..." << endl;
					DP dp = DP();
					
					auto start = chrono::steady_clock::now();
					dp.findShortestPath(data.matrix, data.size);
					auto end = chrono::steady_clock::now();

					auto duration = end - start;
					
					dp.showResult();

					cout << "Algorytm Dynamic Programming dla " << data.size << " wierzcho³ków zajmuje ";
					cout << chrono::duration_cast<chrono::microseconds>(duration).count() << " us, ";
					cout << chrono::duration_cast<chrono::seconds>(duration).count() << " s" << endl << endl;
					
					

				}
				else {
					cout << "Brak danych do zbadania!!!" << endl;
				}
			}break;
			case 9: menuTest(); break;
			default: isMainMenu = false; break;
		}
	}
}
void Menu::menuTest() {
	int nr ;
	bool isTestMenu = true;
	Test test = Test();

	while (isTestMenu) {
		cout << endl << "Menu:" << endl;
		cout << "1. Test BF" << endl;
		cout << "2. Test BB (Low cost)" << endl;
		cout << "3. Test BB (DFS)" << endl;
		cout << "4. Test DP" << endl;

		cout << "0. Zakoñcz" << endl;
		cout << endl << "Podaj numer: ";
		cin >> nr;

		switch (nr) {
			case 1: test.testBF(); break;
			case 2: test.testBBL(); break;
			case 3: test.testBBD(); break;
			case 4: test.testDP(); break;
			default: isTestMenu = false;
		}


	}

}