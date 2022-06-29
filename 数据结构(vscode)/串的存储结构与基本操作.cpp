#include<iostream>

#define MAXLEN 255    //预定义最大串长为255

//静态数组实现
typedef struct 
{
    char ch[MAXLEN]; //每个分量存储一个字符
    int length;      //串的实际长度
}SString;


//动态数组实现
typedef struct 
{
    char *ch;
    int length;
}HString;

int main(){
    HString S;
    S.ch = (char*)malloc(MAXLEN*sizeof(char));
    S.length = 0;
}


typedef struct StringNode{
    char ch;  //每个结点存1个字符
    struct StringNode *next;    
}StringNode,*String;

//上边的存储密度低

typedef struct StringNode{
    char ch[4];
    struct StringNode *next;
}StringNode,*String;

int StrLength(SString S){
    int length = 0;
    /*code*/
    return length;
}

bool SubString(SString &Sub,SString S,int pos,int len){
    //子串范围越界
    if (pos+len-1>S.length)
        return false;
    for(int i=pos;i<pos+len;i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}
//比较操作。若S>T，则返回值>0；若S=T，则返回值=0，若S<T，则返回值<0
int StrCompare(SString S,SString T){
    for(int i=1;i<=S.length && i<=T.length;i++){
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    //扫描过的所有字符都相同，则长度长的串更大
    return S.length-T.length;
}
//定位操作。若主串S中存在与串T值相同的S子串，则返回它在子串中第一次出现的位置；否则函数值为0
int Index(SString S,SString T){
    int i=1,n=StrLength(S),m=StrLength(T);
    SString sub;  //用于暂存子串
    while (i<=n-m+1)
    {
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0)
            ++i;
        else return i;  //返回子串中的位置
    }
    return 0;  //S中不存在与T相等的子串
}