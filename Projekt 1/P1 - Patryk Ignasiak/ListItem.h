#pragma once
#include "Node.h"
class ListItem
{
public:
	//Wierzcho³ek
	Node node;
	//Poprzedni element w liœcie
	ListItem* previous;
	//Nastêpny element w liœcie
	ListItem* next;

	//Tworzy element listy
	//Jako argumenty przyjmuje wêze³, koszt krawêdzi, wskaŸnik na poprzedni element i na nastêpny
	ListItem(Node node, ListItem* previous, ListItem* next);
};

