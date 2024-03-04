#include "List.h"


void List::pushBack(Node node) {
	//tworzymy nowy element i wstawiamy w odpowiednim miejscu
	ListItem* item = new ListItem(node, tail, NULL);

	if (tail == NULL) {
		head = item;
		tail = item;
	}
	else {
		tail->next = item;
		tail = item;
	}
}

Node List::popBack() {
	//sprawdzamy czy s¹ elementy w tablicy jeœli tak to usuwamy pierwszy element
	if (head != NULL) {
		//Zmienna pomocnicza do przechowania wskaŸnika na element do usuniêcia
		ListItem* temp = tail;
		Node node = tail->node;

		//Ustawienie nowej g³owy
		tail = tail->previous;
		if (tail != NULL) {
			tail->next = NULL;
		}
		else {
			head = NULL;
		}

		delete temp;

		return node;
	}

}

bool List::noEmpty() {
	if (head == NULL) {
		return false;
	}
	
	return true;

}