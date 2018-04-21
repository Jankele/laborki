#include <iostream>
#include <vector>
#include <cstdlib>

//random access iterator
void fun()
{
	std::vector<int> w = {1,2,3,4,5,6,7};
	for(int i=0;i<w.size();i++)
		std::cout << *(w.begin() + i) << std::endl;
}

//distance, advance
void fun2()
{
	std::size_t t;
	int i = 0;
	int value = 5;
	std::vector<int> w = {1,2,3,4,5,6,7};
	auto wb = w.begin();

	while(*wb != value)
	{
		t = std::advance(wb,i);
		++i;	
	}
}

//std::list
void fun3()
{
	std::list<int> lista = {1,2,3,4};
	auto bi = std::back_inserter(lista);
	auto fi = std::front_inserter(lista);
	for(int i=1;i<4;i++)
		bi = i;
	fi = 
}

struct  f
int main()
{
	fun();
	fun2();
		return 0; 
}