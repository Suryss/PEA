#pragma once
#include <iostream>
class Node
{
	//wierzcho�ek
	int vertice;
	//warto��
	int value;
	//poziom
	int level;
	//�cie�ka prowadz�ca do w�z�a
	int* path;
	//czy wierzo�ek o danym indeksie zosta� odwiedzony
	bool* visited;
	//macierz s�siedztwa
	int** matrix;
public:
	//konstruktory
	Node();
	Node(int vertice, int value, int level, int** matrixToInsert, int size, int* pathToInsert = NULL);
	//--------------------------------------------------------------------------------------------------
	
	//kopiowanie macierzy
	void createMatrix(int** matrixToInsert, int size);
	//zwracanie macierzy
	int** getMatrix();
	//tworzenie �cie�ki 
	void createPath(int* pathToInsert);
	//zwraca �cie�k�
	int* getPath();
	//zwraca wierzcho�ek
	int getVertice();
	//zwraca warto��
	int getValue();
	//dodaje do obecnej warto�ci
	void addValue(int value);
	//zwraca poziom
	int getLevel();
	//zwraca wska�nik na tablic� odwiedzonych
	bool* getVisited();
};

