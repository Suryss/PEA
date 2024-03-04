#pragma once
#include "ListItem.h"
#include <cstddef>
#include "Node.h"

class List
{
	
	//Wska�nik na ogon
	ListItem* tail = NULL;
public:
	//Wska�nik na g�ow�
	ListItem* head = NULL;

	//Dodanie nowego elementu na koniec listy 
	//jako argument przyjmuje warto�� tego elementu
	void pushBack(Node node);

	//Usuni�cie elementu z pocz�tku listy
	Node popBack();

	//Sprawdzenie czy jest pusta
	bool noEmpty();

};