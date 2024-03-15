# include<iostream>
#include <string.h>
int main(){
    const char *st = "how are you";
    char a[11],*p;
    strcpy(p=a+1,&st[4]);
    std::cout<<p<<std::endl;
    std::cout<<st[4]<<'\t'<<&st[4];
}