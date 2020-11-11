
#include <iostream>


int main()
{ 
	int i,j;
	int n; 
	double temp; 
	double sum1 = 1, sum2 = 1;
	printf("n:\n"); 
	scanf_s("%d", &n); 
	for (i = 1; i <= n; i++) 
	{ 
		for (j = 1; j <= i; j++) 
		{
			sum1 *= 1.0*j;
			
		}
		
		temp = 1.0 / sum1; 
		sum2 += temp;
		sum1 = 1;
	} 
	printf("%Lf\n",sum2);
	
}
