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
    /// Сравнивает матрицы на одинаковость
    /// </summary>
    /// <param name="mat1">Матрица 1</param>
    /// <param name="mat2">Матрица 2</param>
    /// <param name="n">Кол-во вершин</param>
    /// <returns>Одинаковые или нет</returns>
    static bool compareMatrixes(int** mat1, int** mat2, int n);

    /// <summary>
    /// Сравнивает два вектора на одинаковость
    /// </summary>
    /// <param name="v1">Вектор 1</param>
    /// <param name="v2">Векор 2</param>
    /// <param name="n">Число элементов в векторах</param>
    /// <returns>Одинаковы или нет</returns>
    static bool compareDegreeVectors(vector<int> v1, vector<int> v2, int n);

    /// <summary>
    /// Считает вектор степеней вершин графа
    /// </summary>
    /// <param name="mat">Матрица смежности</param>
    /// <param name="n">Число вершин</param>
    /// <returns>Вектор степеней вершин графа</returns>
    static vector<int> getDegreeVector(int** mat, int n);

    /// <summary>
    /// Сравненивает элементы вектора степеней второго порядка
    /// </summary>
    /// <param name="left">Степень первой вершины втоорого порядка</param>
    /// <param name="right">Степень второй вершины втоорого порядка</param>
    /// <returns>Одинаковы или нет</returns>
    static bool compare(const pair<int, vector<int>>& left, const pair<int, vector<int>>& right);

    /// <summary>
    /// Сравнивает векора степеней второго порядка
    /// </summary>
    /// <param name="v1">Вектор 1</param>
    /// <param name="v2">Вектор 2</param>
    /// <param name="n">Число вершин</param>
    /// <returns>Одинаковы или нет</returns>
    static bool compareSecondOrderDegreeVectors(vector<pair<int, vector<int>>> v1, vector<pair<int, vector<int>>> v2, int n);

    /// <summary>
    /// Считает вектор степеней второго порядка графа
    /// </summary>
    /// <param name="mat">Матрица смежности</param>
    /// <param name="n">Число вершин</param>
    /// <returns>Вектор степеней второго порядка графа</returns>
    static vector<pair<int, vector<int>>> getSecondOrderDegreeVector(int** mat, int n);

public:
    /// <summary>
    /// Алгоритм перестановок для проверки графов на изоморфизм
    /// </summary>
    /// <param name="mat1">Матрица смежности первого графа</param>
    /// <param name="mat2">Матрица смежности второго графа</param>
    /// <param name="n">Кол-во вершин</param>
    /// <returns>Изоморфны или нет</returns>
    static bool shuffleAlgo(int** mat1, int** mat2, int n);

    /// <summary>
    /// Проеряет на изоморфизм сравнивая вектора степеней вершин
    /// </summary>
    /// <param name="mat1">Матрица смежности первого графа</param>
    /// <param name="mat2">Матрица смежности второго графа</param>
    /// <param name="n">Кол-во вершин</param>
    /// <returns>Изоморфны или нет</returns>
    static bool degreeVectorAlgo(int** mat1, int** mat2, int n);

    /// <summary>
    /// Проверяет на изоморфизм сравнивая вектора степеней второг порядка
    /// </summary>
    /// <param name="mat1">Матрица смежности первого графа</param>
    /// <param name="mat2">Матрица смежности второго графа</param>
    /// <param name="n">Кол-во вершин</param>
    /// <returns>Изоморфны или нет</returns>
    static bool secondOrderDegreeVectorAlgo(int** mat1, int** mat2, int n);
};

