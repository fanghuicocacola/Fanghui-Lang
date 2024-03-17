# include<iostream>
#include <math.h>

class Rational
{
    private:
        int X,Y; //X为分子，Y为分母
    public:
        Rational(int xx = 1,int yy = 1)
        {
            if(xx<yy)
            {
                for(int i = 1;i <= xx;i++)
                {
                    if(xx%i == 0 && yy%i==0)
                    {
                        xx /= i;
                        yy /= i;
                        i = 1;
                    }
                }
            }
            else
            {
                for(int i = 1;i <= yy;i++)
                {
                    if(xx%i == 0 && yy%i==0)
                    {
                        xx /= i;
                        yy /= i;
                        i = 1;
                    }
                }
            }
            std::cout<<xx<<std::endl;
            std::cout<<yy<<std::endl;
            X = xx;
            Y = yy;
        }
        void Show1();
        void Show2();
        void Add(int X1,int Y1);
        void Sub(int X1,int Y1);
        void Mul(int X1,int Y1);
        void Div(int X1,int Y1);
};

void Rational::Show1()
{
    std::cout<<X<<"/"<<Y<<std::endl;
}
void Rational::Show2()
{
    std::cout<<float(X)/float(Y)<<std::endl;
}

void Rational::Add(int X1,int Y1)
{
    int xx = X*Y1+X1*Y,yy = Y*Y1;
    if(xx<yy)
    {
        for(int i = 1;i <= xx;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    else
    {
        for(int i = 1;i <= yy;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    X = xx;
    Y = yy;
}
void Rational::Sub(int X1,int Y1)
{
    int xx = X*Y1-X1*Y,yy = Y*Y1;
    if(xx<yy)
    {
        for(int i = 1;i <= xx;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    else
    {
        for(int i = 1;i <= yy;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    X = xx;
    Y = yy;  
}
void Rational::Mul(int X1,int Y1)
{
        int xx = X*X1,yy = Y*Y1;
    if(xx<yy)
    {
        for(int i = 1;i <= xx;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    else
    {
        for(int i = 1;i <= yy;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    X = xx;
    Y = yy;
}
void Rational::Div(int X1,int Y1)
{
        int xx = X*Y1,yy = Y*X1;
    if(xx<yy)
    {
        for(int i = 1;i <= xx;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    else
    {
        for(int i = 1;i <= yy;i++)
        {
            if(xx%i == 0 && yy%i==0)
            {
                xx /= i;
                yy /= i;
                i = 1;
            }
        }
    }
    X = xx;
    Y = yy;
}
int main()
{
    Rational R(21,27);
    R.Show1(),R.Show2();
    R.Add(1,1),R.Show1();
    R.Sub(1,1),R.Show1();
    R.Mul(2,7),R.Show1();
    R.Div(2,7),R.Show1();
}

