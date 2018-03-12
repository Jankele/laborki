#include <iostream>
#include <vector>
#include <cmath>

struct T1 {
    int _i;
};

struct T2{
	int _i;
};

std::vector <int> fun(std::vector <int> &in, int a)
{
	std::vector <int> out;
	for(int const &i : in)
	{
		if(i%2 == 0)
			out.push_back(i);
	}
	for(int &i : out)
		i = std::pow(i, a);
	return out;
}

int main()
{
	std::vector <int> in = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	std::vector <int> wynik;
	wynik = fun(in, 2);
	for(int const &i : in)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int const &i : wynik)
		std::cout << i << " ";
	std::cout << std::endl;

}