#pragma once
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
class Algorithm
{
	std::vector<int> generatePath(std::vector<std::vector<int>> matrix, int size);
	std::vector<std::vector<int>> tournament( std::vector<std::vector<int>>& population, const std::vector<int>& fitnessValues, int populationSize);
	int calculateFitness(const std::vector<int>& route, const std::vector<std::vector<int>>& matrix, int size);
	int rouletteWheelSelection(std::vector<int>& fitnessValues);
	std::vector<int> orderCrossover(const std::vector<int>& parent1, const std::vector<int>& parent2, int size);
	std::vector<int> swapMutation(std::vector<int> route, int size);
	std::vector<int> partiallyMappedCrossover(const std::vector<int>& parent1, const std::vector<int>& parent2, int size);
public:
	std::vector<int> bestPath;
	int bestResult = INT32_MAX;
	long long times[1000]{ 0 };
	int costs[1000]{ 0 };
	void genetic(const std::vector<std::vector<int>> matrix, int size, int stop, int populationSize, double mutationRate, double crossRate, bool oX);
	
};

