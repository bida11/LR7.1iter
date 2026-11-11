#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "C:\Users\Sasha\Downloads\student\vs\LR7.1iter\LR7.1iter\LR7.1iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(CheckProcessing)
        {
            int matrix[4][5] = {
                { 3,  2, -1, -4,   0 },
                {-2,  1,  5, -8,   6 },
                { 3,  1, -5,  0, -12 },
                { 1, -1, -3, -7,   8 }
            };

            int* a[4] = {
                matrix[0], matrix[1],
                matrix[2], matrix[3]
            };

            int count = 0;
            long long sum = 0;

            processTargets(a, 4, 5, count, sum);

            Assert::AreEqual<int>(6, count);
            Assert::AreEqual<long long>(-19LL, sum);

            int expected[4][5] = {
                {3, 2, 0, -4,   0},
                {0, 1, 5, -8,   6},
                {3, 1, 0,  0, -12},
                {1, 0, 0,  0,   8}
            };

            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 5; ++j)
                    Assert::AreEqual<int>(
                        expected[i][j], a[i][j]);
        }

        TEST_METHOD(CheckSorting)
        {
            int matrix[4][5] = {
                { 3, 1,  9, 0, 0 },
                { 3, 1, -5, 0, 0 },
                {-2, 4,  5, 0, 0 },
                { 3, 0,  7, 0, 0 }
            };

            int* a[4] = {
                matrix[0], matrix[1],
                matrix[2], matrix[3]
            };

            sortRows(a, 4);

            int expected[4][5] = {
                {-2, 4,  5, 0, 0},
                { 3, 0,  7, 0, 0},
                { 3, 1, -5, 0, 0},
                { 3, 1,  9, 0, 0}
            };

            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 5; ++j)
                    Assert::AreEqual<int>(
                        expected[i][j], a[i][j]);
        }
    };
}