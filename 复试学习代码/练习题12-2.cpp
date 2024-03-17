# include<iostream>

class A 
{
    public:
        void func()
        {
            std::cout<<"Create A";
        }
};

class B
{
    public:
        void func()
        {
            std::cout<<"Create B";
        }
};


int main()
{
    A a;
    B b;
    a.func();
    b.func();
}

