#pragma once
#include <iostream>
#include "Data.h"
#include <chrono>
#include <string>
using namespace std;
class Menu
{
	int stop = 60;
	int populationSize = 10;
	double mutationRate = 0.01;
	double crossRate = 0.8;
	string filename;
	int* path;
	string alg;
	int choice;
	std::vector<int> pathTS;
	bool oX = true;
public:
	void mainMenu();
};

