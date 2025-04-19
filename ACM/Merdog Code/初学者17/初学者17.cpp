#include<stdio.h>
int main(void)
{
	int n;
	int i=1;
	long p=1;
	printf("please enter n");
	scanf("%d",&n);
	do
	{
		p=p*i;
		i+=1;
	}
	while(i<=n);
	printf("%d!=%1d\n",n,p);
	return 0;
}
