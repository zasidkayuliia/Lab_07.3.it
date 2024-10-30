#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;

void InputMatrix(int** matrix, int size);
void PrintMatrix(int** matrix, int size);
void CountLocalMinima(int** matrix, int size, int& count);
int SumAboveMainDiagonal(int** matrix, int size);

int main()
{
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int Low = -10, High = 10;
    int size;

    cout << "Розмір матриці (n x n): ";
    cin >> size;

    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    InputMatrix(matrix, size); // Для ручного введення

    PrintMatrix(matrix, size);

    int localMinimaCount = 0;
    CountLocalMinima(matrix, size, localMinimaCount);
    cout << "Кількість локальних мінімумів: " << localMinimaCount << endl;

    int sumAboveDiagonal = SumAboveMainDiagonal(matrix, size);
    cout << "Сума модулів елементів вище головної діагоналі: " << sumAboveDiagonal << endl;

    // Очищення пам'яті
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

// Функція для ручного введення елементів матриці
void InputMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }
}

// Функція для виведення матриці
void PrintMatrix(int** matrix, int size)
{
    cout << "Матриця:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
}

// Функція для підрахунку локальних мінімумів
void CountLocalMinima(int** matrix, int size, int& count)
{
    count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            bool isLocalMin = true;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0) continue;

                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < size && nj >= 0 && nj < size)
                    {
                        if (matrix[i][j] >= matrix[ni][nj])
                        {
                            isLocalMin = false;
                            break;
                        }
                    }
                }
                if (!isLocalMin) break;
            }
            if (isLocalMin)
                count++;
        }
    }
}

// Функція для підрахунку суми модулів елементів вище головної діагоналі
int SumAboveMainDiagonal(int** matrix, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            sum += abs(matrix[i][j]);
        }
    }
    return sum;
}
