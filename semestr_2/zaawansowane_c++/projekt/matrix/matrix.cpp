#include "gmock/gmock.h"

template<std::size_t N, std::size_t M, typename T>
class Matrix
{
    std::array<std::array<T, M>, N> _array{};
public:

    Matrix() //default ctor
    {
        static_assert(!(N == 0 || M == 0),"Matrix cannot have size equal to zero");
    }


    template<std::size_t N1, std::size_t matrix, typename T1>
    Matrix(const Matrix<N1, matrix, T1>& other) //copy ctor
    {
        static_assert(!(N1 != N || matrix != M), "Both matrixes must have the same size");

        for (std::size_t n = 0; n < N1; ++n)
        {
            for (std::size_t m = 0; m < matrix; ++m)
            {
                _array[n][m] = other[n][m];
            }
        }
    }

    std::array<T, M> &operator[](std::size_t index)
    {
        return _array.at(index);
    }

    template<typename T1>
    auto operator+(const T1 &rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        Matrix<N,M,T> array;
        Matrix<N,M,T1> identityMatrix;
        for (auto &i : identityMatrix._array) // create identity matrix
            i.fill(rhs);
        for (std::size_t n = 0; n < N; ++n)
        {
            for (std::size_t m = 0; m < M; ++m)
            {
                array._array[n][m] = _array[n][m] + identityMatrix._array[n][m];
            }
        }
        return array;
    }

    template<typename T1>
    auto operator*(const T1 &rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        Matrix<N,M,T> array;

        for (std::size_t n = 0; n < N; ++n)
        {
            for (std::size_t m = 0; m < M; ++m)
            {
                array._array[n][m] = _array[n][m] * rhs;
            }
        }
        return array;

    }
    template<std::size_t N1, std::size_t matrix, typename T1>
    auto operator+(Matrix<N1, matrix, T1>& rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        static_assert(!(N1 != N || matrix != M), "Second matrix must be the same size as first matrix");

        Matrix<N,M,T> array;

        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < matrix; ++m)
            {
                array._array[n][m] = _array[n][m] + rhs._array[n][m];
            }
        }
        return array;
    }

    template<std::size_t N1, std::size_t matrix, typename T1>
    auto operator*(Matrix<N1, matrix, T1>& rhs)
    {

        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        static_assert(!(N!=matrix), "Number of rows from first matrix must be equal to number of columns from second");

        Matrix<N, matrix, T> array;
        for (std::size_t n = 0; n < N; ++n) {
            for (std::size_t m = 0; m < matrix; ++m) {
                T sum = 0;
                for (std::size_t inner = 0; inner < N1; ++inner) {
                    sum += _array[n][inner] * rhs._array[inner][m];
                }
                array._array[n][m] = sum;
            }
        }
        return array;
    }

    void display()
    {
        for (auto &i : _array)
        {
            for( auto &j : i)
            {
                std::cout << j << "\t";
            }
            std::cout << std::endl << std::endl;
        }
    }

    template<std::size_t N1, std::size_t matrix, typename T1> // zeby moc sie dostac do tablicy z rhs
      friend class Matrix;
};

template <std::size_t N, std::size_t M>
class Matrix<N, M, bool> {
   public:
    Matrix() {
        static_assert(true, "Bool type is not supported!");
        std::cout << "Bool type is not supported!" << std::endl;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// @TESTS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    Matrix<2, 2, int> matrix;
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;

    Matrix<2, 2, float> matrix2;
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
    Matrix<2, 2, int> matrix;
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
    Matrix<2, 3, int> matrix;
    matrix[0][0] = 1;
    matrix[0][1] = 5;
    matrix[0][2] = 0;
    matrix[1][0] = 2;
    matrix[1][1] = -3;
    matrix[1][2] = 1;

    Matrix<3, 2, float> matrix2;
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
    Matrix<2, 2, int> matrix;
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
    Matrix<2, 2, int> matrix;

    EXPECT_EQ(matrix[0][0], 0);
    EXPECT_EQ(matrix[0][1], 0);
    EXPECT_EQ(matrix[1][0], 0);
    EXPECT_EQ(matrix[1][1], 0);
}