#include<stdio.h>
int main(void)
{
    int n,a=2,i=1,sum=0;
    scanf("%d",&n);
    while(i<=n)
    {
    	a=a*a;
    	i+=1;
    	sum=a+sum;
	}
	printf("%d",sum); 
}
