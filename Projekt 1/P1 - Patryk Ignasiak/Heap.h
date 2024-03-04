#pragma once
#include <string>
#include "Node.h"
class Heap
{
	//WskaŸnik na pocz¹tek tablicy przechowuj¹cej dane kopca
	Node* heap = NULL;
	//Rozmiar kopca
	int heapSize = 0;
	int busySpace = 0;

	//kopcowanie w dó³
	void heapifyDown(int i);

	//kopcowanie w górê
	void heapifyUp(int i);
public:
	Heap(int size);
	//wyœwietlenie kopca jako tablicy
	void showHeapArray();

	//usuwanie
	Node pop();

	//dodawanie
	void push(Node node);

	//Algorytm Floyda do budowy kopca
	void floyd();

	//Sprawdzenie czy nie jest pusty
	bool noEmpty();

	//Wyszukiwanie
	bool find(int vertice);

};

