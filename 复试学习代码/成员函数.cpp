# include<iostream>

class Sample
{
    public:
        int a,b,c;
        static int num;
    public:
        static void log()
        {
            std::cout<<"执行"<<std::endl;
        }
        Sample(int x=9){
            a=b=c=x;
        }
        void setSample(int x=1,int y=1,int z=1)
        {
            a = x;
            b = y;
            c = z;
        }
        void show()
        {
            std::cout<<"\na="<<a<<" b="<<b<<" c="<<c;
        }
        void show(const char a[])
        {
            std::cout<<a<<std::endl;
        }
};
int Sample::num = 1;
int main(){

    system("chcp 65001");//添加该代码防止乱码
    
    Sample sample;
    sample.num++;
    sample.show();
    sample.setSample(2,3,4);
    sample.show();
    sample.setSample();
    sample.show();
    sample.show("\nHello World!");
    std::cout<<Sample().num<<std::endl;
    Sample().log();
}