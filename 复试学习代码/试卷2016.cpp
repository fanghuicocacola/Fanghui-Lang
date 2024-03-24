#include<iostream>

double func1(float x)
{
    if(x <= -1)
        return x*x*x;
    else if(x >= -1&&x <= 1)
        return 0;
    else
        return 5*x;
}

double func2(int n)
{
    return n*func2(n-1);
}

class Matrix
{
    public:
        int x[80][80] = {0}; //矩阵最大不超过 80*80
        int N,M;
    public:
        Matrix(int n,int m)
        {
            N = n;
            M = m;
        }
        void setMatrix(int a[])
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    x[i][j] = a[i*M+j];
                }
            }
        }
        void print()
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    std::cout<<x[i][j]<<'\t';
                }
                std::cout<<"\n";
            }
        }
        Matrix operator*(Matrix &a)
        {
            Matrix b(this->N,a.M);
            for(int i=0;i<this->N;i++)
            {
                for(int j=0;j<a.M;j++)
                {
                    for(int k=0;k<a.N;k++)
                    {
                        b.x[i][j] += this->x[i][k]*a.x[k][j];
                    }
                }
            }
            return b;
        }
};

void insert_sort(float p[],int n,float x)
{
    for(int i=0;i<n;i++)
    {
        if(x < p[i])
        {
            for(int j=n;j>i;j--)
            {
                p[j] = p[j-1];
            }
            p[i] = x;
            return;
        }
    }
}
void test()
{
    Matrix a(2,3),b(3,2);
    int x1[] = {1,2,3,4,5,6},x2[] = {1,2,3,4,5,6};
    a.setMatrix(x1);
    b.setMatrix(x2);
    a.print();
    b.print();
    Matrix c(2,2);
    c = a*b;
    c.print();
}

int main()
{
    float a[100] = {1,2,3,5,6,7,8};
    insert_sort(a,7,4);
    for(int i=0;i<8;i++)
    {
        std::cout<<a[i]<<'\t';
    }
}
