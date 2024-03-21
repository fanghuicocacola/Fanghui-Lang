#include<iostream>
#include<string.h>

class Base
{
    char str[20];
    public:
        Base(char *s="Dase default!")
        {
            strcpy(str,s);
        }
};
class Inh1:virtual public Base
{
    char str1[20];
    public:
        Inh1(char *s1,char *s2):Base(s1)
        {
            strcpy(str1,s2);
            std::cout<<str1<<std::endl;
        }
};
class Inh2:virtual public Base
{
    char str2[20];
    public:
        Inh2(char *s1,char *s2):Base(s1)
        {
            strcpy(str2,s2);
            std::cout<<str2<<std::endl;
        }
};
class Inh3:public Inh1,public Inh2
{
    char str3[20];
    public:
        Inh3(char *s1,char *s2,char *s3,char *s4):Inh1(s1,s2),Inh2(s1,s3)
        {
            strcpy(str3,s4);
            std::cout<<str3<<std::endl;
        }
};

int main()
{
    Inh3 a("class Base","class Inh1","class Inh2","class Inh3");
}