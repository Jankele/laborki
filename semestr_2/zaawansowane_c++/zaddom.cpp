#include <iostream>
#include <vector>

template < size_t n, size_t m, typename T >
class Matrix
{
	T data[n][m];
public:
	Matrix()
	{
		if(n == 0 || m == 0)
			throw std""underflow_error { "asdas" };;
			for(int i=0;int<n;i++)
				for(int i=0;int<m;i++)
					data[i][j] = j+1;
	}
	Matrix(const Matrix<n1, m1, T1>& _data)
	{
		for(int i=0;int<n1;i++)
			for(int i=0;int<m1;i++)
				_data[i][j] = data[i][j];
	}
    Matrix<n, m, T>& operator+(const Matrix<n, m, T>& rhs)
    {
		for(int i=0;int<n;i++)
			for(int i=0;int<m;i++)
				data[i][j] += rhs[i][j];
    }

    Matrix<n, m, T>& operator<<(const Matrix<n, m, T>& rhs)
    {
//10 slajd ostream...
    }

    Matrix<n, m, T>& operator()(const auto n)
    {
    	return data.at(n);
    }
};

int main()
{

}

//bool decltype
//meta-programowanie to potega :)
//