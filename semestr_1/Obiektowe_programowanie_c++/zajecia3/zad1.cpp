#include <iostream>
#include <array>
#include <stdlib.h>

using namespace std;

int main()
{
	int najwieksza = 0;
	array<int, 100> tab;
	for(int& value: tab)
	{
		value = rand()%30;		
	}
	for(const int & value: tab)
	{
		if(value>najwieksza)
			najwieksza=value;
	}
	for(const int & value: tab)
	{
		cout << value << " ";
	}
	cout << endl;
	cout << najwieksza << endl;
}
