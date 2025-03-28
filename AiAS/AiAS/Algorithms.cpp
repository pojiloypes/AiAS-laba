#include "Algorithms.h"

bool Algorithms::compareMatrixes(int** mat1, int** mat2, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (mat1[i][j] != mat2[i][j])
                return false;

    return true;
}


bool Algorithms::shuffleAlgo(int** mat1, int** mat2, int n)
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


bool Algorithms::compareDegreeVectors(vector<int> v1, vector<int> v2, int n)
{
    for (int i = 0; i < n; i++)
        if (v1[i] != v2[i])
            return false;

    return true;
}

vector<int> Algorithms::getDegreeVector(int** mat, int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i] += mat[i][j];

    return res;
}


bool Algorithms::degreeVectorAlgo(int** mat1, int** mat2, int n)
{
    vector<int> v1 = getDegreeVector(mat1, n);
    vector<int> v2 = getDegreeVector(mat2, n);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    return compareDegreeVectors(v1, v2, n);
}


bool Algorithms::compare(const pair<int, vector<int>>& left, const pair<int, vector<int>>& right)
{
    if (left.first != right.first)
        return left.first < right.first;

    if (left.second.size() != right.second.size())
        return left.second.size() < right.second.size();

    return left.second < right.second;
}


bool Algorithms::compareSecondOrderDegreeVectors(vector<pair<int, vector<int>>> v1, vector<pair<int, vector<int>>> v2, int n)
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


vector<pair<int, vector<int>>> Algorithms::getSecondOrderDegreeVector(int** mat, int n)
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


bool Algorithms::secondOrderDegreeVectorAlgo(int** mat1, int** mat2, int n)
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