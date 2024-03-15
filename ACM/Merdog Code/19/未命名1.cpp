#include<stdio.h>
#include<math.h>
double yunsuan(int x);
int main(void)
{
    int x;
    scanf("%d",&x);
    double i;
    i=yunsuan(x);
    
    printf("%f",i);
    return 0; 
}
double yunsuan(int x)
{
    int y;
     if(x>0)
     {
         y=exp(-x);
     }
     else if(x==0)
     {
         y=1;
     }
     else
     {
         y=-exp(x);
     }
     return y;
}
