#include<iostream>
#include<string.h>

class Matrix //定义三行四列的矩阵类
{
    public:
        double x[100][100] = {0};
        int m,n;
    public:
        Matrix(int a,int b)
        {
            if(a > 100 || b > 100)
            {
                std::cout<<"Out of bound!";
            }
            m = a;
            n = b;
            std::cout<<"Create !"<<std::endl;
        }
        std::istream friend &operator>>(std::istream &in,Matrix &a)
        {
            double number;
            for(int i = 0;i < a.m;i++)
            {
                for(int j = 0;j < a.n;j++)
                {
                    in>>number;
                    a.x[i][j] = number;
                }
            }
            return in;
        }
        std::ostream friend &operator<<(std::ostream &out,Matrix &a)
        {
            double number;
            for(int i = 0;i < a.m;i++)
            {
                for(int j = 0;j < a.n;j++)
                {
                    number = a.x[i][j];
                    out<<number<<'\t';
                }
                out<<'\n';
            }
            out<<'\n';
            return out;
        }
        Matrix& operator=(const Matrix &a)
        {
            for(int i = 0;i < a.m;i++)
            {
                for(int j = 0;j< a.n;j++)
                {
                    this->x[i][j] = a.x[i][j];
                }
            }
            return *this;
        }
        Matrix operator+(Matrix &a)
        {
            Matrix b(a.m,a.n);
            for(int i = 0;i < a.m;i++)
            {
                for(int j = 0;j< a.n;j++)
                {
                    b.x[i][j] = this->x[i][j] + a.x[i][j];
                }
            }
            return b;
        }
        Matrix operator-(Matrix &a)
        {
            Matrix b(a.m,a.n);
            for(int i = 0;i < a.m;i++)
            {
                for(int j = 0;j< a.n;j++)
                {
                    b.x[i][j] = this->x[i][j] - a.x[i][j];
                }
            }
            return b;
        }
};

int main()
{
    Matrix m1(3,4),m2(3,4),m3(3,4),m4(3,4);
    std::cin>>m1>>m2;
    std::cout<<m1<<m2;
    m3 = m1+m2;
    m4 = m1-m2;
    std::cout<<m3<<m4;
}