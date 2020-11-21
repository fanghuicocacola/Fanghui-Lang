#include<stdio.h>
int main()
{
	int n;
	float t, r = 0, fm = 2, fz = 1;
	scanf_s("%d", &n);
	while (n--)
	{
		r += fm / fz;
		t = fm;
		fm += fz;
		fz = t;
	}
	printf("%.3f", r);
	return 0;
}



