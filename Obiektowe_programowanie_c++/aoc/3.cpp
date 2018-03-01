#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

int liczba = std::rand()%300000;
const int rozmiar = sqrt(liczba) + 1;


int wyswietl(int (&tab)[rozmiar][rozmiar])
{
	for(int i=0;i<rozmiar;i++)
	{
		for(int j=0;j<rozmiar;j++)
		{
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int main()
{
	srand ( time(NULL));

	std::array<std::array<int, rozmiar>, rozmiar> tab;
	
	wypelnij(tab);
	wyswietl(tab);



	return 0;
}