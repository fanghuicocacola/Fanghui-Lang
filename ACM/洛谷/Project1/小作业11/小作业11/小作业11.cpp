#include<stdio.h>
int f(int x) 
{
    int i;
    bool prime = false;    
    while (prime == false)
    {
        for (i = 2; i < x; i++)
        {            
            if (x % i == 0) //==0，就不是素数了            
            {
                prime = false;
                break;
            }
            else
                prime = true;
        }
        if (prime == true)
            return x;
        else
        {
            x++;    
        }
    }
}
int main()
{
    int a;
    scanf_s("%d", &a);
    a = f(a);
    printf("%d", a);
}



