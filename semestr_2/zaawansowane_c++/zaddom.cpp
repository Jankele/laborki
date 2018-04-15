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
			throw 1;
			for(int i=0;int<n;i++)
				for(int i=0;int<m;i++)
					data[i][j] = j+1;
	}
	Matrix(const Matrix<n, m, T>& _data)
	{
		for(int i=0;int<n;i++)
			for(int i=0;int<m;i++)
				_data[i][j] = data[i][j];
	}
    Matrix<n, m, T>& operator+(const Matrix<n, m, T>& rhs)
    {
    	T temp[n][m];
		for(int i=0;int<n;i++)
			for(int i=0;int<m;i++)
				temp[i][j] = data[i][j] + rhs[i][j];
		return temp;
    }

    Matrix<n, m, T>& operator<<(const Matrix<n, m, T>& rhs)
    {

    }

    Matrix<n, m, T>& operator()(const auto n, const auto m)
    {
    	return at(data[n][m];
    }
};

int main()
{

}

//bool decltype