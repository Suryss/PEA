#include "SA.h"

using namespace std;
void SA::annealingIns(vector<vector<int>> matrix, int size, int stop, double a, double T) {
	time_t startTime;

	startTime = time(NULL);
	srand(time(NULL));
	//inicjalizacja  œcie¿ek
	bestPath = new int[size];
	int* path = generatePath(matrix, size);

	bestCost = calculateCost(matrix, size, path);
	int temp;
	int currentCost = bestCost;
	int newCost;
	auto start = chrono::steady_clock::now();
	costs[0] = bestCost;
	int z = 1;
	while (time(NULL) - startTime < stop) {
		// Generowanie s¹siedztwa
		int v1 = rand() % size;
		int v2 = rand() % size;
		while (v1 == v2) {
			v2 = rand() % size;
		}
		// Zamiana wierzcho³ków
		temp = path[v1];
		path[v1] = path[v2];
		path[v2] = temp;

		newCost = calculateCost(matrix, size, path);
		//Akceptacja rozwi¹zania
		if (newCost < currentCost || (rand() / static_cast<double>(RAND_MAX)) < min(exp(-(currentCost - newCost) / T))) {
			currentCost = newCost;

			if (currentCost < bestCost) {
				auto end = chrono::steady_clock::now();
				auto duration = end - start;
				
				times[z] = chrono::duration_cast<chrono::microseconds>(duration).count();
				costs[z] = currentCost;
				z++;
				for (int i = 0; i < size; i++) {
					bestPath[i] = path[i];
				}
				bestCost = currentCost;
			}
		}
		else {
			temp = path[v1];
			path[v1] = path[v2];
			path[v2] = temp;
		}
		//Sch³adzanie
		T *= a;
	}
	Tend = T;
}
void SA::annealingLog(vector<vector<int>> matrix, int size, int stop, double a, double T) {
	time_t startTime;

	startTime = time(NULL);
	
	srand(time(NULL));
	//inicjalizacja  œcie¿ek
	bestPath = new int[size];
	int* path = generatePath(matrix, size);

	int temp;
	int currentCost = bestCost;
	int newCost;
	double k = 1;
	auto start = chrono::steady_clock::now();
	costs[0] = bestCost;
	int z = 1;
	while (time(NULL) - startTime < stop) {
		// Generowanie s¹siedztwa
		int v1 = rand() % size;
		int v2 = rand() % size;
		while (v1 == v2) {
			v2 = rand() % size;
		}
		// Zamiana wierzcho³ków
		temp = path[v1];
		path[v1] = path[v2];
		path[v2] = temp;

		newCost = calculateCost(matrix, size, path);
		//Akceptacja rozwi¹zania
		if (newCost < currentCost || (rand() / static_cast<double>(RAND_MAX)) < min(exp(-(currentCost - newCost) / T))) {
			currentCost = newCost;

			if (currentCost < bestCost) {
				auto end = chrono::steady_clock::now();
				auto duration = end - start;

				times[z] = chrono::duration_cast<chrono::microseconds>(duration).count();
				costs[z] = currentCost;
				z++;
				for (int i = 0; i < size; i++) {
					bestPath[i] = path[i];
				}
				bestCost = currentCost;
			}
		}
		else {
			temp = path[v1];
			path[v1] = path[v2];
			path[v2] = temp;
		}

		//Sch³adzanie
		T = T/(a+b * log(k));
		k++;
		
	}
	Tend = T;
	
}

void SA::annealingLine(vector<vector<int>> matrix, int size, int stop, double a, double T) {
	time_t startTime;

	startTime = time(NULL);
	srand(time(NULL));
	//inicjalizacja  œcie¿ek
	
	bestPath = new int[size];
	int* path = generatePath(matrix, size);

	int temp;
	int currentCost = bestCost;
	int newCost;
	int k = 1;
	auto start = chrono::steady_clock::now();
	costs[0] = bestCost;
	int z = 1;
	while (time(NULL) - startTime < stop) {
		// Generowanie s¹siedztwa
		int v1 = rand() % size;
		int v2 = rand() % size;
		while (v1 == v2) {
			v2 = rand() % size;
		}
		// Zamiana wierzcho³ków
		temp = path[v1];
		path[v1] = path[v2];
		path[v2] = temp;

		newCost = calculateCost(matrix, size, path);
		//Akceptacja rozwi¹zania
		if (newCost < currentCost || (rand() / static_cast<double>(RAND_MAX)) < min(exp(-(currentCost - newCost) / T))) {
			currentCost = newCost;

			if (currentCost < bestCost) {
				auto end = chrono::steady_clock::now();
				auto duration = end - start;

				times[z] = chrono::duration_cast<chrono::microseconds>(duration).count();
				costs[z] = currentCost;
				z++;
				for (int i = 0; i < size; i++) {
					bestPath[i] = path[i];
				}
				bestCost = currentCost;
			}
		}
		else {
			temp = path[v1];
			path[v1] = path[v2];
			path[v2] = temp;
		}

		//Sch³adzanie
		T = T/(a + b * k);
		k++;

	}
	Tend = T;
}
int SA::calculateCost(vector<vector<int>> matrix, int size, int* path) {
	int sum = 0;
	for (int i = 0; i < size-1; i++) {
		sum += matrix[path[i]][path[i + 1]];
	}
	sum += matrix[path[size -1]][path[0]];
	return sum;
}
double SA::min(int number) {
	if (number > 1) return 1;
	else return number;
}
void SA::showResult(int size) {
	cout << bestCost << endl;
	for (int i = 0; i < size; i++) {
		cout << bestPath[i] << " | ";
	}
	cout << endl;
	cout << "Temperatura koñcowa: " << Tend << endl;
	cout << "exp(-1/Tk) : " << exp(-1 / Tend) << endl;
}
int* SA::generatePath(vector<vector<int>> matrix, int size) {
	int* path = new int[size];
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
	bestCost += matrix[path[size-1]][0];
	return path;
}