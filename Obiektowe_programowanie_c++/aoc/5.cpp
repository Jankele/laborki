#include <iostream>
#include <vector>

int main()
{
	int score = 0, position = 0, jump;
	std::vector<int> input = { 1,-1,2,-5,2 };
	while(position < input.size())
	{
		jump = input[position];
		input[position] += 1;
		position += jump;
		score++;
	}
	std::cout << "Exit found after " << score << " jumps." << std::endl;
	return 0;
}