# include<iostream>
# include<string.h>
# define max 8

class Person
{
    public:
        char name[max];
        int age;
    public:
        Person()
        {
            
        }
        Person(const char name[],int age)
        {
            strcpy(this->name,name);
            this->age = age;
            std::cout<<"Create a person"<<std::endl;
        }
        ~Person()
        {
            std::cout<<"Destructed a person"<<std::endl;
        }
};

class Worker:public Person
{
    private:
        int workerNum,salary;
    public:
        Worker()
        {
            std::cout<<"Create a worker"<<std::endl;
        }
        Worker(const char name[],int age,int workerNum,int salary):Person(name,age)
        {
            this->workerNum = workerNum;
            this->salary = salary;
            std::cout<<"Create a worker"<<std::endl;
        }
        void setSalary(int salary)
        {
            this->salary = salary;
        }
        int getsalary()
        {
            return this->salary;
        }
        ~Worker()
        {
            std::cout<<"Destructed a worker"<<std::endl;
        }
};

int main()
{
    Person *p,p1("AAA",21);
    Worker *w,w1("BBB",23,1001,6800);
    w1.setSalary(10000);
    std::cout<<w1.getsalary()<<std::endl;
    Worker w2 = w1;
    std::cout<<&w2<<&w1<<std::endl;
}