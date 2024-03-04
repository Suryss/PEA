// P3 - Patryk Ignasiak.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <locale.h>
#include <iostream>
#include "Menu.h"
#include "Test.h"


int main()
{
    //Ustawienie polskich znaków w programie
    setlocale(LC_CTYPE, "Polish");
    //Test test = Test();
    //test.test2();
    Menu menu = Menu();
    menu.mainMenu();
}


