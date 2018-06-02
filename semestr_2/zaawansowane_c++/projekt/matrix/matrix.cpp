#include <array>
#include <iostream>
#include <type_traits>
#include <cstdlib>
#include <ctime>

template<std::size_t N, std::size_t M, typename T>
class Matrix
{
    std::array<std::array<T, M>, N> _array{};
public:

    Matrix() //default ctor
    {
        static_assert(!(N == 0 || M == 0),"Matrix cannot have size equal to zero");

        for (auto &i : _array)
        {
            for( auto &j : i)
            {
                j = std::rand() % 20;
            }
        }
    }

    template<std::size_t N1, std::size_t M1, typename T1>
    Matrix(const Matrix<N1, M1, T1>& other) //copy ctor
    {
        static_assert(!(N1 != N || M1 != M), "Both matrixes must have the same size");

        for (std::size_t n = 0; n < N1; ++n)
        {
            for (std::size_t m = 0; m < M1; ++m)
            {
                _array[n][m] = other[n][m];
            }
        }
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
    template<std::size_t N1, std::size_t M1, typename T1>
    auto operator+(Matrix<N1, M1, T1>& rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        static_assert(!(N1 != N || M1 != M), "Second matrix must be the same size as first matrix");

        Matrix<N,M,T> array;

        for (size_t n = 0; n < N1; ++n)
        {
            for (size_t m = 0; m < M1; ++m)
            {
                array._array[n][m] = _array[n][m] + rhs._array[n][m];
            }
        }
        return array;
    }

    template<std::size_t N1, std::size_t M1, typename T1>
    auto operator*(Matrix<N1, M1, T1>& rhs)
    {

        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        static_assert(!(N!=M1), "Number of rows from first matrix must be equal to number of columns from second");

        Matrix<N, M1, T> array;
        for (std::size_t n = 0; n < N; ++n) {
            for (std::size_t m = 0; m < M1; ++m) {
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

    template<std::size_t N1, std::size_t M1, typename T1> // zeby moc sie dostac do tablicy z rhs
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
////////////////////////////////////////
int main()
{
    std::srand(std::time(nullptr));
    Matrix<5,5,int> matrix1;
    Matrix<5,5,int> matrix2;
    Matrix<5,5,int> matrix3 = matrix1;
    int scalar = 10;

    std::cout << "pierwszy matrix" << std::endl;
    matrix1.display();

    std::cout << "drugi matrix" << std::endl;
    matrix2.display();

    std::cout << "trzeci matrix" << std::endl;
    matrix3.display();

    std::cout << "skalar: " << scalar << std::endl;

    auto product = matrix1 + matrix2;
    std::cout << "dodawanie matrix" << std::endl;
    product.display();

    auto product1 = matrix1 * matrix2;
    std::cout << "mnozenie matrix" << std::endl;
    product1.display();

    auto product2 = matrix1 + scalar;
    std::cout << "dodawanie skalar" << std::endl;
    product2.display();

    auto product3 = matrix1 * scalar;
    std::cout << "mnozenie skalar" << std::endl;
    product3.display();

    return 0;
}