#include <iostream>
int main() 
{
	unsigned n, m;
	long double a = 0.0;
	while (scanf_s("%d%d", &n, &m) != EOF)
	{
		a = 0.0;
		for (; n <= m; n++)
			a += 1.0 / n / n;
		printf("%.5Lf\n", a);
	}
	return 0;
}
int main2()
{
	int n;
	float sum = 0.0;
	while (scanf_s("%d",&n) != EOF)
	{
		sum = 0.0;
		for(int i = 1; i <= n; i++)
		{
			sum += 1.0 / i;
		}
		printf("%.3f\n", sum);
		
	}
	return 0;
}