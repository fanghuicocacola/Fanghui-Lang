# include<iostream>

class A
{
    public:
        void showA()
        {
            std::cout<<"A.show()"<<std::endl;
        }
};

class a:protected A
{
    public:
        void showa()
        {
            std::cout<<"a.show()"<<std::endl;
        }
};

int main()
{
    A x1;
    x1.showA();
    a x2;
    x2.showa();
    // x2.showA() 函数 "A::showA" (已声明 所在行数:6) 不可访问C/C++(265

}