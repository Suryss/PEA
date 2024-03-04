#include "BF.h"
#include <iostream>
using namespace std;
void BF::findShortestPath(int** matrix, int size) {
	BF::matrix = matrix;
	BF::size = size;
	path = new int[size];
	sPath = new int[size];
	//wype³niamy pierwsz¹ œcie¿kê
	for (int i = 0; i < size; i++) {
		path[i] = i;
	}
	//obliczamy pierwsz¹ œcie¿kê
	countPath();
	//generowanie kolejnych permutacji
	permutations(size - 1);

}
void BF::permutations(int k) {
	if (k == 0) {
		countPath();
	}
	else {
		for (int i = 0; i <= k; i++) {
			
			swap(i, k);
			permutations(k - 1);
			swap(i, k);
		}
	}

}
void BF::swap(int left, int right) {
	int buf = path[left];
	path[left] = path[right];
	path[right] = buf;

}
void BF::countPath() {
	int sum = matrix[path[size - 1]][path[0]];
	for (int i = 1; i < size; i++) {
		sum += matrix[path[i - 1]][path[i]];
	}
	if (length == 0 || length > sum) {
		length = sum;
		
		for (int i = 0; i < size; i++) {
			sPath[i] = path[i];
		}
	}
}
void BF::showResult() {
	cout << "\nDroga:" << endl;
	for (int i = 0; i < size; i++) {
		cout << sPath[i] << ", ";
	}
	cout << endl << "D³ugoœæ: " << length <<endl;

}