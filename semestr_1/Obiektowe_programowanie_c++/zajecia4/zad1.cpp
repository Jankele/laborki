#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	string help = "help of this program";
	const std::vector<std::string> args {argv +1, argv + argc};
	for(const std::string& arg : args)
	{
		if(arg == "-h"){
			cout << help << endl;
			return 0;}
		else if(arg == "-v"){
			for(const std::string& arg : args)
				cout << arg << endl;
			return 0;}
		else{
			int position = arg.find("-f=");
			std::string subStr = arg.substr(position+3, arg.size());
			int number = std::atoi(subStr.c_str());
			cout << number * number << endl;
			return 0;
		}
	}
	
}