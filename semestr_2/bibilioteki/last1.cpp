#include <vector>
#include <memory>
#include <iostream>

int main()
{
	std::vector<int> _v = {1,2,3,4,5,6,7,8,9,10};
	std::vector<std::unique_ptr<int> _p;

	std::transform(_v.begin(), _v.end(), std::back_inserter(_p), [](const auto& v){
		return std::make_unique<int>(v);
	});
            }

    for (auto& v : _p)
    {
        std::cout << *v << std::endl;
    }
}