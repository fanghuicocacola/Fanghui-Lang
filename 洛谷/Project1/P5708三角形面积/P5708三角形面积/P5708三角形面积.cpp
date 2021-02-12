#include <iostream>
#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c, p, s;
	scanf_s("%lf %lf %lf", &a, &b, &c);
	p = (a + b + c) / 2;
	s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf", s);
}