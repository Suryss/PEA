#pragma once
#include<iostream>
#include <vector>
//======================================================================
//Dynamic Programming
//======================================================================
class DP
{	//macierz s�siedztwa
	int** matrix;
	//rozmiar macierzy
	int size;
	//�cie�ka 
	std::vector<std::vector<int>> path;
	//minimalny cykl
	int min;
	//rozwi�zywanie problemu
	int solve(int start, int mask, std::vector<std::vector<int>>& memory, std::vector<std::vector<int>>& path);
public:
	//metoda g��wna przygotowanie i wywo�anie algorytmu
	void findShortestPath(int** matrix, int size);
	//wy�wietlenie rozwi�zania
	void showResult();

	




	
	
	
};

