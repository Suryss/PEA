#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
class SA
{
	double Tend;
	double b = 0.05;
	int calculateCost(std::vector<std::vector<int>> matrix, int size, int* path);
	int* generatePath(std::vector<std::vector<int>> matrix, int size);
	double min(int y);
	
public:
	int* bestPath;
	int bestCost = 0;
	long long times[100]{0};
	int costs[100]{0};
	void annealingIns(std::vector<std::vector<int>> matrix, int size, int stop, double a, double T);
	void annealingLine(std::vector<std::vector<int>> matrix, int size, int stop, double a, double T);
	void annealingLog(std::vector<std::vector<int>> matrix, int size, int stop, double a, double T);
	void showResult(int size);
	
};

