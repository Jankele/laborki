#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define N 5

void pobierz(std::vector<int>& v)
{
	int b;
	for(int i=0; i<N; i++)
	{
		std::cout << "podaj liczbe";
		std::cin >> b;
		v[i] = b;
		std::cout << std::endl;
	}
}

void asc_desc(std::vector<int>& v)
{
	if(std::is_sorted(v.begin(), v.end()))
		std::cout << "rosnaco" << std::endl;
	else
		std::cout << "malejaco" << std::endl;
}

int main()
{
	bool aa = true;
	std::vector<int> v;
	v.resize(N);
	pobierz(v);
	for(auto a : v)
	std::cout << a << std::endl;
	asc_desc(v);
	std::boolalpha << aa;
}
/*
std::generate_n(std::back_inserter(vec), N, []() {
	float number;
	std::cin >> number;
	return number;
});
*/