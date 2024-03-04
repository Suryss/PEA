#pragma once
#include <iostream>
class Node
{
	//wierzcho³ek
	int vertice;
	//wartoœæ
	int value;
	//poziom
	int level;
	//œcie¿ka prowadz¹ca do wêz³a
	int* path;
	//czy wierzo³ek o danym indeksie zosta³ odwiedzony
	bool* visited;
	//macierz s¹siedztwa
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
	//tworzenie œcie¿ki 
	void createPath(int* pathToInsert);
	//zwraca œcie¿kê
	int* getPath();
	//zwraca wierzcho³ek
	int getVertice();
	//zwraca wartoœæ
	int getValue();
	//dodaje do obecnej wartoœci
	void addValue(int value);
	//zwraca poziom
	int getLevel();
	//zwraca wskaŸnik na tablicê odwiedzonych
	bool* getVisited();
};

