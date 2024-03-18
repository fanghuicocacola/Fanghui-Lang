#include<iostream>
#include<string.h>

class Student
{
    private:
        char *name;
        float score;
    public:
        Student(const char *str,int num)
        {
            this->name = new char(strlen(str));
            strcpy(this->name,str);
            this->score = num;
            std::cout<<"Create!"<<std::endl;
        }
        Student(Student &s)
        {
            this->name = new char(strlen(s.name));
            strcpy(this->name,s.name);
            this->score = s.score;
            std::cout<<"Copy nuCreate!"<<std::endl;
        }
        void print()
        {
            std::cout<<"name : "<<this->name<<" score : "<<this->score<<std::endl;
        }
        ~ Student()
        {
            delete[] name;
            std::cout<<"Destruct!"<<std::endl;
        }
};

int main()
{
    system("chcp 65001");
    Student s1("zhang san",80),s2(s1);
    s1.print();
    s2.print();
}