#include <iostream>
#include <ios>
#include <istream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

struct Employee
{
	std::string a;
	friend std::ostream& operator<< (std::ostream& stream, const Employee& e);
};

	std::ostream& operator<< (std::ostream& stream, const Employee& e)
	{
   		stream << e.a;
		return stream;
	}

int main()
{
	struct Employee a;
	std::stringstream ss;
	ss << Employee{};

	return 0;
}//