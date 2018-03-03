#include <iostream>
#include <vector>
#include <cmath>
#include <chrono> 

typedef struct big
{
	std::array<float, 1024 *1024> _data
}big;

int main()
{
	auto start = std::chrono::system_clock::now();
	big b;
	
	std::vector <auto> w;
	std::list <auto> l;

	int i = 1000000;
	float j = 1000000;
	while(i > 0)
	{
		w.push_back(i);
		w.push_back(j);
		w.push_back(big);
		--i;
		--j;
	}

	auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::cout << elapsed.count() << '\n';
	
}