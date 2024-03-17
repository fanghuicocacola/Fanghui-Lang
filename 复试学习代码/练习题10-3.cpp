# include<iostream>
#include <string.h>

class RLE
{
    private:
        char s1[81],s2[81];
        int length;
    public:
        RLE(char s[])
        {
            strcpy(s1,s);
            length = strlen(s);
        }
        char* Zip()
        {
            int i = 0,j = 0,num = 1;
            while(i < length)
            {
                if(s1[i] == s1[i+1])
                {
                    num++;
                    i++;
                }
                else
                {
                    s2[j] = num + 48;
                    s2[++j] = s1[i];
                    j++;
                    i++;
                    num = 1;
                }
            }
            std::cout<<s2; 
            return s2;  
        }
};

int main()
{
    char *str = (char*)"bbbbbaaddddeeeeeee";
    RLE s(str);
    strcpy(str,s.Zip());
}