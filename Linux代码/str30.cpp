#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void str30()
{
	//2 to 10
	char a[10],b[10];
	fgets(a,9,stdin);
	fgets(b, 9, stdin);
	int len, i, sum1 = 0, sum2 = 0, sum = 0, m, j;
	len = strlen(a)-1;
	if (len <= 9)
	{
		for (i = 0; i < len; i++)
		{
			m = 1;
			if (a[i] == '1')
			{
				for (j = 1; j <= len - i - 1; j++)
					m *= 2;
				sum1 += m;
			}
		}
	}
	len = strlen(b) - 1;
	if (len <= 9)
	{
		for (i = 0; i < len; i++)
		{
			m = 1;
			if (b[i] == '1')
			{
				for (j = 1; j <= len - i - 1; j++)
					m *= 2;
				sum2 += m;
			}
		}
	}
	sum = sum1 + sum2; 
	i = 1;
	long long num = 0;
	int rem, step = 1;

	while (sum != 0)
	{
		rem = sum % 2;
		step++;
		sum / 2;
		sum /= 2;
		num += long long(rem * i);
		i *= 10;
	}
	printf("%lld", num);
}
int main()
{
	str30();
}