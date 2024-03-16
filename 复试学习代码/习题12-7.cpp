# include<iostream>
# include<math.h>
static float s = 0;
class Shape
{
    public:
        virtual float area() = 0; //纯虚函数
};

float Total(Shape *s[],int n)
{
    float sum = 0.0;
    for(int i = 0;i<n;i++)
    sum += s[i]->area();
    return sum;
}

class Triangle:public Shape
{
    private:
        float L1,L2,L3; //三条边
    public:
        void setTri(float L1,float L2,float L3)
        {
            this->L1 = L1;
            this->L2 = L2;
            this->L3 = L3;
        }
        float area()
        {
            float s1;
            float p = (L1 + L2 + L3)/2;
            s1 = sqrt(p*(p-L1)*(p-L2)*(p-L3));
            return s1;
        }
        friend float Total(Shape &exp);
};

class Rectangle:public Shape
{
    private:
        float L1,L2; //三条边
    public:
        void setRect(float L1,float L2)
        {
            this->L1 = L1;
            this->L2 = L2;
        }
        float area()
        {
            float s1;
            s1 = L1*L2;
            return s1;
        }
        friend float Total(Shape &exp);
};

float Total(Shape &exp)
{
    s += exp.area();
    return s;
}

int main()
{
    Triangle t1;
    Rectangle R1,R2;
    t1.setTri(3,4,5);
    std::cout<<"\narea = "<<Total(t1);
    R1.setRect(4,8);
    std::cout<<"\narea = "<<Total(R1);
    R2.setRect(10,10);
    std::cout<<"\narea = "<<Total(R2);
}