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
    /// Копирует матрицу и инвертрует все ребра
    /// </summary>
    /// <param name="mat">Матрица</param>
    /// <param name="n">Кол-ва вершин</param>
    /// <returns>Новая матрица</returns>
    static int** getReverseMatrix(int** mat, int n);

public:
    /// <summary>
    /// Проводит кучу тестов на разных N
    /// </summary>
    static void bigTest();

    /// <summary>
    /// Вовзращает время работы функции и результат ее работы
    /// </summary>
    /// <param name="mat1">Матрица 1</param>
    /// <param name="mat2">Матрица 2</param>
    /// <param name="n">Число вершин</param>
    /// <param name="func">Измеряемая функция</param>
    /// <returns>Пара зачений времени рабы и результата</returns>
    static pair<double, bool> getRuntimeAndRes(int** mat1, int** mat2, int n, bool (*func)(int** mat1, int** mat2, int n));

    /// <summary>
    /// Проводит тестирование для измерения среднего времени работы и качества работы неточных алгосов для разных N
    /// </summary>
    static void controlTest();

    /// <summary>
    /// Выполняет тестирование алгоритма перестановок на худших случаях
    /// </summary>
    static void shuffleAlgoWorstTest();

    /// <summary>
    /// Выполняет тестирование алгоритма перестановок на худших случаях
    /// </summary>
    static void shuffleAlgoBestTest();

    /// <summary>
    /// Выполняет тестирование алгоритма вектора степеней на худших случаях
    /// </summary>
    static void degreeVectorAlgoWorstTest();

    /// <summary>
    /// Выполняет тестирование алгоритма вектора степеней на худших случаях
    /// </summary>
    static void  degreeVectorAlgoBestTest();

    /// <summary>
    /// Выполняет тестирование алгоритма вектора степеней второго порядка на худших случаях
    /// </summary>
    static void degreeVectorSecondOrderAlgoWorstTest();

    /// <summary>
    /// Выполняет тестирование алгоритма вектора степеней второго порядка на худших случаях
    /// </summary>
    static void  degreeVectorSecondOrderAlgoBestTest();


};

