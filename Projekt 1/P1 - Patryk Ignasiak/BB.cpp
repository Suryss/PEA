#include "BB.h"

using namespace std;
void BB::findShortestPathLC(int** matrix, int size) {
	BB::matrix = matrix;
	BB::size = size;
	int upperBound = INT32_MAX;
	//tworzymy wêze³ startowy
	Node node = Node(0, 0, 1, matrix, size);

	reduceRow(node);
	reduceColumn(node);

	//tworzymy kopiec
	Heap heap = Heap(size * 3);
	heap.push(node);

	//pobieramy kolejne wierzcho³ki z kopca
	while (heap.noEmpty()) {
		node = heap.pop();
		bool fulfilled = false;
		//sprawdzamy granice
		if (upperBound < INT32_MAX) {
			if (getLowerBound(node) < upperBound) {
				fulfilled = true;
			}
		}
		else {
			fulfilled = true;
		}
		if (fulfilled) {
			//tworzymy kolejne wêz³y dla dzieci rozpatrywanego wêz³a
			for (int i = 0; i < size; i++) {
				if (node.getVertice() != i && node.getMatrix()[node.getVertice()][i] < INT32_MAX) {
					Node childNode = Node(i, node.getValue(), node.getLevel() + 1, node.getMatrix(), size, node.getPath());
					
					makeInf(node.getVertice(), i, childNode);
					reduceRow(childNode);
					reduceColumn(childNode);

					heap.push(childNode);

					//porównujemy nowe rozwi¹zanie z aktualnym
					if (childNode.getLevel() == size) {
						upperBound = childNode.getValue();
						best = childNode;
					}
				}
			}
		}
	}

}

void BB::makeInf(int from, int to, Node& node) {
	int** nMatrix = node.getMatrix();
	node.addValue(nMatrix[from][to]);
	for (int i = 0; i < size; i++) {
		nMatrix[i][to] = INT32_MAX;
		nMatrix[from][i] = INT32_MAX;
	}
	nMatrix[to][from] = INT32_MAX;
}
void BB::reduceRow(Node& node) {
	int** nMatrix = node.getMatrix();
	int sum = 0;
	for (int i = 0; i < size; i++) {
		int min = INT32_MAX;
		for (int j = 0; j < size; j++) {
			if (nMatrix[i][j] < INT32_MAX) {
				if (min > nMatrix[i][j]) {
					min = nMatrix[i][j];
				}
			}
		}
		if (min < INT32_MAX && min > 0) {
			for (int j = 0; j < size; j++) {
				if (nMatrix[i][j] < INT32_MAX) {
					nMatrix[i][j] -= min;
				}
			}
		}
		if (min < INT32_MAX) {
			sum += min;
		}
		
	}
	node.addValue(sum);
}
void BB::reduceColumn(Node& node) {
	int** nMatrix = node.getMatrix();
	int sum = 0;
	for (int j = 0; j < size; j++) {
		int min = INT32_MAX;
		for (int i = 0; i < size; i++) {
			if (nMatrix[i][j] < INT32_MAX) {
				if (min > nMatrix[i][j]) {
					min = nMatrix[i][j];
				}
			}
		}
		if (min < INT32_MAX && min > 0) {
			for (int i = 0; i < size; i++) {
				if (nMatrix[i][j] < INT32_MAX) {
					nMatrix[i][j] -= min;
				}
			}
		}
		if (min < INT32_MAX) {
			sum += min;
		}
	}
	node.addValue(sum);
}
void BB::showResult() {
	cout << "\nDroga:" << endl;
	for (int i = 0; i < size; i++) {
		cout << best.getPath()[i] << ", ";
	}
	cout << endl << "D³ugoœæ: " << best.getValue() << endl;
}
void BB::findShortestPathDFS(int** matrix, int size) {
	this->matrix = matrix;
	this->size = size;
	int upperBound = INT32_MAX;
	//tworzymy wêze³ startowy
	Node node = Node(0, 0, 1, matrix, size);
	reduceRow(node);
	reduceColumn(node);

	//tworzymy listê
	List list = List();
	list.pushBack(node);
	//pobieramy kolejne elementy z listy
	while (list.noEmpty()) {
		
		node = list.popBack();
		bool fulfilled = false;
		//sprawdzamy granice
		if (upperBound < INT32_MAX) {
			if (getLowerBound(node) < upperBound) {
				fulfilled = true;
			}
		}
		else {
			fulfilled = true;
		}
		if (fulfilled) {
			//tworzymy wêz³y dla dzieci wierzcho³ka rozpatrywanego
			for (int i = 0; i < size; i++) {
				if (node.getVertice() != i && node.getMatrix()[node.getVertice()][i] < INT32_MAX) {
					Node childNode = Node(i, node.getValue(), node.getLevel() + 1, node.getMatrix(), size, node.getPath());

					makeInf(node.getVertice(), i, childNode);
					reduceRow(childNode);
					reduceColumn(childNode);

					list.pushBack(childNode);
					//porównywujemy z aktualnie najlepszym
					if (childNode.getLevel() == size) {
						upperBound = childNode.getValue();
						best = childNode;
						
					}
				}
			}
		}
	}
}
int BB::getLowerBound(Node node) {
	int** nMatrix = node.getMatrix();
	int sum = node.getValue();
	for (int i = 0; i < size; i++) {
		if (!node.getVisited()[i]) {
			int min1 = INT32_MAX, min2 = INT32_MAX;
			for (int j = 0; j < size; j++) {
				if (!node.getVisited()[i] && i != j) {
					
					if (min1 > matrix[i][j]) {
						min1 = matrix[i][j];
					}
					if (min2 > matrix[j][i]) {
						min2 = matrix[j][i];
					}
					
				}
			}
			sum += (min1 + min2) / 2;
		}
	}
	return sum;
}