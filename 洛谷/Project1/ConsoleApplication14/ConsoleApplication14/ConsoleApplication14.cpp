#include<stdio.h>
int main()
{
	int a, b, c, temp;
	scanf_s("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	if (a + b > c)
	{
		if ((a * a + b * b) == c * c)
		{
			printf("Right triangle\n");
		}
		else if ((a * a + b * b) > c * c)
		{
			printf("Acute triangle\n");
		}
		else if ((a * a + b * b) < c * c)
		{
			printf("Obtuse triangle\n");
		}
		if (a == b || b==c || a==c)
		{
			printf("Isosceles triangle\n");
		}
		if (a == b && b == c && a == c)
		{
			printf("Equilateral triangle\n");
		}
	}
	else
	{
		printf("Not triangle\n");
	}
}
