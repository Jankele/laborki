#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <array>
#include <list>

void findVector()
{
	int find = 500000;
	std::vector<int> data;
	for (int i = 0; i < 1000000; ++i)
	{
		data.push_back(i);
	}

	auto start = std::chrono::system_clock::now();
////////////////////////////////////////////////////////
	for(const auto &i : data)
	{
		if(i == find){}
	}
////////////////////////////////////////////////////////
	auto  end = std::chrono::system_clock::now();
	auto diff = end - start;
	std::cout << diff.count() << std::endl;
}

void insertVector()
{
	int insert = 500000;
	int j = 0;

	std::vector<int> data;
	for (int i = 0; i < 1000000; ++i)
	{
		data.push_back(i);
	}
	std::vector<int>::iterator it = data.begin();
	std::advance(it,499999);
	auto start = std::chrono::system_clock::now();
////////////////////////////////////////////////////////
	*it = 500000;
////////////////////////////////////////////////////////
	auto  end = std::chrono::system_clock::now();
	auto diff = end - start;
	std::cout << diff.count() << std::endl;
}

void findList()
{
	int find = 500000;
	std::list<int> data;
	for (int i = 0; i < 1000000; ++i)
	{
		data.push_back(i);
	}

	auto start = std::chrono::system_clock::now();
/////////////////////////////////////////////////////////
	for(const auto &i : data)
	{
		if(i == find){}
	}
////////////////////////////////////////////////////////
	auto  end = std::chrono::system_clock::now();
	auto diff = end - start;
	std::cout << diff.count() << std::endl;
}

void insertList()
{
	int insert = 500000;
	int j = 0;
	std::list<int> data;
	for (int i = 0; i < 1000000; ++i)
	{
		data.push_back(i);
	}
	std::list<int>::iterator it = data.begin();
	std::advance(it,499999);
	auto start = std::chrono::system_clock::now();
////////////////////////////////////////////////////////
	*it = 500000;
////////////////////////////////////////////////////////
	auto  end = std::chrono::system_clock::now();
	auto diff = end - start;
	std::cout << diff.count() << std::endl;
}

int main()
{
	std::cout << "Czas przeszukania wektora: " << std::endl;
	findVector();
	std::cout << "Czas przeszukania listy: " << std::endl;
	findList();
	std::cout << "Czas wrzucenia do wektora: " << std::endl;
	insertVector();
	std::cout << "Czas wrzucenia do listy: " << std::endl;
	insertList();

	return 0;
}
