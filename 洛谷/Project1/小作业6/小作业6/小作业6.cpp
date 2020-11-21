#include<stdio.h>
int main()
{
	int a, b, c;
	for (a = 0; a < 30; a++) {
		for (b = 0; b < 30; b++)
		{
			c = 30 - a - b;
			if (c > 0 && 3 * a + 2 * b + c == 50)
			{
				printf("男人人数:a=%d\n", a);
				printf("女人人数:b=%d\n", b);
				printf("小孩人数:c=%d\n", c);
			}
		}
	}
}


