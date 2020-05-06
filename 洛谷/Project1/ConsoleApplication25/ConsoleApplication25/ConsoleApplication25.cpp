#include<stdio.h>

int function(int n)
{
	int i;
	int k = 0;
	for (i = 1; i <= n / 2; i++)
	{
		if (n % i == 0) 
			k += i;

	}

	return k;

}
int main() { 
	int i;
	for (i = 2; i <= 100; i++) 
	{
		if (i == function(i)) 
	{ 
		printf("%d ",i);
	} 
	}	return 0;
} 
