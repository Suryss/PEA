#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Data.h"
#include "BF.h"
#include <chrono>
#include "BB.h"
#include "DP.h"
class Test
{
	void saveResult(std::string filename, long long* times);
public:
	//testy Brute Force
	void testBF();
	//testy BB metoda Low Cost
	void testBBL();
	//testy BB metoda DFS
	void testBBD();
	//testy Dynamic Programming
	void testDP();
};

