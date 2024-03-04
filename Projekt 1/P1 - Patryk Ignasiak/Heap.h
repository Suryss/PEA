#pragma once
#include <string>
#include "Node.h"
class Heap
{
	//Wska�nik na pocz�tek tablicy przechowuj�cej dane kopca
	Node* heap = NULL;
	//Rozmiar kopca
	int heapSize = 0;
	int busySpace = 0;

	//kopcowanie w d�
	void heapifyDown(int i);

	//kopcowanie w g�r�
	void heapifyUp(int i);
public:
	Heap(int size);
	//wy�wietlenie kopca jako tablicy
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

