#include "Node.h"
using namespace std;
Node::Node() {}
Node::Node(int vertice, int value,  int level, int** matrixToInsert, int size, int* pathToInsert) {
	Node::vertice = vertice;
	Node::level = level;
	Node::value = value;
	//wype³nienie tablicy odwiedzonych
	visited = new bool[size];
	if (level == 1) {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}

	createMatrix(matrixToInsert, size);
	createPath(pathToInsert);

}


void Node::createMatrix(int** matrixToInsert, int size) {
	//przekopiowywanie macierzy
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		int* row = new int[size];
		for (int j = 0; j < size; j++) {
			if (i == j) {
				row[j] = INT32_MAX;
			}
			else {
				row[j] = matrixToInsert[i][j];
			}
		}
		matrix[i] = row;
	}

}
int** Node::getMatrix() {
	return matrix;
}
void Node::createPath(int* pathToInsert) {
	path = new int[level];
	for (int i = 0; i < level - 1; i++) {
		path[i] = pathToInsert[i];
		visited[path[i]] = true;
	}
	path[level - 1] = vertice;
	visited[vertice] = true;
}
int* Node::getPath() {
	return path;
}

int Node::getVertice() {
	return vertice;
}
int Node::getValue() {
	return value;
}
void Node::addValue(int value) {
	Node::value += value;
}
int Node::getLevel() {
	return level;
}
bool* Node::getVisited() {
	return visited;
}