#include<iostream>
#include<string.h>

struct node
{
    int val;
    struct node *next;
};


int main()
{
    // int i = 1;
    // ++i,++i||++i;
    // std::cout<<i;

    // int a[3] = {'A','\0','D'},*p = a;
    // std::cout<<*(p+1);

    // std::cout<<(100,200);

    // char s[5] = {'1','2','3','4','5'};

    // int a[6] = {4,5,6,7,8,9},*p = a,*q = p;

    // char s1[] = {'a','b','c','d'};
    // char s2[] = "abcd";
    // std::cout<<sizeof(s1)<<sizeof(s2)<<std::endl;
    // std::cout<<s1<<s2;

    // struct node sa[3] = {{5},{7},{9}},*sp;
    // sa[0].next = sa+1;
    // sa[1].next = sa+2;
    // sa[2].next = NULL;
    // sp = sa;
    // sp->val++;
    // int ss = sp->val;
    // std::cout<<ss;
    int x = 5,y = 6;
    std::cout<<x--*--y;
}