# include<iostream>
using namespace std;
class Base
{
    public:
        Base()
        {
            cout<<"Base class"<<endl;
        }
        ~Base()
        {
            cout<<"Destruct Base"<<endl;
        }
};

class Base1
{
    public:
        Base1()
        {
            cout<<"Base1 class"<<endl;
        }
        ~Base1()
        {
            cout<<"Destruct Base1"<<endl;
        }
};

class Level1:public Base1,virtual public Base
{
    public:
        Level1()
        {
            cout<<"Level1 class"<<endl;
        }
        ~Level1()
        {
            cout<<"Destruct Level1"<<endl;
        }
};

class Level2:public Base1,virtual public Base
{
    public:
        Level2()
        {
            cout<<"Level2 class"<<endl;
        }
        ~Level2()
        {
            cout<<"Destruct Level2"<<endl;
        }
};

class topLevel:public Level1,virtual public Level2
{
    public:
        topLevel()
        {
            cout<<"topLevel class"<<endl;
        }
        ~topLevel()
        {
            cout<<"Destruct topLevel"<<endl;
        }
};

int main()
{
    topLevel top;
}