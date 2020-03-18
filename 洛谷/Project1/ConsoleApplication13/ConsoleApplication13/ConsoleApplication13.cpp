#include <stdio.h>
#include <string.h>
bool is_prime(int x)
{
	if (x % 2 == 0)
		return false;
	for (int k = 2; k * k <= x; k++)
		if (x % k == 0) 
			return false;
	return true;
}
int main()
{
	int i, num, n, t = 0, temp, Num;
	scanf_s("%d%d", &Num, &num);
	for (i = Num; i <= num && i <= 9989899; i++)
	{
		temp = i;
		n = 0;
		while (temp > 0)
		{
			n = n * 10 + temp % 10;
			if (n == temp)
			{
				if(is_prime(i))
					printf("%d\n", i);
				break;
			}
			temp /= 10;
			if (n == temp)
			{
				if(is_prime(i))
					printf("%d\n", i);
				break;
			}
		}
	}
}