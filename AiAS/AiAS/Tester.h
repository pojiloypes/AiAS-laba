#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <time.h> 
#include <string>
#include "MatrixGenerator.h"
#include "Algorithms.h"

using namespace std;

class Tester
{
protected:
    /// <summary>
    /// �������� ������� � ���������� ��� �����
    /// </summary>
    /// <param name="mat">�������</param>
    /// <param name="n">���-�� ������</param>
    /// <returns>����� �������</returns>
    static int** getReverseMatrix(int** mat, int n);

public:
    /// <summary>
    /// �������� ���� ������ �� ������ N
    /// </summary>
    static void bigTest();

    /// <summary>
    /// ���������� ����� ������ ������� � ��������� �� ������
    /// </summary>
    /// <param name="mat1">������� 1</param>
    /// <param name="mat2">������� 2</param>
    /// <param name="n">����� ������</param>
    /// <param name="func">���������� �������</param>
    /// <returns>���� ������� ������� ���� � ����������</returns>
    static pair<double, bool> getRuntimeAndRes(int** mat1, int** mat2, int n, bool (*func)(int** mat1, int** mat2, int n));

    /// <summary>
    /// �������� ������������ ��� ��������� �������� ������� ������ � �������� ������ �������� ������� ��� ������ N
    /// </summary>
    static void controlTest();

    /// <summary>
    /// ��������� ������������ ��������� ������������ �� ������ �������
    /// </summary>
    static void shuffleAlgoWorstTest();

    /// <summary>
    /// ��������� ������������ ��������� ������������ �� ������ �������
    /// </summary>
    static void shuffleAlgoBestTest();

    /// <summary>
    /// ��������� ������������ ��������� ������� �������� �� ������ �������
    /// </summary>
    static void degreeVectorAlgoWorstTest();

    /// <summary>
    /// ��������� ������������ ��������� ������� �������� �� ������ �������
    /// </summary>
    static void  degreeVectorAlgoBestTest();

    /// <summary>
    /// ��������� ������������ ��������� ������� �������� ������� ������� �� ������ �������
    /// </summary>
    static void degreeVectorSecondOrderAlgoWorstTest();

    /// <summary>
    /// ��������� ������������ ��������� ������� �������� ������� ������� �� ������ �������
    /// </summary>
    static void  degreeVectorSecondOrderAlgoBestTest();


};

