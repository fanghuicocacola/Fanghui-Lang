#include <iostream>


int ff(int A)
{
	int temp, a = 0;
	while (A != 0)
	{
		temp = A % 10;
		a = a * 10 + temp;
		A = A / 10;
	}
	return a;
}
int main()
{
	int a, b, n = 0;
	long ans;
	while (scanf_s("%d%d", &a, &b))
	{
		a = ff(a);
		b = ff(b);
		ans = a * b;
		ans = ff(ans);
		printf("%d\n", ans);
	}
}
