#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bits/stdc++.h>

bool pred(int i, int j)
{
    return (i != j);
}

void foo(std::vector<std::string> & _v)
{
	std::string a = "a";
	std::generate(_v.begin(), _v.end(), [&a](){return a;});
}

auto imsomean(std::vector<int> v)
{
	int suma = 0;
	for_each(v.begin(), v.end(), [&suma](int & value){ suma += value; });
	return (static_cast<double>(suma) / static_cast<double>(v.size()));
}

//bool IsOdd (int i) { return ((i%2)==1); }

/*auto odd(std::vector<int> v)
{	

	return count_if(v.begin(), v.end(), IsOdd);
}*/

int funkcja(std::vector<int> wektor)
{
	
}

int main()
{
	std::vector<std::string> v;
	std::vector<int> vv = {22,2,3,4};
	std::list<int> vl = {22,2,3,4};
	if(std::equal(vv.begin(), vv.end(), vl.begin(), pred))
		std::cout << "a" << std::endl;
	else
		std::cout << "b" << std::endl;

	v.resize(10);
	//foo(v);
	std::string s = "abcd";
	for_each(s.begin(), s.end(), [](char & value){value = std::toupper(value);});
	//for_each(s.begin(), s.end(), [](char const& value){std::cout << value << std::endl;});
	//std::cout << imsomean(vv) << std::endl;
	//std::vector<int> temp = odd(vv);
	//for_each(temp.begin(), temp.end(), [](int const& value){std::cout << value << std::endl;});
	int a = *(std::min_element(vv.begin(), vv.end()));
	std::cout << a << std::endl;
	return 0;
}