#include <stdio.h>
int main(void)
{
	int a,b, i = 1;
	double sum;
	char ch;
	scanf_s("%d", &a);
	while (1)
	{
		i = i + 1;
		
		if (i == 2)
			sum = 1.0 * a;
		ch = getchar();
		if (ch == '+') {
			scanf_s("%d", &b);
			sum = sum + b * 1.0;
		}
		else if (ch == '-') {
			scanf_s("%d", &b);
			sum = sum - b * 1.0;
		}
		else if (ch == '*') {
			scanf_s("%d", &b);
			sum = sum * b * 1.0;
			
		}
		else if (ch == '/')
		{
			scanf_s("%d", &b);
			if (b == 0)
			{
				printf("ERROR"); break;
			}
			else {
				sum = sum / b * 1.0;
			}
		}
		else if (ch == '=')
		{
			printf("%.0lf", sum); break;
		}
		else
		{
			printf("ERROR"); break;
		}

	}
	return 0;
}
