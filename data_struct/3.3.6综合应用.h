#include<iostream>
#include<stdio.h>

//01
bool BracketsCheck(char *str){
    InitStack(S);
    int i=0;
    while (str[i]!='\0')
    {
        switch (str[i])
        {
        case '(':Push(S,'(');break;
        case '[':Push(S,'[');break;
        case '{':Push(S,'{');break;
        case ')':Pop(S,')');break;
        case ']':Pop(S,']');break;
        case '}':Pop(S,'}');break;
        default:break;
        }
        i++;
    }
    if(!IsEmpty(S)){
        printf("括号不匹配\n");
        return false;
    }
    else{
        printf("括号匹配\n");
        return true;
    }
}

//02
void Train_Arrange(char *train){
    //用字符串train表示火车，H表示硬座，S表示软座
    char *p=train,*q=train,c;
    stack s;
    InitStack(s);          //初始化栈结构
    while (*p)
    {
        if(*p=='H')
            Push(s,*p);    //把H存入栈中
        else
            *(q++)=*p;     //把S调到前部
        p++;
    }
    while (!StackEmpty(s))
    {
        Pop(s,c);
        *(q++)=c;          //把H接到后部
    } 
}
#define MaxSize 100
//03
double p(int n,double x){
    struct stack
    {
        int no;
        double val;
    }st[MaxSize];
    int top=-1,i;
    double fv1=1,fv2=2*x;
    for(i=n;i>=2;i--){
        top++;
        st[top].no=i;
    }                     //入栈
    while(top>=0){
        st[top].val=2*x*fv2-2*(st[top].no-1)*fv1;
        fv1=fv2;
        fv2=st[top].val;
        top--;             //出栈  
    }
    if(n==0){
        return fv1;
    }
    return fv2;
}

//04
Queue q;    //过江渡船载渡队列
Queue q1;   //客车
Queue q2;   //货车
void manager(){
    int i=0,j=0;
    while(j<10){
        if(!QueueEmpty(q1)&&i<4){
            DeQueue(q1,x);
            EnQueue(q,x);
            i++;
            j++;
        }
        else if(i==4&&Q!ueueEmpty(q2)){
            DeQueue(q2,x);
            EnQueue(q,x);
            i++;
            i=0;
        }
        else{
            while (j<10&&i<4&&!QueueEmpty(q2))
            {
                DeQueue(q2,x);
                EnQueue(q,x);
                i++;
                j++;
            }
            i=0;
        }
        if(QueueEmpty(q1)&&QueueEmpty(q2))
            j=11;        //总和不足10辆，直接退出
    }

}