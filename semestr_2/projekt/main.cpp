#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(Matrix, Adding_Scalar_To_Matrix){
    Matrix<2,2,float> matrix;
    matrix[0][0] = 2.0;
    matrix[0][1] = 2.0;
    matrix[1][0] = 2.0;
    matrix[1][1] = 2.0;

    int scalar = 5;
    auto matrix2 = matrix + scalar;
    EXPECT_EQ(matrix2[0][0], 7);
    EXPECT_EQ(matrix2[0][1], 7);
    EXPECT_EQ(matrix2[1][0], 7);
    EXPECT_EQ(matrix2[1][1], 7);
}

TEST(Matrix, Adding_Matrix_To_Matrix) {
    Matrix<2,2,int> matrix;
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;

    Matrix<2,2,float> matrix2;
    matrix2[0][0] = 2.0;
    matrix2[0][1] = 2.0;
    matrix2[1][0] = 4.0;
    matrix2[1][1] = 3.0;

    auto matrix3 = matrix + matrix2;
    EXPECT_EQ(matrix3[0][0], 3);
    EXPECT_EQ(matrix3[0][1], 3);
    EXPECT_EQ(matrix3[1][0], 5);
    EXPECT_EQ(matrix3[1][1], 4);
}

TEST(Matrix, Multiplying_Matrix_By_Scalar) {
    Matrix<2,2,int> matrix;
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;

    float scalar = 5;

    auto matrix2 = matrix * scalar;
    EXPECT_EQ(matrix2[0][0], 5);
    EXPECT_EQ(matrix2[0][1], 5);
    EXPECT_EQ(matrix2[1][0], 5);
    EXPECT_EQ(matrix2[1][1], 5);
}

TEST(Matrix, Multiplying_Matrix_By_Matrix) {
    Matrix<2,3,int> matrix;
    matrix[0][0] = 1;
    matrix[0][1] = 5;
    matrix[0][2] = 0;
    matrix[1][0] = 2;
    matrix[1][1] = -3;
    matrix[1][2] = 1;

    Matrix<3,2,float> matrix2;
    matrix2[0][0] = 0.0;
    matrix2[0][1] = -2.0;
    matrix2[1][0] = 1.0;
    matrix2[1][1] = 1.0;
    matrix2[2][0] = 3.0;
    matrix2[2][1] = 4.0;

    auto matrix3 = matrix * matrix2;
    EXPECT_EQ(matrix3[0][0], 5);
    EXPECT_EQ(matrix3[0][1], 3);
    EXPECT_EQ(matrix3[1][0], 0);
    EXPECT_EQ(matrix3[1][1], -3);

}

TEST(Matrix, Copy_Ctor) {
    Matrix<2,2,int> matrix;
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;

    auto matrix2 = matrix;

    EXPECT_EQ(matrix2[0][0], 1);
    EXPECT_EQ(matrix2[0][1], 2);
    EXPECT_EQ(matrix2[1][0], 3);
    EXPECT_EQ(matrix2[1][1], 4);
}

TEST(Matrix, Default_Ctor) {
    Matrix<2,2,int> matrix;

    EXPECT_EQ(matrix[0][0], 0);
    EXPECT_EQ(matrix[0][1], 0);
    EXPECT_EQ(matrix[1][0], 0);
    EXPECT_EQ(matrix[1][1], 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
