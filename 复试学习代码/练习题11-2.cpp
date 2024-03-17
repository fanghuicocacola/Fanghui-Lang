# include<iostream>

class RMB
{
    public:
        int yuan,jiao,fen;
        int money;  //100倍的金额
    public:
        RMB(int y = 0,int j = 0,int f = 0)
        {
            money = y*100 + j*10 + f;
            if(y < 0 || j < 0 || f < 0)
            {
                std::cout<<"输入非法，请输入大于零的金额！(将设置为0元0角0分)";
                yuan = 0;
                jiao = 0;
                fen = 0;
            }
            yuan = money/100;
            jiao = (money%100)/10;
            fen = money%10;
        }
        RMB operator+(RMB &r2)
        {
            RMB r3(0,0,0);
            r3.money = money + r2.money;
            std::cout<<"\t"<<money<<"\t"<<r2.money<<"\t"<<r3.money<<std::endl;
            r3.yuan = r3.money/100;
            r3.jiao = (r3.money%100)/10;
            r3.fen = r3.money%10;
            return r3;
        }
        RMB operator-(RMB &r2)
        {
            RMB r3(0,0,0);
            r3.money = money - r2.money;
            std::cout<<"\t"<<money<<"\t"<<r2.money<<"\t"<<r3.money<<std::endl;
            if(r3.money >= 0)
            {
                r3.yuan = r3.money/100;
                r3.jiao = (r3.money%100)/10;
                r3.fen = r3.money%10;
            }
            else
            {
                std::cout<<"输入非法，请输入大于零的金额！(将设置为0元0角0分)";
                r3.yuan = r3.jiao = r3.fen = 0;
            }
            return r3;            
        }
        bool operator>(RMB &r2)
        {
            if (money > r2.money)
                return 1;
            else
                return 0;
            
        }

        bool operator<(RMB &r2)
        {
            if (money < r2.money)
                return 1;
            else
                return 0;
            
        }
        void show()
        {
            std::cout<<"You have: 【"<<yuan<<" yuan】 【"<<jiao<<" jiao】 【"<<fen<<" fen】 "<<std::endl;
        }
};

int main()
{
    system("chcp 65001");//添加该代码防止乱码
    RMB r1(2,1,10),r2(3,9,3);
    r1.show(),r2.show();
    (r1+r2).show();
    (r2-r1).show();
}
