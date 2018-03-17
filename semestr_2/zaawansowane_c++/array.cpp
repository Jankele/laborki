#include <iostream>
#include <array>
#include <vector>



template<int N, bool B,  typename T>
auto getArray(T t)
{
	return CustomArray<N, B, T> {};
}

int main()
{
	getArray<10, true> (100);
}
