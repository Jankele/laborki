#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	std::vector <std::string> wektor;
	std::string tmp;
	std::string tekst = "aa bb cc dd aa";
	std::istringstream iss(tekst);
	bool a = true;
	char spacja = ' ';

	while(std::getline(iss, tmp, spacja))
	{
		wektor.push_back(tmp);
	}
	for(int i=0;i<wektor.size();i++)
	{
		for(int j=i+1;j<wektor.size();j++)
		{
			if(wektor[i] == wektor[j])
				a = false;
		}
	}

	if(a == true)
		std:: cout << "Access Granted" << std::endl;
	else
		std::cout << "Access Denied" << std::endl;

	return 0;
}