# include<iostream>
class Sample
{
    int x;
    public:
        Sample(){};
        Sample(int a){x=a;}
        Sample(Sample &a){x=a.x+++10;}
        void disp(const char *ob){std::cout<<" "<<ob<<"x="<<x;}
};
int main(){
    Sample s1,s2(20),s3(s2),s4(s1);
    s1 = s2;
    s1.disp("s1.");
    s2.disp("s2.");
    s3.disp("s3.");
    s4.disp("s4.");
    Sample s5(s2);
    s5.disp("s5.");
    s1.disp("s1.");
}