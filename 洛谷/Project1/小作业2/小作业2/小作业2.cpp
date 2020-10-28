#include <iostream>

int main1()
{
	int a, b,x,y,z,temp;
	while(scanf_s("%d%d", &a, &b));
	for (int i = a; i < b; i++)
	{
		temp = a;
		x = i / 100;
		y = (i-x*100) / 10;
		z = i % 10;
		if (pow(x, 3) + pow(y, 3) + pow(z, 3) == i)
			printf("%d\n", i);
	}
	return 0;
}
int main2() {
	int n, a, b, c;
	while (~scanf_s("%d%d%d", &a, &b, &c))
	{
		for (n = 10; n < 101; n++) {
			if ((n % 3 == a) && (n % 5 == b) && (n % 7 == c)) {
				printf("%d\n", n);
				break;
			}
		}
		if (n == 101) printf("No answer\n");
	}
	return 0;
}
int main()
{
	int n, sum;
	while (scanf_s("%d", &n) != EOF)
	{
		sum = 1;
		if (n > 1 && n < 30)
			for (int i = 1; i < n; i++)
			{
				sum = (sum + 1) * 2;
			}
		printf("%d\n", sum);
	}
	return 0;
}