#include <iostream>
#include <vector>
#include <algorithm>

struct Dictionary
{
	std::std::vector<std::string> v;

	void addWord(std::string &a)
	{
		a.toLowerCase();
		v.push_back(a);
	}
	void removeWord(const std::string &a)
	{
		int pos = std::find(v.begin(), v.end(), a);
		if(pos != v.end())
			v.erase(pos);
	}
	bool check(const std::string &a)
	{
		if (std::find(v.begin(), v.end(), a) != v.end())
			return true
		else
			return false
	}
};

int main()
{

}