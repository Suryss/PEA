#pragma once
#include "heap.h"
#include <iostream>
#include "Node.h"
#include <chrono>
#include "List.h"
//======================================================================
//Branch & Bound
//======================================================================
class BB
{
	//rozmiar macierzy
	int size;
	//macierz s¹siedztwa
	int** matrix;
	//zawiera informacje o najlepszym rozwi¹zaniu
	Node best;

	//wstawianie Infinity do macierzy w odpowiednie miejsca
	void makeInf(int from, int to, Node& node);
	//redukcja wierszy
	void reduceRow(Node& node);
	//redukcja kolumn
	void reduceColumn(Node& node);
	//wyliczanie dolnej granicy
	int getLowerBound(Node node);

public:
	//znajdowanie najkrótszego cyklu Hamiltona - przeszukiwanie Low Cost
	void findShortestPathLC(int** matrix, int size);
	//wyœwietlenie rozwi¹zania
	void showResult();
	//znajdowanie najkrótszego cyklu Hamiltona - przeszukiwanie Low Cost
	void findShortestPathDFS(int** matrix, int size);

};

