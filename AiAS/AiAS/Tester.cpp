#include "Tester.h"


void Tester::bigTest()
{
    srand(std::time({}));

    for (int i = 9; i < 20; i++)
    {
        cout << "\nN = " << i << endl;
        int testCount = 5;
        double avgTime = 0;

        for (int j = 0; j < testCount; j++)
        {
            int** mat1 = MatrixGenerator::genRandomly(i);
            int** mat2 = MatrixGenerator::genRandomly(i);

            clock_t start = clock();

            Algorithms::shuffleAlgo(mat1, mat2, i);
            //degreeVectorAlgo(mat1, mat2, i);
            //secondOrderDegreeVectorAlgo(mat1, mat2, i);

            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            avgTime += seconds;
            cout << "�������� ������� " + to_string(seconds) + " ������\n";
        }

        cout << "������� ����� ������: " << to_string(avgTime / testCount) << " ������\n\n";
        system("pause");
    }
}


pair<double, bool> Tester::getRuntimeAndRes(int** mat1, int** mat2, int n, bool (*func)(int** mat1, int** mat2, int n))
{
    clock_t start = clock();
    bool res = (*func)(mat1, mat2, n);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    return { seconds, res };
}


void Tester::controlTest()
{
    vector<int> v = vector<int>{ 3, 5, 6, 7, 8, 9, 10 };
    int testCount = 10;

    bool (*sa)(int**, int**, int) = &Algorithms::shuffleAlgo;
    bool (*dva)(int**, int**, int) = &Algorithms::degreeVectorAlgo;
    bool (*sdva)(int**, int**, int) = &Algorithms::secondOrderDegreeVectorAlgo;

    for (int n : v)
    {
        double avgTime[3]{ 0,0,0 };
        double avgCorrect[2]{ 0,0 };

        for (int j = 0; j < testCount; j++)
        {
            int** mat1 = MatrixGenerator::genRandomly(n);
            int** mat2 = MatrixGenerator::genRandomly(n);

            pair<double, bool> res1 = getRuntimeAndRes(mat1, mat2, n, sa);
            pair<double, bool> res2 = getRuntimeAndRes(mat1, mat2, n, dva);
            pair<double, bool> res3 = getRuntimeAndRes(mat1, mat2, n, sdva);

            avgTime[0] += res1.first;
            avgTime[1] += res2.first;
            avgTime[2] += res3.first;

            avgCorrect[0] += res1.second == res2.second ? 1 : 0;
            avgCorrect[1] += res1.second == res3.second ? 1 : 0;
        }
        cout << "����� ��� N = " << n << " ������...\n";

        cout << "\n������� ����� ������ ��������� ������������: " << to_string(avgTime[0] / testCount) << " ������\n";
        cout << "������� ����� ������ ��������� ������� ��������: " << to_string(avgTime[1] / testCount) << " ������\n";
        cout << "������� ����� ������ ��������� ������� �������� ������� �������: " << to_string(avgTime[2] / testCount) << " ������\n";

        cout << "\n������� ����� ������ ������� ��������� �������� ��������: " << to_string(avgCorrect[0] / testCount);
        cout << "\n������� ����� ������ ������� ��������� �������� �������� ������� �������: " << to_string(avgCorrect[1] / testCount) << "\n";
        cout << "---------------------------------------------------------------------------\n\n";
    }
}


int** Tester::getReverseMatrix(int** mat, int n)
{
    int** mat2 = new int* [n];
    for (int i = 0; i < n; i++)
    {
        mat2[i] = new int[n];
        for (int j = 0; j < n; j++)
            mat2[i][j] = i == j ? 0 : abs(mat[i][j] - 1);
    }

    return mat2;
}


void Tester::shuffleAlgoWorstTest()
{
    cout << "\n����� �� ������ ������� ��������� ������������\n";

    vector<int> v = vector<int>{ 6, 8, 10, 11 };
    bool (*sa)(int**, int**, int) = &Algorithms::shuffleAlgo;

    for (int n : v)
    {
        int** mat1 = MatrixGenerator::genRandomly(n);
        int** mat2 = getReverseMatrix(mat1, n);

        pair<double, bool> res = getRuntimeAndRes(mat1, mat2, n, sa);

        cout << "��� N = " << n << " ����� ������ = " << res.first << " ������\n";
    }
}


void Tester::shuffleAlgoBestTest()
{
    cout << "\n����� �� ������ ������� ��������� ������������\n";

    vector<int> v = vector<int>{ 6, 8, 10, 11 };
    bool (*sa)(int**, int**, int) = &Algorithms::shuffleAlgo;

    for (int n : v)
    {
        int** mat1 = MatrixGenerator::genRandomly(n);
        int** mat2 = mat1;

        pair<double, bool> res = getRuntimeAndRes(mat1, mat2, n, sa);

        cout << "��� N = " << n << " ����� ������ = " << res.first << " ������\n";
    }
}

void Tester::degreeVectorAlgoWorstTest()
{
    cout << "\n����� �� ������ ������� ��������� ������� ��������\n";

    vector<int> v = vector<int>{ 1280, 2560, 5120, 10240 };
    bool (*dva)(int**, int**, int) = &Algorithms::degreeVectorAlgo;

    for (int n : v)
    {
        int** mat1 = MatrixGenerator::genFullMatrix(n);
        int** mat2 = mat1;

        pair<double, bool> res = getRuntimeAndRes(mat1, mat2, n, dva);

        cout << "��� N = " << n << " ����� ������ = " << res.first << " ������\n";
    }
}


void Tester::degreeVectorAlgoBestTest()
{
    cout << "\n����� �� ������ ������� ��������� ������� ��������\n";

    vector<int> v = vector<int>{ 1280, 2560, 5120, 10240 };
    bool (*dva)(int**, int**, int) = &Algorithms::degreeVectorAlgo;

    for (int n : v)
    {
        int** mat1 = MatrixGenerator::genRandomly(n);
        int** mat2 = MatrixGenerator::genChainMatrix(n);

        pair<double, bool> res = getRuntimeAndRes(mat1, mat2, n, dva);

        cout << "��� N = " << n << " ����� ������ = " << res.first << " ������\n";
    }
}

void Tester::degreeVectorSecondOrderAlgoWorstTest()
{
    cout << "\n����� �� ������ ������� ��������� ������� �������� ������� �������\n";

    vector<int> v = vector<int>{ 640, 1280, 2560, 5120 };
    bool (*sdva)(int**, int**, int) = &Algorithms::secondOrderDegreeVectorAlgo;

    for (int n : v)
    {
        int** mat1 = MatrixGenerator::genFullMatrix(n);
        int** mat2 = mat1;

        pair<double, bool> res = getRuntimeAndRes(mat1, mat2, n, sdva);

        cout << "��� N = " << n << " ����� ������ = " << res.first << " ������\n";
    }
}


void Tester::degreeVectorSecondOrderAlgoBestTest()
{
    cout << "\n����� �� ������ ������� ��������� ������� �������� ������� �������\n";

    vector<int> v = vector<int>{ 640, 1280, 2560, 5120 };
    bool (*sdva)(int**, int**, int) = &Algorithms::secondOrderDegreeVectorAlgo;

    for (int n : v)
    {
        int** mat1 = MatrixGenerator::genChainMatrix(n);
        int** mat2 = MatrixGenerator::genChainMatrix(n);
        mat2[0][1] = mat2[1][0] = 0;

        pair<double, bool> res = getRuntimeAndRes(mat1, mat2, n, sdva);

        cout << "��� N = " << n << " ����� ������ = " << res.first << " ������\n";
    }
}
