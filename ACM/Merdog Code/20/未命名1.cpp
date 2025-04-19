#include <stdio.h>
void display(int a[3][3]); 
int main(void)
 {
 	int aa[3][3]={{1,2,3},
	              {1,2,3},
	              {1,2,3}};
	display(aa);              
	return 0;
}
void display(int a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d",a[i][j]);
		}
	}
	return ;
}

