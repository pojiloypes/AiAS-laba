#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <time.h> 
#include <string>
#include "MatrixGenerator.h"

using namespace std;

void printMatrix(int** mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << "------\n\n";
}

bool compareMatrixes(int** mat1, int** mat2, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (mat1[i][j] != mat2[i][j])
                return false;

    return true;
}

bool shuffleAlgo(int** mat1, int** mat2, int n)
{
    vector<int> shuffles = vector<int>(n);
    int** shaffledMat = new int* [n];

    for (int i = 0; i < n; i++)
    {
        shuffles[i] = i;
        shaffledMat[i] = new int[n];
    }

    do 
    {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                shaffledMat[i][j] = mat1[shuffles[i]][shuffles[j]];

        if (compareMatrixes(shaffledMat, mat2, n))
            return true;
        
    } while (next_permutation(shuffles.begin(), shuffles.end()));

    return false;
}

bool compareDegreeVectors(vector<int> v1, vector<int> v2, int n)
{
    for (int i = 0; i < n; i++)
        if (v1[i] != v2[i])
            return false;

    return true;
}

vector<int> getDegreeVector(int** mat, int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i] += mat[i][j];

    return res;
}

bool degreeVectorAlgo(int** mat1, int** mat2, int n)
{
    vector<int> v1 = getDegreeVector(mat1, n);
    vector<int> v2 = getDegreeVector(mat2, n);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    return compareDegreeVectors(v1, v2, n);
}

bool compare(const pair<int, vector<int>>& left, const pair<int, vector<int>>& right)
{
    if (left.first != right.first)
        return left.first < right.first;

    if (left.second.size() != right.second.size())
        return left.second.size() < right.second.size();

    return left.second < right.second;
}

bool compareSecondOrderDegreeVectors(vector<pair<int, vector<int>>> v1, vector<pair<int, vector<int>>> v2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (v1[i].first != v2[i].first)
            return false;

        if (v1[i].second.size() != v2[i].second.size())
            return false;

        for (int j = 0; j < v1[i].second.size(); j++)
            if (v1[i].second[j] != v2[i].second[j])
                return false;
    }

    return true;
}

vector<pair<int, vector<int>>> getSecondOrderDegreeVector(int** mat, int n)
{
    vector<int> degreeVec = getDegreeVector(mat, n);

    vector<pair<int, vector<int>>> res(n);

    for (int i = 0; i < n; i++)
    {
        res[i].first = degreeVec[i];
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 1)
                res[i].second.push_back(degreeVec[j]);
    }

    return res;
}

bool secondOrderDegreeVectorAlgo(int** mat1, int** mat2, int n)
{
    vector<pair<int, vector<int>>> v1 = getSecondOrderDegreeVector(mat1, n);
    vector<pair<int, vector<int>>> v2 = getSecondOrderDegreeVector(mat2, n);

    for (int i = 0; i < n; i++)
    {
        sort(v1[i].second.begin(), v1[i].second.end());
        sort(v2[i].second.begin(), v2[i].second.end());
    }

    sort(begin(v1), end(v1), compare);
    sort(begin(v2), end(v2), compare);

    return compareSecondOrderDegreeVectors(v1, v2, n);
}

void alg1(int** mat1, int** mat2, int n)
{
    bool res = shuffleAlgo(mat1, mat2, n);
    cout << "Алгоритм перестановок: ";
    if (res)
        cout << "ДА\n";
    else
        cout << "НЕТ\n";
}

void alg2(int** mat1, int** mat2, int n)
{
    bool res = degreeVectorAlgo(mat1, mat2, n);
    cout << "\nАлгоритм векторов степеней: ";
    if (res)
        cout << "ДА\n";
    else
        cout << "НЕТ\n";
}

void alg3(int** mat1, int** mat2, int n)
{
    bool res = secondOrderDegreeVectorAlgo(mat1, mat2, n);

    cout << "\nАлгоритм векторов степеней второго порядка: ";
    if (res)
        cout << "ДА\n";
    else
        cout << "НЕТ\n";
}

/// <summary>
/// Проводит кучу тестов на разных N
/// </summary>
void bigTest()
{
    srand(std::time({}));

    MatrixGenerator* mg = new MatrixGenerator();

    for (int i = 9; i < 20; i++)
    {
        cout << "\nN = " << i << endl;
        int testCount = 5;
        double avgTime = 0;

        for (int j = 0; j < testCount; j++)
        {
            int** mat1 = mg->genRandomly(i);
            int** mat2 = mg->genRandomly(i);

            clock_t start = clock();

            shuffleAlgo(mat1, mat2, i);
            //degreeVectorAlgo(mat1, mat2, i);
            //secondOrderDegreeVectorAlgo(mat1, mat2, i);

            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            avgTime += seconds;
            cout << "Алгоритм работал " + to_string(seconds) + " секунд\n";
        }

        cout << "Среднее время работы: " << to_string(avgTime / testCount) << " секунд\n\n";
        system("pause");
    }
}

/// <summary>
/// Вовзращает время работы функции и результат ее работы
/// </summary>
/// <param name="mat1">Матрица 1</param>
/// <param name="mat2">Матрица 2</param>
/// <param name="n">Число вершин</param>
/// <param name="func">Измеряемая функция</param>
/// <returns>Пара зачений времени рабы и результата</returns>
pair<double, bool> getRuntimeAndRes(int** mat1, int** mat2, int n, bool (*func)(int** mat1, int** mat2, int n))
{
    clock_t start = clock();
    bool res = (*func)(mat1, mat2, n);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    return { seconds, res };
}

/// <summary>
/// Проводит тестирование для измерения среднего времени работы и качества работы неточных алгосов для разных N
/// </summary>
void controlTest()
{
    vector<int> v = vector<int>{ 3, 5, 6, 7, 8, 9, 10};
    MatrixGenerator* mg = new MatrixGenerator();
    int testCount = 10;

    bool (*sa)(int**, int**, int) = &shuffleAlgo;
    bool (*dva)(int**, int**, int) = &degreeVectorAlgo;
    bool (*sdva)(int**, int**, int) = &secondOrderDegreeVectorAlgo;

    for (int n : v)
    {
        double avgTime[3]{ 0,0,0 };
        double avgCorrect[2]{ 0,0 };

        for (int j = 0; j < testCount; j++)
        {
            int** mat1 = mg->genRandomly(n);
            int** mat2 = mg->genRandomly(n);

            pair<double, bool> res1 = getRuntimeAndRes(mat1, mat2, n, sa);
            pair<double, bool> res2 = getRuntimeAndRes(mat1, mat2, n, dva);
            pair<double, bool> res3 = getRuntimeAndRes(mat1, mat2, n, sdva);
            
            avgTime[0] += res1.first;
            avgTime[1] += res2.first;
            avgTime[2] += res3.first;

            avgCorrect[0] += res1.second == res2.second ? 1 : 0;
            avgCorrect[1] += res1.second == res3.second ? 1 : 0;
        }
        cout << "Тесты для N = " << n << " прошли...\n";

        cout << "\nСреднее время работы алгоритма перестановок: " << to_string(avgTime[0] / testCount) << " секунд\n";
        cout << "Среднее время работы алгоритма вектоора степеней: " << to_string(avgTime[1] / testCount) << " секунд\n";
        cout << "Среднее время работы алгоритма вектоора степеней второго порядка: " << to_string(avgTime[2] / testCount) << " секунд\n";

        cout << "\nСреднее число верных ответов алгоритма вектоора степеней: " << to_string(avgCorrect[0] / testCount);
        cout << "\nСреднее число верных ответов алгоритма вектоора степеней второго порядка: " << to_string(avgCorrect[1] / testCount) << "\n";
        cout << "---------------------------------------------------------------------------\n\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    bigTest();

    /*MatrixGenerator* mg = new MatrixGenerator();

    pair<int**, int> p1 = mg->readMatrixFromFile("mat7.txt");
    pair<int**, int> p2 = mg->readMatrixFromFile("mat8.txt");

    int n = p1.second;
    int** mat1 = p1.first;
    int** mat2 = p2.first;

    cout << "Матрица №1\n";
    printMatrix(mat1, n);

    cout << "Матрица №2\n";
    printMatrix(mat2, n);

    alg1(mat1, mat2, n);*/
    //alg2(mat1, mat2, n);
    //alg3(mat1, mat2, n);
}