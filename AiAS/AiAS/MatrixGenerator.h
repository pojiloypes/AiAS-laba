#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class MatrixGenerator
{
public:
	 pair<int, pair<int**, int**>> genMatrixes();

	 pair<int**, int> readMatrixFromFile(string fileName);

	 int** genRandomly(int n);
};

