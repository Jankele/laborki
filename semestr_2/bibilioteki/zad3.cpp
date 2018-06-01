#include <iostream>
#include <ios>
#include <istream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::vector<std::uint8_t> v;
	std::uint8_t a = 244;
	v.push_back(a);
	for(auto a : v)
		std::cout << std::showbase << std::hex << static_cast<int>(a) << std::endl;
	std::cout << 23 << std::endl;
	return 0;
}//