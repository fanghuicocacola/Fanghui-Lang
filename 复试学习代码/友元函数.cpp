# include<iostream>
class A
{
    public:
        static int n;
        
    private:
        int x,y;
    public:
        A(int x,int y)
        {
            this->x = x;
            this->y = y;
            n++;
        }
        friend void getxy(A a);
        void getxy()
        {
            std::cout<<"x= "<<x<<"y= "<<y;
        }
};
void getxy(A a)
{
    std::cout<<a.x<<a.y;
}
int A::n = 10;
int main()
{
    A x(10,10);
    getxy(x);
    x.getxy();
}