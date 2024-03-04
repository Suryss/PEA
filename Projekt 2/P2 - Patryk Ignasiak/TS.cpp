#include "TS.h"
using namespace std;
void TS::TabuSearch(vector<vector<int>> matrix, int size, int stop, int choice) {
	int diversification_threshold = 10; // maksymalna liczba do dywersyfikacji
	time_t startTime;

	
	srand(time(NULL));
	//inicjalizacja  œcie¿ek
	vector<int> path = generatePath(matrix, size);
	
	bestCost = calculateCost(matrix, size, path);
	int pathCost = bestCost;

	vector<vector<int>> tabu_list = { path };
	int diversification_count = 0;
	auto start = chrono::steady_clock::now();
	costs[0] = bestCost;
	int z = 1;
	vector<vector<int>> solution_neighborhood = getNeighborhoodSolutions(path);
	startTime = time(NULL);
	while (time(NULL) - startTime < stop) {
		if (choice == 2) {
			vector<vector<int>> solution_neighborhood = getNeighborhoodSolutions3Cities(path);
		}
		else if (choice == 3) {
			vector<vector<int>> solution_neighborhood = getNeighborhoodSolutionsInversion(path);
		}
		else {
			vector<vector<int>> solution_neighborhood = getNeighborhoodSolutions(path);
		}
		

		// Dywersyfikacja
		if (diversification_count >= diversification_threshold) {
			std::random_shuffle(solution_neighborhood.begin(), solution_neighborhood.end());
			path = solution_neighborhood[0];
			diversification_count = 0;
		}
		else {
			path = solution_neighborhood[0];
		}
		pathCost = calculateCost(matrix, size, path);
		for (vector<int> candidate : solution_neighborhood) {
			int candidateCost = calculateCost(matrix, size, candidate);
			if (candidateCost < pathCost &&
				std::find(tabu_list.begin(), tabu_list.end(), candidate) == tabu_list.end()) {
				path = candidate;
				pathCost = candidateCost;
			}
		}
		//zamiana z najlepszym
		if (pathCost < bestCost) {
			bestPath = path;
			bestCost = pathCost;
			auto end = chrono::steady_clock::now();
			auto duration = end - start;

			times[z] = chrono::duration_cast<chrono::microseconds>(duration).count();
			costs[z] = pathCost;
			z++;
		}

		tabu_list.push_back(path);
		if (tabu_list.size() > static_cast<size_t>(size)) {
			tabu_list.erase(tabu_list.begin());
		}

		//Zwiêkszamy licznik do dywersyfikacji
		if (pathCost > bestCost) {
			diversification_count++;
		}
		else {
			diversification_count = 0;
		}
	}
}
int TS::calculateCost(vector<vector<int>> matrix, int size, vector<int> path) {
	int sum = 0;
	for (int i = 0; i < size - 1; i++) {
		sum += matrix[path[i]][path[i + 1]];
	}
	sum += matrix[path[size - 1]][path[0]];
	return sum;
}
vector<int> TS::generatePath(vector<vector<int>> matrix, int size) {
	vector<int> path(size);
	vector<int> tmp(size);
	this->bestPath = tmp;
	bool* visited = new bool[size] {false}; // Tablica do œledzenia, czy miasto zosta³o odwiedzone
	// Losowy wybór startowego miasta
	int firstCity = rand() % size;
	path[0] = firstCity;
	bestPath[0] = firstCity;
	visited[firstCity] = true;

	// Wybór kolejnych miast
	for (int i = 1; i < size; ++i) {
		int lastCity = path[i - 1];
		int nextCity = -1;
		int bCost = INT32_MAX;

		// Wybór najbli¿szego miasta spoœród nieodwiedzonych
		for (int j = 0; j < size; ++j) {
			if (!visited[j] && matrix[lastCity][j] < bCost) {
				bCost = matrix[lastCity][j];
				nextCity = j;
			}
		}
		// Zaznaczenie miasta jako odwiedzonego
		visited[nextCity] = true;
		path[i] = nextCity;
		bestPath[i] = nextCity;
		bestCost += matrix[lastCity][nextCity];
	}
	bestCost += matrix[path[size - 1]][0];
	return path;
}
 std::vector<int> TS::swapPositions(const std::vector<int>& tour, int city1, int city2) {
	std::vector<int> tourCopy = tour;
	std::swap(tourCopy[city1], tourCopy[city2]);
	return tourCopy;
}

std::vector<std::vector<int>> TS::getNeighborhoodSolutions( std::vector<int>& tour) {
	std::vector<std::vector<int>> neighborhoodSolutions;

	for (size_t i = 1; i < tour.size() - 1; ++i) {
		for (size_t j = 1; j < tour.size() - 1; ++j) {
			if (i == j) {
				continue;
			}

			neighborhoodSolutions.push_back(swapPositions(tour, i, j));
		}
	}

	return neighborhoodSolutions;
}

std::vector<int> TS::swapPositions3Cities(const std::vector<int>& tour, int city1, int city2, int city3) {
	std::vector<int> tourCopy = tour;
	std::swap(tourCopy[city1], tourCopy[city2]);
	std::swap(tourCopy[city1], tourCopy[city3]);
	return tourCopy;
}
std::vector<std::vector<int>> TS::getNeighborhoodSolutions3Cities(std::vector<int>& tour) {
	std::vector<std::vector<int>> neighborhoodSolutions;

	for (size_t i = 1; i < tour.size() - 1; ++i) {
		for (size_t j = i+1; j < tour.size() - 1; ++j) {
			for (size_t k = j+1; k < tour.size() - 1; ++k) {
				if (i == j == k || i == j || i == k || j == k) {
					continue;
				}
				neighborhoodSolutions.push_back(swapPositions3Cities(tour, i, j, k));
			}
		}
	}

	return neighborhoodSolutions;
}
std::vector<int> TS::inversion(const std::vector<int>& tour, int city1, int city2) {
	std::vector<int> tourCopy = tour;
	std::reverse(tourCopy.begin() + city1, tourCopy.begin() + city2 + 1);
	return tourCopy;
}
std::vector<std::vector<int>> TS::getNeighborhoodSolutionsInversion(std::vector<int>& tour) {
	std::vector<std::vector<int>> neighborhoodSolutions;

	for (size_t i = 1; i < tour.size() - 1; ++i) {
		for (size_t j = i + 1; j < tour.size() - 1; ++j) {
			if (i == j) {
				continue;
			}

			neighborhoodSolutions.push_back(inversion(tour, i, j));
		}
	}

	return neighborhoodSolutions;
}
void TS::showResult(int size) {
	cout << bestCost << endl;
	for (int i = 0; i < size; i++) {
		cout << bestPath[i] << " | ";
	}
	cout << endl;
}