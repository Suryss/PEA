#include "ListItem.h"

ListItem::ListItem(Node node, ListItem* previous, ListItem* next) {
	//Przypisanie warto�ci do p�l obiektu
	this->node = node;
	this->previous = previous;
	this->next = next;
}
