#include "Data.h"
#include <random>
using namespace std;
void Data::importData(string filename) {
	//otwieramy plik
	ifstream file(filename);
	if (file.is_open()) {
		cout << "Trwa importowanie danych..." << endl;
		
		//zapisujemy dane do tablicy
		
		bool first = true;
		string sLine;
		int i = 0;
		while (!file.eof() && i < size) {
			
			if (first) {
				file >> size;
				createMatrix();
				first = false;
				continue;
			}
			else {
				
				getline(file, sLine);

				if (!sLine.empty()) {
					istringstream in_ss(sLine);

					for (int j = 0; j < size; j++)
					{
						
						in_ss >> matrix[i][j];
					}
					i++;
				}
			}

		}

		file.close();
		
		cout << "Dane zosta³y zaimportowane" << endl;

		
		
	}
	else {
		cout << "Nie znaleziono pliku: " << filename << endl;
	}
}
void Data::showMatrix() {
	cout << endl << "Macierz s¹siedztwa" << endl << endl;
	cout << "    ";
	for (int i = 0; i < size; i++) {
		printf("%3d ", i);
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		printf("%3d ", i);
		for (int j = 0; j < size; j++) {

			printf("%3d ", matrix[i][j]);

		}
		cout << endl;
	}
}
void Data::createMatrix() {
	matrix = new int* [size];
	for (int j = 0; j < size; j++) {
		matrix[j] = new int[size];
	}
}
void Data::generateData(int min, int max, int mSize) {
	if (mSize < 2) {
		cout << "Podano za ma³y rozmiar!!!" << endl;
		return;
	}
	size = mSize;
	createMatrix();

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distValue(min, max);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j) {
				matrix[i][j] = distValue(gen);
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
}
void Data::saveAsFile(string filename) {
	if (size == 1) {
		cout << "Brak danych do zapisania!!!" << endl;
		return;
	}

	//Tworzymy plik i zapisujemy rozmiar
	ofstream file(filename);
	
	file << size << endl;

	file.close();

	//otwieramy plik do nadpisania
	//i zapisujemy generowane dane
	file.open(filename, ios_base::app);

	for (int i = 0; i <= size; i++) {
		string line;
		for (int j = 0; j < size; j++) {
			file <<matrix[i][j];
			file <<" ";
		}

		file << endl;
	}
	file.close();
}