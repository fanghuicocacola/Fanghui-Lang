#include<iostream>
#include<stdio.h>
# include<string.h>
# include<iomanip>
# define M 6
# define NUM 21
int main(){
    int a[NUM],*p[M],i,j,add;
    for(i=0;i<M;i++)
    {
        add=i*(i+1)/2;
        p[i]=&a[add];
    }
    for(i=0;i<M;i++)
    {
        p[i][0]=1;
        p[i][i]=1;
    }
    for (i = 2; i < M; i++)
    {
        for (j = 1; j < i; j++)
        {
            p[i][j] = p[i-1][j-1] + p[i-1][j];
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j <= i; j++)
        {
            std::cout<<std::setw(4)<<p[i][j];
        }
        std::cout<<std::endl;
    } 
}