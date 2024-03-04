#include "DP.h"
using namespace std;

void DP::findShortestPath(int** matrix, int size) {
	this->matrix = matrix;
	this->size = size;
	//tworzymy pamiêci
	vector<vector<int>> memory(size, vector<int>(1 << size, -1));
	vector<vector<int>> path(size, vector<int>(1 << size, -1));

	min = solve( 0, 1, memory, path);
	this->path = path;

}

void DP::showResult() {
	int start = 0;
	int mask = 1;
	vector<int> droga;
	vector<bool> visited(size, false);

	while (mask != (1 << size) - 1) {
		droga.push_back(start);
		visited[start] = true;

		int nextNode = path[start][mask];
		droga.push_back(nextNode);
		mask |= (1 << nextNode);
		start = nextNode;
	}

	droga.push_back(0);
	visited[0] = true;

	for (int i = 0; i < droga.size() - 1; ++i) {
		cout << droga[i] << " ";
		i++;
	}
	cout << droga[droga.size() - 2] << " \nD³ugoœæ: "<<min<<endl;
}

int DP::solve( int start, int mask, vector<vector<int>>& memory, vector<vector<int>>& path) {
	
	//zwracamy wartoœæ krawêdzi prowadz¹cej do wierzcho³ka startowego
	if (mask == (1 << size) - 1) { 
		path[start][mask] = 0;
		return matrix[start][0];
	}
	//zwracamy zapamiêtan¹ wartoœæ dla danego pod-problemu
	if (memory[start][mask] != -1) {
		return memory[start][mask];
	}

	int minimum = INT_MAX;
	int nextNode = -1;

	//rozpatrujemy kolejne przypadki
	for (int i = 0; i < size; i++) {
		if ((mask & (1 << i)) == 0) {
			int newMask = mask | (1 << i);
			int cost = matrix[start][i] + solve( i, newMask, memory, path);
			if (cost < minimum) {
				minimum = cost;
				nextNode = i;
			}
		}
	}
	//zapamietanie rozwiazania
	memory[start][mask] = minimum;

	//zapamiêtanie œcie¿ki
	path[start][mask] = nextNode;

	return minimum;
}
