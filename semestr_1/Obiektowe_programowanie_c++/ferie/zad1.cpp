#include <iostream>

int foo(int a)
{
		return (a==0) ? 1:(a * (foo(a-1)));
}

int main()
{
	int	a = foo(5);
	std::cout << a << std::endl;
	return 0;
}