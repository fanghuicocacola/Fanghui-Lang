//16.判断B是不是A的连续子序列
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNOde
{
    ElemType data;
    LNOde *next;
}LNode,*LinkList;

bool Pattern(LinkList A,LinkList B){
    LNode *p = A;
    LNode *pre = p;
    LNode *q = B;
    while (p!=NULL&&q!=NULL)
    {
        if(p->data==q->data){
            p = p->next;
            q = q->next;
        }
        else{
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    if(q==NULL)
        return true;
    else
        return false;
}