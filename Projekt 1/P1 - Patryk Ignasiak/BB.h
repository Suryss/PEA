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
	//macierz s�siedztwa
	int** matrix;
	//zawiera informacje o najlepszym rozwi�zaniu
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
	//znajdowanie najkr�tszego cyklu Hamiltona - przeszukiwanie Low Cost
	void findShortestPathLC(int** matrix, int size);
	//wy�wietlenie rozwi�zania
	void showResult();
	//znajdowanie najkr�tszego cyklu Hamiltona - przeszukiwanie Low Cost
	void findShortestPathDFS(int** matrix, int size);

};

