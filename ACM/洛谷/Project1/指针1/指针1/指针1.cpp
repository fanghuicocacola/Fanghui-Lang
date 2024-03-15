#include<stdio.h>
int main()
{
	int a[3], i, j, temp, k;
	printf("输入三个数:");
	scanf_s("%d %d %d", &a[0], &a[1], &a[2]);
	for (i = 1; i < 3; i++)
		for (j = 0; j < i; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	for (k = 0; k < 3; k++)
	{
		printf("%d ", *(a+k));
	}
	printf("\n");
	return 0;
}


