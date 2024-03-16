# include<iostream>
using namespace std;
class Sample
{
    public:
        Sample()
        {
            cout<<"\n调用了构造函数"<<endl;
        }
        Sample(Sample &A)
        {
            cout<<"\n调用了拷贝构造函数"<<endl;
        }
        void disp(const char* txt,const char* cap)
        {
            cout<<"\nTxt:"<<txt<<" Cap:"<<cap;
        }
        void disp(const char* txt,unsigned int opq)
        {
            cout<<"\nTxt:"<<txt<<" Opq:"<<opq;
        }
};

int main()
{
    system("chcp 65001");//添加该代码防止乱码
    Sample my;
    my.disp("Hello",254);
    my.disp("World",254);
    Sample your = my;
    Sample their(my);
}