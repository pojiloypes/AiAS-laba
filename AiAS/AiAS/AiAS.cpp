#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <time.h> 
#include <string>
#include "MatrixGenerator.h"
#include "Algorithms.h"
#include "Tester.h"

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


void alg1(int** mat1, int** mat2, int n)
{
    bool res = Algorithms::shuffleAlgo(mat1, mat2, n);
    cout << "Алгоритм перестановок: ";
    if (res)
        cout << "ДА\n";
    else
        cout << "НЕТ\n";
}

void alg2(int** mat1, int** mat2, int n)
{
    bool res = Algorithms::degreeVectorAlgo(mat1, mat2, n);
    cout << "\nАлгоритм векторов степеней: ";
    if (res)
        cout << "ДА\n";
    else
        cout << "НЕТ\n";
}

void alg3(int** mat1, int** mat2, int n)
{
    bool res = Algorithms::secondOrderDegreeVectorAlgo(mat1, mat2, n);

    cout << "\nАлгоритм векторов степеней второго порядка: ";
    if (res)
        cout << "ДА\n";
    else
        cout << "НЕТ\n";
}



int main()
{
    setlocale(LC_ALL, "Russian");

    Tester::shuffleAlgoBestTest();
    Tester::shuffleAlgoWorstTest();

    Tester::degreeVectorAlgoBestTest();
    Tester::degreeVectorAlgoWorstTest();

    Tester::degreeVectorSecondOrderAlgoBestTest();
    Tester::degreeVectorSecondOrderAlgoWorstTest();

}