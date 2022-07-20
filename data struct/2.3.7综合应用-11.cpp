//11思路同上一题，但采用头插法
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

LinkList DisCreat_2(LinkList &A){
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next,*q;
    LNode *ra = A;
    while (p!=NULL)
    {
        ra->next=p;ra=p;
        p = p->next;
        if(p!=NULL){
            q = p->next;
            p->next = B->next;
            B->next = p;
            p = q;
        }
    }
    ra->next = NULL;
    return B;
}