#include<stdio.h>
int main(void)
{
	int i=1,j,p,sum=1;
	while(i<=101)
	{
		j=1;
		p=1;
		while(j<=i)
		{
			p+=2;
			j+=1;
		}
		sum=sum+p;
		i++;
	}
	printf("sum=%d",sum);
	return 0;
}
