#include <iomanip>
#include <iostream>
#include <random>
#include <utility>

void fillMatrix(int** a, int rows, int cols, std::mt19937& gen);
void printMatrix(int** a, int rows, int cols);
bool isTarget(int x);
void processTargets(int** a, int rows, int cols,
    int& count, long long& sum);
bool rowGreater(int** a, int x, int y);
void sortRows(int** a, int rows);

#ifndef UNIT_TEST
int main()
{
    const int rows = 8;
    const int cols = 5;

    int** a = new int* [rows];
    for (int i = 0; i < rows; ++i)
        a[i] = new int[cols];

    std::mt19937 gen(2026);
    fillMatrix(a, rows, cols, gen);

    std::cout << "Initial matrix:\n";
    printMatrix(a, rows, cols);

    int count = 0;
    long long sum = 0;

    processTargets(a, rows, cols, count, sum);

    std::cout << "Count: " << count
        << "\nSum: " << sum
        << "\nMatrix after replacing target elements:\n";
    printMatrix(a, rows, cols);

    sortRows(a, rows);

    std::cout << "Matrix after sorting rows by columns 1, 2, 3:\n";
    printMatrix(a, rows, cols);

    for (int i = 0; i < rows; ++i)
        delete[] a[i];

    delete[] a;

    return 0;
}
#endif

void fillMatrix(int** a, int rows, int cols, std::mt19937& gen)
{
    std::uniform_int_distribution<int> distribution(-17, 14);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            a[i][j] = distribution(gen);
}

void printMatrix(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << std::setw(5) << a[i][j];

        std::cout << '\n';
    }
}

bool isTarget(int x)
{
    return x < 0 && x % 4 != 0;
}

void processTargets(int** a, int rows, int cols,
    int& count, long long& sum)
{
    count = 0;
    sum = 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            if (isTarget(a[i][j]))
            {
                ++count;
                sum += a[i][j];
                a[i][j] = 0;
            }
        }
}

bool rowGreater(int** a, int x, int y)
{
    for (int j = 0; j < 3; ++j)
    {
        if (a[x][j] != a[y][j])
            return a[x][j] > a[y][j];
    }

    return false;
}

void sortRows(int** a, int rows)
{
    for (int i = 0; i < rows - 1; ++i)
        for (int j = 0; j < rows - 1 - i; ++j)
        {
            if (rowGreater(a, j, j + 1))
            {
                for (int c = 0; c < 5; ++c)
                    std::swap(a[j][c], a[j + 1][c]);
            }
        }
}