#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Data
{
	//Funkcja trzorzy macierz s¹siedztwa
	void createMatrix();

public:
	//macierz s¹siedztwa 
	int** matrix;
	//rozmiar macierzy s¹siedztwa
	int size = 1;

	//Funkcja pobiera dane z pliku
	void importData(std::string filename);

	//Funkcja wyœwietla macierz s¹siedztwa
	void showMatrix();

	//Funkcja generuje dane do macierzy s¹siedztwa
	void generateData(int min, int max, int size);

	//Funkcja zapisuje dane do pliku
	void saveAsFile(std::string filename);
};

