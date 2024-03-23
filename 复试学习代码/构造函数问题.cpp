#include<iostream>
class A
{
    int x;
    public:
        A(int x=0)
        {
            this->x=x;
            std::cout<<x<<"\tcome"<<std::endl;
        }
        ~A()
        {
            std::cout<<x<<"\tgo"<<std::endl;
        }
};
class B:virtual public A
{
    A a;
    int y;
    public:
        B(int x,int y=1):a(x)
        {
            this->y = y;
            std::cout<<y<<"\tcome"<<std::endl;
        }
        ~B()
        {
            std::cout<<y<<"\tgo"<<std::endl;
        }
};

int main()
{
    A *pa = new B(10,20);
    delete pa;
}