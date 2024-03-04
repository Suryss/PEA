#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
class Data
{
	int number = 0;
public:
	std::vector<std::vector<int>> matrix;
	int size = 1;
	void readFile(std::string filename);
	void showMatrix();
	void savePath(int* path, std::string alg, std::string filename);
	void savePathTS(std::vector<int> path, std::string alg, std::string filename);
	void loadPath(std::string filename);
	void saveTestResult(long long times[100], int costs[100], double a, int type);
};

