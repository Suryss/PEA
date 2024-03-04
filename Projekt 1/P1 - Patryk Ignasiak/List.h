#pragma once
#include "ListItem.h"
#include <cstddef>
#include "Node.h"

class List
{
	
	//WskaŸnik na ogon
	ListItem* tail = NULL;
public:
	//WskaŸnik na g³owê
	ListItem* head = NULL;

	//Dodanie nowego elementu na koniec listy 
	//jako argument przyjmuje wartoœæ tego elementu
	void pushBack(Node node);

	//Usuniêcie elementu z pocz¹tku listy
	Node popBack();

	//Sprawdzenie czy jest pusta
	bool noEmpty();

};