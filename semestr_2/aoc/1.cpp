#include <iostream>
#include <vector>

int main()
{
	std::vector<int> input = { 1,2,3,4 };
	int suma = 0;

	if(input[0] == input[input.size() - 1])
		suma += input[0];

	for(int i=0;i<input.size() - 1;i++)
	{
			if(input[i] == input[i+1])
				suma += input[i];
	}

	std::cout << suma << std::endl;
	return 0;
}
