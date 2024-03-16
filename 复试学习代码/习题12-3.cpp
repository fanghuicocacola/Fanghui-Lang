# include<iostream>

class Count
{
    public:
        static int count;
    public:
        Count()
        {
            count++;
        }
        static int getn()
        {
            return count;
        }
        ~Count()
        {
            count--;
        }
};
int Count::count = 30;
int main()
{
    Count c1,c2;
    std::cout<<"Count::getn():"<<Count::getn()<<std::endl;
    std::cout<<"c1.getn():"<<c1.getn()<<std::endl;
}