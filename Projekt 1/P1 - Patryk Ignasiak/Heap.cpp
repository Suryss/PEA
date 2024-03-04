#include "Heap.h"
#include <iostream>


using namespace std;
Heap::Heap(int size) {
	heapSize = size;
	heap = new Node[size];
}
void Heap::showHeapArray() {
	//Jeœli w kopcu s¹ dane to go wyœwietlamy
	if (heap != NULL) {
		cout << "\nKopiec:" << endl;
		cout << "Index:   |";

		for (int i = 0; i < busySpace; i++) {
			printf("%2d|", heap[i].getVertice());
		}

		cout << "\nWartoœæ: |";

		for (int i = 0; i < busySpace; i++) {
			printf("%2d|", heap[i].getValue());
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo¿na wyœwietliæ kopca - brak danych" << endl;
	}

}
void Heap::heapifyDown(int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int smallest = i;

	if (left < busySpace && right < busySpace) {
		if (heap[left].getValue() < heap[i].getValue() || heap[right].getValue() < heap[i].getValue()) {
			if (heap[left].getValue() < heap[right].getValue()) {
				smallest = left;
			}
			else {
				smallest = right;
			}
		}
	}
	else if (left < busySpace) {
		if (heap[left].getValue() < heap[i].getValue()) {
			smallest = left;
		}
	}
	if (smallest != i) {
		Node temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		heapifyDown(smallest);
	}
}
void Heap::heapifyUp(int i) {
	int parent = floor((i - 1) / 2);
	int largest = i;

	if (heap[parent].getValue() > heap[i].getValue()) {
		largest = parent;
	}

	if (largest != i) {
		Node temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		heapifyUp(largest);
	}
}
Node Heap::pop() {
	//Jeœli w kopcu s¹ elementy to usuwamy element ze szczytu
	if (busySpace > 1) {
		Node node = heap[0];
		busySpace--;
		//zamieniamy element ze szczytu z elementem ostatnim 
		heap[0] = heap[busySpace];

		//znajdujemy odpowiednie miejsce dla nowego elementu na szczycie
		heapifyDown(0);
		return node;
	}
	else {
		Node node = heap[0];
		busySpace--;
		return node;
	}

}
void Heap::push(Node node) {
	busySpace++;
	if (busySpace == heapSize) {
		heapSize *= 2;
		//relokujemy tablicê 
		Node* temp = heap;
		heap = new Node[heapSize];

		if (heapSize > 1) {
			for (int i = 0; i < busySpace-1; i++) {
				heap[i] = temp[i];
			}
			delete[] temp;
		}
	}

	//Wstawiamy nasz nowy element
	heap[busySpace - 1] = node;

	//jeœli rozmiar jest wiêkszy ni¿ 1, do szukamy miejsca dla naszego elementu
	if (busySpace > 1) {
		heapifyUp(busySpace - 1);
	}

}

void Heap::floyd() {
	//budujemy kopiec od ostatniego rodzica
	for (int i = floor((busySpace - 1) / 2); i >= 0; i--) {
		heapifyDown(i);
	}
}
bool Heap::noEmpty() {
	if (busySpace > 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Heap::find(int vertice) {
	for (int i = 0; i < busySpace; i++) {
		if (heap[i].getVertice() == vertice) {
			return true;
		}
	}
	return false;
}

