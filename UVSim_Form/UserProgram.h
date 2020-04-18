#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include<vector>

using namespace std;

class UserProgram
{
	const int SIZE_OF_MEMORY = 1000;
public:
	UserProgram() {};
	void cliProgramLoad(Simulator* sim);
	void fileProgramLoad(Simulator* sim);
	void loadProgram(Simulator* sim, vector<string> instructions);
};

