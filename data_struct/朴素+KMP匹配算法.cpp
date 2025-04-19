#include<iostream>
#define MAXLEN 255
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;


int Index(SString S,SString T){
    int i=1,j=1;
    while (i<=S.length && j<=T.length)
    {
        if(S.ch[i]==T.ch[j]){
            ++i;++j;
        }
        else{
            i = i-j+2;
            j = 1;
        }
    }
    if(j>T.length)//当j大于T的长度，说明T的所有字符都已经与S的某个子串匹配完，说明匹配成功，返回子串在S中的起始位置
        return i-T.length;
    else
        return 0;
}

int Index_KMP(SString S,SString T,int next[]){
    int i = 1,j = 1;
    while (i<=S.length && j<=T.length)
    {
        if(j==0||S.ch[i]==T.ch[i]){
            ++i;++j;  //继续比较后继字符
        }
        else
            j=next[j]; //模式串向右移动
    }
    if(j>T.length)
        return i-T.length; //匹配成功
    else
        return 0;
}