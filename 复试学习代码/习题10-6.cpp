# include<iostream>

class Point
{
    private:
        double x,y;
    public:
        Point(double x1 = 60.0,double y1 = 75.0)
        {
            x = x1;
            y = y1;
        }
        void display()
        {
            std::cout<<"Location: X = "<<x<<" Y = "<<y<<std::endl;
        }
        void setpoint(int x1,int y1)
        {
            x = x1;
            y = y1;
        }
};

int main()
{
    Point p;
    p.display();
    p.setpoint(80.0,100.0);
    p.display();
}