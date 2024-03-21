# include<iostream>
#include <string.h>

class Point
{
    int x,y;
    public:
        Point(int a=0,int b=0)
        {
            x = a;
            y = b;
        }
        int getx()
        {
            return x;
        }
        int gety()
        {
            return y;
        }
        void print()
        {
            std::cout<<'('<<x<<','<<y<<')'<<std::endl;
        }
};

class Rect:public Point
{
    public:
        Point p1,p2;
    public:
        Rect(int tlX,int tlY,int brX,int brY):p1(tlX,tlY),p2(brX,brY)
        {
            std::cout<<"Rectangle is created!"<<std::endl;
        }
        int area()
        {
            int x,y;
            x = (p1.getx() - p2.getx()) > 0 ? (p1.getx() - p2.getx()) : (p2.getx() - p1.getx()); 
            y = (p1.gety() - p2.gety()) > 0 ? (p1.gety() - p2.gety()) : (p2.gety() - p1.gety());
            return x*y;
        }
 
        friend bool operator>(Rect &a,Rect &b)
        {
            return (a.area() - b.area()) > 0 ? 1 : 0;
        }
};


int main()
{
    // Rect a(0,0,6,6),b(0,0,8,8);
    // std::cout<<a.area()<<"\t"<<b.area()<<std::endl;
    // if(b > a)
    //     std::cout<<"b > a"<<std::endl;
    // char c1='a',c2=c1+1;
    // std::cout<<c2;
    // int a = 7,b;
    // float x=5.4;
    // char c=('D'+'a')-'A';
    // b = x+a%3+x/2;
    // std::cout<<b<<'\t'<<c;
    // int a = 100;
    // int *p = &a;

    // char s[] = "abcdefg",ss[] = "ABC";
    // strcpy(s,ss);
    // std::cout<<s;

    // const M = 100;

    char *str1 = "abcd",*str2,str3[10];
    strcpy(str2,str1);
    strcpy(str3,str1);
    std::cout<<str2<<str3;
}