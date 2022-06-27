//12.递增有序数列删除重复值
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNOde
{
    ElemType data;
    LNOde *next;
}LNode,*LinkList;

void Del_Same(LinkList &L){
    LNode *p = L->next,*q;
    if(p==NULL)
        return;
    while (p->next!=NULL)
    {
        q = p->next;
        if(p->data == q->data){
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }  
}
