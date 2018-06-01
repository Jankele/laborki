#include <iostream>
#include <ios>
#include <istream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cin.exceptions(std::ios::badbit | std::ios::failbit);

	try
	{
		double x;
		std::cin << x;
	}
	catch(const std::exception& ex)
	{
		std::cerr << error << ex.what() << "type" << typeid(ex).name() << std::endl;
	}
	return 0;
}