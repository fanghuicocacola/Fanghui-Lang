//14.提取两个递增有序单链表的公共结点，组成新的链表，不能破坏结点
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void Get_Common(LinkList A,LinkList B){
    LNode *p=A->next,*q=B->next,*r,*s;
    LinkList C=(LinkList)malloc(sizeof(LNode));
    r = C;
    while (p!=NULL&&q!=NULL)
    {
        if(p->data<q->data)
            p = p->next;
        else if(p->data>q->data)
            q = q->next;
        else{
            s = (LNode*)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
}