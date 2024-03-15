#include <stdio.h>
#include <iostream>
int main() {
	int i, j, n, k = 1;
	double s = 0;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
			k *= j;
		s += 1.0 / k;
		k = 1;
	}
	printf("S=%lf", s);
	return 0;
}