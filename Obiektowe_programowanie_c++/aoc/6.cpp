#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	std::vector <int> input = {0,2,7,0};
	std::vector <std::string> ciagi;
	int max = input[0], pozycja;
	int a = 0;
	std::string wzor;
	std::string znak;
	while(a<20)
	{
		for(int i=0;i<input.size();i++)
		{
			if(max < input[i])
			{
				max = input[i];
				pozycja = i;
			}
		}
		input[pozycja] -= input.size() - 2;
		for(int &i : input)
			i += 1;

		for(int const &i : input)
		{
			znak = std::to_string(i);
			wzor += znak;
		}

		ciagi.push_back(wzor);
		wzor.clear();

		for(int i=0;i<ciagi.size();i++)
		{
			for(int j=i+1;j<ciagi.size();j++)
			{
				if(ciagi[i] == ciagi[j])
					a = false;
			}
		}
		a++;
	}
	for(std::string const &i : ciagi)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << wzor << std::endl;
	return 0;
}