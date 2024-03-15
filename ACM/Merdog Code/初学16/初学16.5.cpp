#include<stdio.h>
int main(void)
{
	int i=1,j,p=1,sum=1;
	while(i<=10)
	{
		p=1;
		j=1;
		while(j<=i)
		{
			j+=1;
			p=p*j; 
		}
		sum=sum+p;
		i+=1;
	}
	printf("sum=%d",sum);
	return 0;
}
