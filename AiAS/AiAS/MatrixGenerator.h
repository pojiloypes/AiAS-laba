#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class MatrixGenerator
{
public:
	 /// <summary>
	 /// ������� ����� ���������� ������
	 /// </summary>
	 /// <returns></returns>
	 static pair<int, pair<int**, int**>> genMatrixes();


	 /// <summary>
	 /// ������ ������� �� �����
	 /// </summary>
	 /// <param name="fileName">�������� �����</param>
	 /// <returns>���� {�������, ����� ������}</returns>
	 static pair<int**, int> readMatrixFromFile(string fileName);


	 /// <summary>
	 /// ���������� �������
	 /// </summary>
	 /// <param name="n">����� ������</param>
	 /// <returns>�������</returns>
	 static int** genRandomly(int n);

	
	 /// <summary>
	 /// ���������� ������� ������� �����
	 /// </summary>
	 /// <param name="n">����� ������</param>
	 /// <returns>�������</returns>
	 static int** genFullMatrix(int n);


	 /// <summary>
	 /// ���������� ������� � ������� ������ ������� ��������� ������ � ��������� �����
	 /// </summary>
	 /// <param name="n"></param>
	 /// <returns></returns>
	 static int** genChainMatrix(int n);
};

