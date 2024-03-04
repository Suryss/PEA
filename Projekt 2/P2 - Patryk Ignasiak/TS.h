#pragma once
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
class TS
{
	int calculateCost(std::vector<std::vector<int>> matrix, int size, std::vector<int> path);
	std::vector<int> generatePath(std::vector<std::vector<int>> matrix, int size);

	std::vector<int> swapPositions(const std::vector<int>& tour, int city1, int city2);
	
public:
	std::vector<int> bestPath;
	int bestCost = 0;
	long long times[100]{ 0 };
	int costs[100]{ 0 };
	void TabuSearch(std::vector<std::vector<int>> matrix, int size, int stop, int choice);
	std::vector<std::vector<int>> getNeighborhoodSolutions(std::vector<int>& tour);
	std::vector<int> swapPositions3Cities(const std::vector<int>& tour, int city1, int city2, int city3);
	std::vector<std::vector<int>> getNeighborhoodSolutions3Cities(std::vector<int>& tour);
	std::vector<int> inversion(const std::vector<int>& tour, int city1, int city2);
	std::vector<std::vector<int>> getNeighborhoodSolutionsInversion(std::vector<int>& tour);
	void showResult(int size);
};

