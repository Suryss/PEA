#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Data
{
	//Funkcja trzorzy macierz s�siedztwa
	void createMatrix();

public:
	//macierz s�siedztwa 
	int** matrix;
	//rozmiar macierzy s�siedztwa
	int size = 1;

	//Funkcja pobiera dane z pliku
	void importData(std::string filename);

	//Funkcja wy�wietla macierz s�siedztwa
	void showMatrix();

	//Funkcja generuje dane do macierzy s�siedztwa
	void generateData(int min, int max, int size);

	//Funkcja zapisuje dane do pliku
	void saveAsFile(std::string filename);
};

