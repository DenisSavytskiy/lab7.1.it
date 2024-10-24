// Lab_7_1.cpp
// < Савицького Дениса >
// Лабораторна робота № 7.1.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 27
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** matrix, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            matrix[i][j] = rand() % 94 - 42;
}

void Print(int** matrix, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

void ProcessElements(int** matrix, const int rowCount, const int colCount, int& sum, int& count) {
    sum = 0;
    count = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (!(matrix[i][j] >= 0 && matrix[i][j] % 5 == 0)) {
                sum += matrix[i][j];
                count++;
                matrix[i][j] = 0;
            }
}

void SwapRows(int** matrix, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

void SortRows(int** matrix, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount - 1; i++)
        for (int j = 0; j < rowCount - i - 1; j++) {
            if ((matrix[j][0] > matrix[j + 1][0]) ||
                (matrix[j][0] == matrix[j + 1][0] && matrix[j][1] < matrix[j + 1][1]) ||
                (matrix[j][0] == matrix[j + 1][0] && matrix[j][1] == matrix[j + 1][1] &&
                    matrix[j][2] > matrix[j + 1][2]))
                SwapRows(matrix, j, j + 1, colCount);
        }
}

int main() {
    srand((unsigned)time(NULL));

    const int ROW_COUNT = 7;
    const int COL_COUNT = 6;

    int** matrix = new int* [ROW_COUNT];
    for (int i = 0; i < ROW_COUNT; i++)
        matrix[i] = new int[COL_COUNT];

    Create(matrix, ROW_COUNT, COL_COUNT);

    Print(matrix, ROW_COUNT, COL_COUNT);

    int S = 0, k = 0;
    ProcessElements(matrix, ROW_COUNT, COL_COUNT, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    Print(matrix, ROW_COUNT, COL_COUNT);

    SortRows(matrix, ROW_COUNT, COL_COUNT);

    Print(matrix, ROW_COUNT, COL_COUNT);

    return 0;
}