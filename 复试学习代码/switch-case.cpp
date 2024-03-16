# include<iostream>
int main(){
    system("chcp 65001");
    int a;
    std::cin>>a;
    switch (a)
    {
        case 1:
        {
            std::cout<<"第一个case被执行了！";
            __attribute__ ((fallthrough));
        }
        case 2:
        {
            std::cout<<"第二个case被执行了！";
            break;
        }
        case 3:
        {
            std::cout<<"第三个case被执行了！";
            __attribute__ ((fallthrough));
        }
        case 4:
        {
            std::cout<<"第四个case被执行了！";
            __attribute__ ((fallthrough));
        }
        default:
        {
            std::cout<<"默认的语句被执行了！";
            break;
        }
    }}