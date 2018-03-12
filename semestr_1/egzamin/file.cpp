#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//#include "file.h"

int main(int argc, char* argv[])
{
	std::string str;
	std::fstream fd;
	fd.open("tekst.txt", std::ios::out | std::ios::in);
	std::getline(fd, str);
	std::cout << str << std::endl;
	fd << "asdasdasdasd" << std::endl;
	fd.close();
}