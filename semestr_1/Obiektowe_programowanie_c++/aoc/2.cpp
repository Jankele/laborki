#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	srand( time( NULL ) );
	std::vector < std::vector <int> > input(std::rand()%(5+1-2)+2);
	int max = 0, min = 0, suma = 0;
	for(auto &i : input)
	{
		std::vector <int> tmp;
		for(int j=0;j<=std::rand()%(5+1-2)+2;j++)
			tmp.push_back(std::rand()%(9+1-1)+1);
		i = tmp;
	}

	for(auto const &i : input)
	{
		for(int j=0;j<i.size();j++)
			std::cout << i[j] << " ";
			std::cout << std::endl;
	}

	for(auto const &i : input)
	{
		max = i[0];
		min = i[0];
		for(int j=0;j<i.size()-1;j++)
			{
				if(max < i[j+1])
					max = i[j+1];
				if(min > i[j+1])
					min = i[j+1];
				
			}
			suma += max - min;
	}
	std::cout << suma << std::endl;
	return 0;
}