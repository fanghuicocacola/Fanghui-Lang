#include<stdio.h>
#include<string.h>
void px1()
{
	int i, a[10];
	int max1, max2;
	printf("输入10个数:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d ", &a[i]);
	}
	max1 = max2 = a[0];
	for (i = 1; i < 10; i++)
	{
		if (max1 < a[i])
		{
			max2 = max1;
			max1 = a[i];
		}
		else if (max2 < a[i])
		{
			max2 = a[i];
		}
	}
	printf("%d",max2);
}
int main()
{
	px1( );
}