#include <array>
#include <functional>
#include <algorithm>

struct Complex
{
    int _re;
    int _img;
};

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex tmp;
    tmp._re = lhs._re + rhs._re;
    tmp._img = lhs._img + rhs._img;
    return tmp;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex tmp;
    tmp._re = lhs._re * rhs._re;
    tmp._img = lhs._img * rhs._img;
    return tmp;
}

template<std::size_t N, std::size_t M, typename T>
class Matrix
{
//using std::array because it gets fixed size at compile time
    std::array<std::array<T, M>, N> _array{};
public:
//default ctor
    Matrix() 
    {
        static_assert(!(N == 0 || M == 0),"Matrix's size cannot equal zero");
        static_assert(!std::is_same <T, bool>::value, "Matrix cannot be of type bool");
/*
*   checking if type of matrix is bool
*   matrix cannot be of type bool because
*   it would only get values 1 and 0
*/
    }

//copy ctor
    template<std::size_t N1, std::size_t M1, typename T1>
    Matrix(
        const Matrix<N1, M1, T1>& other) 
    {
        static_assert(!(N1 != N || M1 != M), "Both matrices must have the same size");
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        _array = other;
    }
//operator [] needed for getting index from objects _array
    std::array<T, M> &operator[](std::size_t index)
    {
        return _array.at(index);
    }

    const std::array<T, M> &operator[](std::size_t index) const
    {
        return _array.at(index);
    }
/*
*   operator + for (matrix + scalar)
*   scalar cannot be added to matrix by default
*   so identity matrix filled with scalar's value
*   need to be created and then summed with lhs matrix
*/
    template<typename T1>
    auto operator+(
        const T1 &rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        Matrix<N,M,T> array;
        Matrix<N,M,T1> identityMatrix;
        for (auto &i : identityMatrix._array)
            std::fill(i.begin(),i.end(), rhs);
//cannot use range for below because need to use same index of two different arrays
            for (std::size_t n=0; n<N; ++n)
            {
//sum two values with std::transform/std::plus combo
                std::transform(_array[n].begin(), _array[n].end(), identityMatrix._array[n].begin(), array._array[n].begin(), std::plus<T1>());
            }
        return array;
    }
//operator * for (matrix * scalar)
    template<typename T1>
    auto operator*(
        const T1 &rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        Matrix<N,M,T> array;
        Matrix<N,M,T1> identityMatrix;
        for (auto &i : identityMatrix._array)
            std::fill(i.begin(),i.end(), rhs);
        for (std::size_t n=0; n<N; ++n)
        {
//multiply two values with std::transform
            std::transform(_array[n].begin(), _array[n].end(), identityMatrix._array[n].begin(), array._array[n].begin(), [](T f, T1 s){return f*s;});
        }
        return array;

    }
//operator + for (matrix + matrix)
    template<std::size_t N1, std::size_t M1, typename T1>
    auto operator+(
        Matrix<N1, M1, T1>& rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        static_assert(!(N1 != N || M1 != M), "Second matrix must be the same size as first matrix");

        Matrix<N,M,T> array;

//cannot use range based for below because it's needed to use the same index of two different arrays
            for (std::size_t n=0; n<N; ++n)
            {
//add two values with std::transform/std::plus
                std::transform(_array[n].begin(), _array[n].end(), rhs._array[n].begin(), array._array[n].begin(), std::plus<T1>());
            }
        return array;
    }
//operator * for (matrix * matrix)
    template<std::size_t N1, std::size_t M1, typename T1>
    auto operator*(
        Matrix<N1, M1, T1>& rhs)
    {
        static_assert(std::is_convertible<T, T1>::value, "Values are not convertible");
        static_assert(!(N!=M1), "Number of rows from first matrix must be equal to number of columns from second");

        Matrix<N, M1, T> array;
        for (std::size_t n=0; n<N; ++n) {
            for (std::size_t m=0; m<M1; ++m) {
                T sum = 0;
                for (std::size_t i=0; i<N1; ++i) {
                    sum += _array[n][i] * rhs._array[i][m];
                }
                array._array[n][m] = sum;
            }
        }
        return array;
    }
//friending class so it can have access to array from rhs object
    template<std::size_t N1, std::size_t M1, typename T1>
      friend class Matrix;

      void fillStruct(auto a)
      {
        static_assert(std::is_same <T, Complex>::value, "Matrix cannot be of type different than Complex");
            for (std::size_t i=0;i<N;i++)
            {
                for(std::size_t j=0;j<M;j++)
                {
                    _array[i][j] = {a,a};
                }
            }
        }
};