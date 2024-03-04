#pragma once
#include <chrono>
//======================================================================
//Brute Force
//======================================================================
class BF
{
	//œcie¿ka do permutacji
	int* path;
	//najlepsza œcie¿ka
	int* sPath;
	//d³ugoœæ najlepszej œcie¿ki
	int length = 0;
	//rozmiar macierzy
	int size;
	//macierz s¹siedztwa
	int** matrix;

	//Funkcja wytwarzaj¹ca drogi/permutacje wierzcho³ków
	void permutations(int k);

	//Funkcja zamienia dwa wierzcho³ki
	void swap(int left, int right);

	//Funkcja wylicza d³ugoœæ drogi i sprawdza czy jest najkrótsza
	void countPath();
public:
	
	//Funkcja znajduj¹ca najkrótsz¹ drogê
	void findShortestPath(int** matrix, int size);

	//Funkcja wyœwietla wynik algorytmu
	void showResult();

};

