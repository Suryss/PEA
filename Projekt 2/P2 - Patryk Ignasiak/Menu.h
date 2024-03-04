#pragma once
#include <iostream>
#include "Data.h"
#include <chrono>
#include <string>
using namespace std;
class Menu
{
	int stop = 60;
	double a = 0.99;
	string filename;
	int* path;
	string alg;
	int choice;
	std::vector<int> pathTS;
public:
	void mainMenu();
};

