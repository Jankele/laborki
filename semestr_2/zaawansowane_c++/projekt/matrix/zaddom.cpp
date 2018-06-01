#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <functional>

template<std::size_t N, std::size_t M, typename T>
class Matrix
{
    std::array<std::array<T, M>, N> _array{};
public:
    Matrix()
    {
        if (N == 0)
        {
            throw std::underflow_error { "number of rows is 0" };
        }
        if (M == 0)
        {
            throw std::underflow_error { "number of columns is 0" };
        }
        for(size_t n = 0; n < N; ++n)
        {
            _array[n].fill(3);
        }
    }

    template<std::size_t N1, std::size_t M1, typename T1>
    Matrix(const Matrix<N1, M1, T1>& other)
    {
        if (N1 > N || M1 > M)
        {
            throw std::range_error { "number of rows or columns error" };
        }
        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < M1; ++m)
            {
                _array[n][m] = other[n][m];
            }
        }
    }

    std::array<T, M> &operator[](const std::size_t &index)
    {
        return _array.at(index);
    }

    auto &operator+(const int &rhs)
    {
        std::array<std::array<T, M>, N> array{};
        for (size_t n = 0; n < N; ++n)
        {
            for (size_t m = 0; m < M; ++m)
            {
                array[n][m] = _array[n][m] + rhs;
            }
        }
        return array;
    }

    auto &operator*(const int &rhs)
    {
        std::array<std::array<T, M>, N> array{};
        for (size_t n = 0; n < N; ++n)
        {
            for (size_t m = 0; m < M; ++m)
            {
                array[n][m] = _array[n][m] + rhs;
            }
        }
        return array;

    }
    template<std::size_t N1, std::size_t M1, typename T1>
    auto &operator+(const Matrix<N1, M1, T1>& rhs)
    {
        Matrix<N,M,T> array;
        if (N1 > N || M1 > M)
        {
            throw std::range_error { "number of rows or columns error" };
        }
        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < M1; ++m)
            {
                array._array[n][m] = _array[n][m] + rhs._array[n][m];
            }
        }
        return array;
    }
    auto &operator*(const Matrix<N1, M1, T1> &rhs)
    {

        Matrix<N,M,T> array;
        if (N1 > N || M1 > M)
        {
            throw std::range_error { "number of rows or columns error" };
        }
        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < M1; ++m)
            {
                array._array[n][m] = _array[n][m] * rhs._array[n][m];
            }
        }
        return array;
    }
    void display()
    {
        for (size_t n = 0; n < N; ++n)
        {
            for (size_t m = 0; m < M; ++m)
            {
                std::cout << _array[n][m] << " ";
            }
            std::cout << std::endl;
        }
    }
};
////////////////////////////////////////
int main()
{
    Matrix<3, 3, int> matrix1;
    Matrix<3, 3, int> matrix2;
    Matrix<3,3, int> product;
    matrix1.display();
    std::cout << std::endl;
    matrix2.display();
    product = matrix1 + matrix2;
    std::cout << std::endl;
    product.display();
    return 0;
}
/*
TEST(TemplateMatrix, create) {
    Matrix<3, 5, int> m;
    EXPECT_EQ(m[0][0], 0);
    m[2][1] = 1;
    EXPECT_EQ(m[2][1], 1);
}

TEST(TemplateMatrix, createZero) {
    auto l = []() {
        Matrix<0, 3, int> m;
    };
    EXPECT_THROW(l(), underflow_error);

    auto l2 = []() {
        Matrix<3, 0, int> m;
    };
    EXPECT_THROW(l2()   , underflow_error);
}

TEST(TemplateMatrix, createBool) {
    auto l = []() {
        Matrix<3, 3, bool> m;
    };
    EXPECT_THROW(l(), bad_typeid);
}

TEST(TemplateMatrix, copyCtor) {
    int number = 0;
    const int I = 2;
    const int J = 3;

    Matrix<I, J, int> m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }

    Matrix<I, J, int> n = m;

    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}
TEST(TemplateMatrix, copyCtorCopy) {
    int number = 0;
    const int I = 2;
    const int J = 2;

    Matrix<I, J, int> m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    Matrix<3, 3, int> n = m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}

TEST(TemplateMatrix, copyCtorExcept) {
    auto l = [&]() {
        Matrix<3, 3, int> m;
        m[1][1] = 5;
        Matrix<2, 3, int> n = m;
    };
    EXPECT_THROW(l(), range_error);
    auto o = [&]() {
        Matrix<3, 3, int> m;
        m[1][1] = 5;
        Matrix<3, 2, int> n = m;
    };
    EXPECT_THROW(o(), range_error);
}
*/
/*
static_assert(std::is_convertible<T, T1>::value, "no");
operator [][];
nie uzywac #define
*/