#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
T fun(const std::vector<T> &v)
{
	return *min_element(v.begin(),v.end());
}

int main()
{
	std::cout << fun<int>({20,5,19,33,21,98}) << std::endl;
}