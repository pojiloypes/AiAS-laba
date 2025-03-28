#include "MatrixGenerator.h"


pair<int, pair<int**, int**>> MatrixGenerator::genMatrixes()
{
	cout << "—гененрировать случайную матрицу или прочесть из файлов? (Y\\N): ";
	string ans; cin >> ans;

	if (ans == "Y" || ans == "y")
	{
		cout << "\n¬вдите число вершин: ";
		int n; cin >> n;
		int** mat1 = genRandomly(n);
		int** mat2 = genRandomly(n);

		return { n, {mat1, mat2} };
	}
	else
	{
		string fileName1 = "handle1.txt", fileName2 = "handle2.txt";
		pair<int**, int> p1 = readMatrixFromFile(fileName1);
		pair<int**, int> p2 = readMatrixFromFile(fileName2);

		return { p1.second, {p1.first, p2.first} };
	}
}

pair<int**, int> MatrixGenerator::readMatrixFromFile(string fileName)
{
	ifstream fin = ifstream(fileName);
	int n; fin >> n;

	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[n];
		for (int j = 0; j < n; j++)
			fin >> mat[i][j];
	}

	return { mat, n };
}

int** MatrixGenerator::genRandomly(int n)
{
	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		mat[i][i] = 0;

		for (int j = i+1; j < n; j++)
		{
			mat[i][j] = rand() % 2 == 0 ? 0 : 1;
			mat[j][i] = mat[i][j];
		}
	}

	return mat;
}

int** MatrixGenerator::genFullMatrix(int n)
{
	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		mat[i][i] = 0;

		for (int j = i + 1; j < n; j++)
		{
			mat[i][j] = 1;
			mat[j][i] = 1;
		}
	}

	return mat;
}

int** MatrixGenerator::genChainMatrix(int n)
{
	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		mat[i][i] = 0;

		for (int j = i + 1; j < n; j++)
		{
			mat[i][j] = 0;
			mat[j][i] = 0;
		}
		
		if (i < n - 1)
		{
			mat[i][i + 1] = 1;
			mat[i + 1][i] = 1;
		}
	}

	mat[0][n - 1] = 1;
	mat[n - 1][0] = 1;

	return mat;
}

