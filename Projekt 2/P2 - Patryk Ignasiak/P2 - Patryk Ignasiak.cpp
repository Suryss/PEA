// P1 - Patryk Ignasiak.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//=========================================
//Autor: Patryk Ignasiak - 263889
//=========================================

#include <locale.h>
#include <iostream>
#include "Menu.h"
#include "Test.h"

int main()
{
    //Ustawienie polskich znaków w programie
    setlocale(LC_CTYPE, "Polish");
    Menu menu = Menu();
    menu.mainMenu();
    //Test test = Test();
    //test.testTS();
    //test.testSW();

}

