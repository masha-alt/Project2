#include "pch.h"
#include "gtest/gtest.h"

bool calculateProductBelowDiagonal(const int matrix[][50], int rows, int cols, long long& product) {
    product = 1;
    bool has_positive = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && matrix[i][j] > 0) {
                product *= matrix[i][j];
                has_positive = true;
            }
        }
    }
    return has_positive;
}

TEST(MatrixProductTest, NormalMatrixWithPositiveNumbers) {
    int matrix[50][50] = {
        { 5,  2,  3 },
        { 4,  6,  1 }, 
        { 2,  3,  7 }  
    };
    long long prod = 0;

    EXPECT_TRUE(calculateProductBelowDiagonal(matrix, 3, 3, prod));
    EXPECT_EQ(prod, 24);
}

TEST(MatrixProductTest, OnlyNegativeAndZerosBelowDiagonal) {
    int matrix[50][50] = {
        { 1,  2,  3 },
        { -4, 5,  6 }, 
        { 0,  -2, 9 }  
    };
    long long prod = 0;

    EXPECT_FALSE(calculateProductBelowDiagonal(matrix, 3, 3, prod));
}

TEST(MatrixProductTest, SingleElementMatrix) {
    int matrix[50][50] = {
        { 5 }
    };
    long long prod = 0;

    EXPECT_FALSE(calculateProductBelowDiagonal(matrix, 1, 1, prod));
}
