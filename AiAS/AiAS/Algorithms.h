#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Algorithms
{
protected:
    /// <summary>
    /// ���������� ������� �� ������������
    /// </summary>
    /// <param name="mat1">������� 1</param>
    /// <param name="mat2">������� 2</param>
    /// <param name="n">���-�� ������</param>
    /// <returns>���������� ��� ���</returns>
    static bool compareMatrixes(int** mat1, int** mat2, int n);

    /// <summary>
    /// ���������� ��� ������� �� ������������
    /// </summary>
    /// <param name="v1">������ 1</param>
    /// <param name="v2">����� 2</param>
    /// <param name="n">����� ��������� � ��������</param>
    /// <returns>��������� ��� ���</returns>
    static bool compareDegreeVectors(vector<int> v1, vector<int> v2, int n);

    /// <summary>
    /// ������� ������ �������� ������ �����
    /// </summary>
    /// <param name="mat">������� ���������</param>
    /// <param name="n">����� ������</param>
    /// <returns>������ �������� ������ �����</returns>
    static vector<int> getDegreeVector(int** mat, int n);

    /// <summary>
    /// ������������ �������� ������� �������� ������� �������
    /// </summary>
    /// <param name="left">������� ������ ������� �������� �������</param>
    /// <param name="right">������� ������ ������� �������� �������</param>
    /// <returns>��������� ��� ���</returns>
    static bool compare(const pair<int, vector<int>>& left, const pair<int, vector<int>>& right);

    /// <summary>
    /// ���������� ������ �������� ������� �������
    /// </summary>
    /// <param name="v1">������ 1</param>
    /// <param name="v2">������ 2</param>
    /// <param name="n">����� ������</param>
    /// <returns>��������� ��� ���</returns>
    static bool compareSecondOrderDegreeVectors(vector<pair<int, vector<int>>> v1, vector<pair<int, vector<int>>> v2, int n);

    /// <summary>
    /// ������� ������ �������� ������� ������� �����
    /// </summary>
    /// <param name="mat">������� ���������</param>
    /// <param name="n">����� ������</param>
    /// <returns>������ �������� ������� ������� �����</returns>
    static vector<pair<int, vector<int>>> getSecondOrderDegreeVector(int** mat, int n);

public:
    /// <summary>
    /// �������� ������������ ��� �������� ������ �� ����������
    /// </summary>
    /// <param name="mat1">������� ��������� ������� �����</param>
    /// <param name="mat2">������� ��������� ������� �����</param>
    /// <param name="n">���-�� ������</param>
    /// <returns>��������� ��� ���</returns>
    static bool shuffleAlgo(int** mat1, int** mat2, int n);

    /// <summary>
    /// �������� �� ���������� ��������� ������� �������� ������
    /// </summary>
    /// <param name="mat1">������� ��������� ������� �����</param>
    /// <param name="mat2">������� ��������� ������� �����</param>
    /// <param name="n">���-�� ������</param>
    /// <returns>��������� ��� ���</returns>
    static bool degreeVectorAlgo(int** mat1, int** mat2, int n);

    /// <summary>
    /// ��������� �� ���������� ��������� ������� �������� ������ �������
    /// </summary>
    /// <param name="mat1">������� ��������� ������� �����</param>
    /// <param name="mat2">������� ��������� ������� �����</param>
    /// <param name="n">���-�� ������</param>
    /// <returns>��������� ��� ���</returns>
    static bool secondOrderDegreeVectorAlgo(int** mat1, int** mat2, int n);
};

