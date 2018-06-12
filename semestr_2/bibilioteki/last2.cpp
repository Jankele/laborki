#include <vector>
#include <memory>
#include <iostream>

int main()
{
	std::vector<int> _v = {1,2,3,4,5,6,7,8,9,10};
	std::function<void(int)>;
	int N = 5;
	std::find_if(_v.begin(), _v.end, [](int val){return val > N});
	
}