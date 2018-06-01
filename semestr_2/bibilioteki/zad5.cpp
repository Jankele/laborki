#include <iostream>
#include <ios>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
	std::fstream myfile{argv[1]};
	std::string temp;
	if(argv[1] == NULL)
		while(true)
		{
			std::cin >> temp;
			std::cout << temp << std::endl;	
		}
	if(!myfile.is_open())
	{
		std::cout << "nie ma takiego pliku ani katalogu" << std::endl;
		return 0;
	}
	std::string s;
 	while (std::getline(myfile, s)) std::cout << s << std::endl;
}

ring buffer -- przeladowac begin end z deque