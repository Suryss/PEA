#pragma once
#include "Node.h"
class ListItem
{
public:
	//Wierzcho�ek
	Node node;
	//Poprzedni element w li�cie
	ListItem* previous;
	//Nast�pny element w li�cie
	ListItem* next;

	//Tworzy element listy
	//Jako argumenty przyjmuje w�ze�, koszt kraw�dzi, wska�nik na poprzedni element i na nast�pny
	ListItem(Node node, ListItem* previous, ListItem* next);
};

