#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№7.1.іт/AP_Lab№7.1.іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIter {
    TEST_CLASS(MatrixProcessingTests) {
public:
    TEST_METHOD(TestProcessElements) {
        const int rows = 2, cols = 2;
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[cols];

        matrix[0][0] = 10;  // не повинен оброблятися
        matrix[0][1] = 3;   // повинен оброблятися
        matrix[1][0] = -5;  // повинен оброблятися
        matrix[1][1] = 15;  // не повинен оброблятися

        int sum = 0, count = 0;
        ProcessElements(matrix, rows, cols, sum, count);

        Assert::AreEqual(2, count);  // повинно бути оброблено 2 елементи
        Assert::AreEqual(-2, sum);   // сума -5 + 3
        Assert::AreEqual(0, matrix[0][1]); // перевірка заміни на 0

        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    TEST_METHOD(TestSortRows) {
        const int rows = 3, cols = 3;
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new int[cols];

        // Заповнюємо тестову матрицю
        matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
        matrix[1][0] = 1; matrix[1][1] = 2; matrix[1][2] = 1;
        matrix[2][0] = 1; matrix[2][1] = 1; matrix[2][2] = 2;

        SortRows(matrix, rows, cols);

        // Перевіряємо правильність сортування
        Assert::AreEqual(1, matrix[0][0]); // перший стовпець
        Assert::AreEqual(2, matrix[0][1]); // другий стовпець
        Assert::AreEqual(1, matrix[0][2]); // третій стовпець

        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    };
}