#include<iostream>
#include <iomanip>

int f(int x[],int n)
{
    if(n!=1)
        x[n] = n + f(x,n-1);
    std::cout<<x[n]<<'\n';
    return x[n];
}
void func(int x,int y)
{
    x = x+y;
    y = x-y;
    x = x-y;
    std::cout<<"Change-> x:"<<x<<"  y:"<<y<<std::endl;
}
int main()
{
    int b[5] = {1,2,3,4,0};
    f(b,3);
    for(int i=0;i<5;i++)
    {
        std::cout<<b[i];
    }
    int x = 3,y = 10;
    std::cout<<"x:"<<x<<"  y:"<<y<<std::endl;
    func(x,y);
    std::cout<<"x:"<<x<<"  y:"<<y<<std::endl;
    char a = 48;
    for(;a<='z';a++)
    {
        std::cout<<a;
    }
}




