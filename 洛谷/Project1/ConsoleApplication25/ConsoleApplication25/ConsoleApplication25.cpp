#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int y[10];
int jc(int n)
{
	if (n == 1)
		return 1;
	else
		return n * jc(n - 1);
}
void find(int x)
{
	memset(y, 0, sizeof(y));
	while (x > 9) {
		y[x % 10] += 1;
		x /= 10;
	}
	y[x % 10] += 1;
}
int main()
{
	int t, n, a, c, num;
	num = 0;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%d %d", &n, &a);
		c = jc(n);
		find(c);
		printf("%d", y[a]);
	}
}




