# include<iostream>
/*
    设有以下关于点point类的定义，请在此基础上派生出一个正方形square类，
    用以描述正方形左上角的位置，正方形的边长，并能够计算正方形的面积
*/
class point
{
    public:
        int x,y;
    public:
        void setxy(int x0,int y0)
        {
            x = x0;
            y = y0;
        }
        int getx()
        {
            return x;
        }
        int gety()
        {
            return y;
        }
};

class square:public point
{
    public:
        int topLeftX,topLeftY,length;
    public:
        square(int L)
        {
            length = L;
        }
        void Area()
        {
            topLeftX = point::getx();
            topLeftY = point::gety();
            std::cout<<topLeftX<<topLeftY;
            std::cout<<"左上角的坐标为"<<"X = "<<x<<" Y = "<<y<<std::endl;
            std::cout<<"正方形的面积为"<<length*length<<std::endl;
        }
};

int main()
{
    system("chcp 65001");//添加该代码防止乱码
    square example1(10);
    example1.setxy(1,1);
    example1.Area();
}