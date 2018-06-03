#include <array>

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

        for (std::size_t n=0; n<N1; ++n)
        {
            for (std::size_t m=0; m<M1; ++m)
            {
                _array[n][m] = other[n][m];
            }
        }
    }
//operator [] needed for getting index from objects _array
    std::array<T, M> &operator[](std::size_t index)
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
            i.fill(rhs);
        for (std::size_t n=0; n<N; ++n)
        {
            for (std::size_t m=0; m<M; ++m)
            {
                array._array[n][m] = _array[n][m] + identityMatrix._array[n][m];
            }
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

        for (std::size_t n=0; n<N; ++n)
        {
            for (std::size_t m=0; m<M; ++m)
            {
                array._array[n][m] = _array[n][m] * rhs;
            }
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

        for (std::size_t n=0; n<N1; ++n)
        {
            for (std::size_t m=0; m<M1; ++m)
            {
                array._array[n][m] = _array[n][m] + rhs._array[n][m];
            }
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
};