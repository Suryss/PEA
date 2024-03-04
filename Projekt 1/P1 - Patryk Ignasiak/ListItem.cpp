#include "ListItem.h"

ListItem::ListItem(Node node, ListItem* previous, ListItem* next) {
	//Przypisanie wartoœci do pól obiektu
	this->node = node;
	this->previous = previous;
	this->next = next;
}
