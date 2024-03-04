#include "Test.h"

using namespace std;
void Test::testBF() {
	long long* times = new long long[14];

	for (int i = 3; i < 14; i++) {
		cout << i << endl;
		times[i] = 0;
		for (int j = 0; j < 100; j++) {
			Data* data = new Data();
			BF* bf = new BF();
			data->generateData(j * i, (j + 1) * (i + 1), i);
			auto start = chrono::steady_clock::now();
			bf->findShortestPath(data->matrix, data->size);
			auto end = chrono::steady_clock::now();
			
			auto duration = end - start;
			times[i-3] += chrono::duration_cast<chrono::microseconds>(duration).count();
			
			delete data;
			delete bf;
		}
	}
	saveResult("Bf.txt", times);
}
void Test::saveResult(string filename, long long* times) {

	//Tworzymy plik
	ofstream file(filename);

	for (int i = 3; i < 14; i++) {
		
		
		file << i;
		file << ",";
		file << times[i-3];
		file << ",";
		

		file << endl;
	}
	file.close();
}
void Test::testBBL() {
	long long* times = new long long[11];
	
	int tab[11] = { 6, 10,12, 14,16, 18,20, 22, 24, 26};
	for (int i = 3; i < 13; i++) {
		cout << tab[i-3] << endl;
		times[i-3] = 0;
		
		for (int j = 0; j < 100; j++) {
			Data* data = new Data();
			BB* bb = new BB();
			data->generateData(j * i * tab[i-3], (j + 1) * (i + 1) * tab[i-3], tab[i-3]);
			
			auto start = chrono::steady_clock::now();
			bb->findShortestPathLC(data->matrix, data->size);
			auto end = chrono::steady_clock::now();
			
			auto duration = end - start;
			times[i-3] += chrono::duration_cast<chrono::microseconds>(duration).count();
			
			delete data;
			delete bb;
		}
	}
	//}
	saveResult("BBLC.txt", times);
}
void Test::testBBD() {
	long long* times = new long long[11];
	
	int tab[11] = { 6, 10,12, 14,16, 18,20, 22, 24, 26 };
	for (int i = 3; i < 13; i++) {
		cout << tab[i-3] << endl;
		times[i-3] = 0;
		
		for (int j = 0; j < 100; j++) {
			Data* data = new Data();
			BB* bb = new BB();
			data->generateData(j * i * tab[i-3], (j + 1) * (i + 1) * tab[i-3], tab[i-3]);
			auto start = chrono::steady_clock::now();
			bb->findShortestPathDFS(data->matrix, data->size);
			auto end = chrono::steady_clock::now();
			
			auto duration = end - start;
			times[i - 3] += chrono::duration_cast<chrono::microseconds>(duration).count();
			
			delete data;
			delete bb;

		}
	}
	saveResult("BBD.txt", times);
}
void Test::testDP() {
	long long* times = new long long[11];
	
	int tab[10] = { 6, 10,12, 14,16, 18,20, 22, 24 };
	for (int i = 3; i < 12; i++) {
		cout << tab[i - 3] << endl;
		times[i - 3] = 0;
		
		for (int j = 0; j < 100; j++) {
			Data* data = new Data();
			DP* dp = new DP();
			data->generateData(j * i * tab[i - 3], (j + 1) * (i + 1) * tab[i - 3], tab[i - 3]);
			auto start = chrono::steady_clock::now();
			dp->findShortestPath(data->matrix, data->size);
			auto end = chrono::steady_clock::now();
			
			auto duration = end - start;
			times[i - 3] += chrono::duration_cast<chrono::microseconds>(duration).count();
			
			delete data;
			delete dp;

		}
	}
	saveResult("DP.txt", times);
}