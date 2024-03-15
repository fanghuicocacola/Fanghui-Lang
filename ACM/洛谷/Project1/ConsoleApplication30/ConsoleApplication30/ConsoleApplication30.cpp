#include <stdio.h>

int main()
{
	int n, s, sum = 0, zj[7] = { 0,0,0,0,0,0,0 }, c[7];
	int i, j, k;
	scanf_s("%d", &n);
	for (i = 0; i < 7; i++)
	{
		scanf_s("%d", &c[i]);
	}
	for (i = 0; i < n; i++)
	{
		for(j = 0;  j < 7; j++)
		{
			scanf_s("%d", &s);
			for(k = 0; k < 7; k++)
			{
				if (s == c[k])
				{
					sum++;
				}
			}
		}
		if (sum != 0)
		{
			zj[7-sum]++;
			sum = 0;
		}
	}
	for ( i = 0; i < 7; i++)
	{
		printf_s("%d ", zj[i]);
	}
}

