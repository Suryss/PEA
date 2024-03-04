#pragma once
#include <chrono>
//======================================================================
//Brute Force
//======================================================================
class BF
{
	//�cie�ka do permutacji
	int* path;
	//najlepsza �cie�ka
	int* sPath;
	//d�ugo�� najlepszej �cie�ki
	int length = 0;
	//rozmiar macierzy
	int size;
	//macierz s�siedztwa
	int** matrix;

	//Funkcja wytwarzaj�ca drogi/permutacje wierzcho�k�w
	void permutations(int k);

	//Funkcja zamienia dwa wierzcho�ki
	void swap(int left, int right);

	//Funkcja wylicza d�ugo�� drogi i sprawdza czy jest najkr�tsza
	void countPath();
public:
	
	//Funkcja znajduj�ca najkr�tsz� drog�
	void findShortestPath(int** matrix, int size);

	//Funkcja wy�wietla wynik algorytmu
	void showResult();

};

