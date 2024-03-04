#pragma once
#include<iostream>
#include <vector>
//======================================================================
//Dynamic Programming
//======================================================================
class DP
{	//macierz s¹siedztwa
	int** matrix;
	//rozmiar macierzy
	int size;
	//œcie¿ka 
	std::vector<std::vector<int>> path;
	//minimalny cykl
	int min;
	//rozwi¹zywanie problemu
	int solve(int start, int mask, std::vector<std::vector<int>>& memory, std::vector<std::vector<int>>& path);
public:
	//metoda g³ówna przygotowanie i wywo³anie algorytmu
	void findShortestPath(int** matrix, int size);
	//wyœwietlenie rozwi¹zania
	void showResult();

	




	
	
	
};

