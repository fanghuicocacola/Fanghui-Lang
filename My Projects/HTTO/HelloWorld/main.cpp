#include <iostream>
#include <string>
int main()
{
	int64_t i = 0;
	int64_t result = 1;
	while (i < 15)
	{
		i++;
		result *= i;
	}
	std::cout << result;
	std::cin.get();
	return 0;
}