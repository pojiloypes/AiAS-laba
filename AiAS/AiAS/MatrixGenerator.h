#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class MatrixGenerator
{
public:
	 /// <summary>
	 /// Главный метод генериации матриц
	 /// </summary>
	 /// <returns></returns>
	 static pair<int, pair<int**, int**>> genMatrixes();


	 /// <summary>
	 /// Читает матрицу из файла
	 /// </summary>
	 /// <param name="fileName">Название файла</param>
	 /// <returns>Пару {Матрица, Число вершин}</returns>
	 static pair<int**, int> readMatrixFromFile(string fileName);


	 /// <summary>
	 /// Генерирует матрицу
	 /// </summary>
	 /// <param name="n">Число вершин</param>
	 /// <returns>Матрица</returns>
	 static int** genRandomly(int n);

	
	 /// <summary>
	 /// Генерирует матрицу полного графа
	 /// </summary>
	 /// <param name="n">Число вершин</param>
	 /// <returns>Матрица</returns>
	 static int** genFullMatrix(int n);


	 /// <summary>
	 /// Генерирует матрицу в которой каждая вершина соединена только с соседними двумя
	 /// </summary>
	 /// <param name="n"></param>
	 /// <returns></returns>
	 static int** genChainMatrix(int n);
};

