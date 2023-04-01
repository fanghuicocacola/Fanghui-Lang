#include <stdio.h>
int main()
{
    char str[81];           /* 在DOS模式下一行最多80个字符 */
    char ch;
    int i,num=0,w=0;
    //i记录字符串的下表，num记录字符数量，w判断当前读取的字符是一个单词的，还是新单词的
    printf("Input a string:  ");
    gets(str);              /* 输入字符串 */
    //第一步：gets作为输入，接收空格键
    for(i=0; (ch=str[i])!='\0'; i++)
    {
        //第二步：读取字符串，当遇到一个或多个空格，代表一个单词结束，将w置为0，开始记录下一个字符
        if(ch==' ')
            w=0;            /* 当前字符为空格时，置w=0 */
        else if(w==0)
        {
            w=1;            /* 新单词开始 */
            num++;
        }
    }
    printf("There are %d words in the line.\n",num);
    return 0;
}