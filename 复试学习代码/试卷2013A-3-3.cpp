#include<iostream>
#include<string.h>
class Person
{
    private:
        char* name;
        int age;
    public:
    Person(const char* n,int a);
    ~Person();
    void Print();
};

Person::Person(const char* n,int a)
{
    this->name = new char(strlen(n)+1);
    strcpy(this->name,n);
    this->age = a;
    std::cout<<"Construct!"<<std::endl;
}

Person::~Person()
{
    delete[] name;
    std::cout<<"Destruct!"<<std::endl;
}

void Person::Print()
{
    std::cout<<"Name: "<<this->name<<" Age: "<<this->age<<std::endl;
}

int main()
{
    int age = 21;
    Person p("Jack",age);
    p.Print();
}