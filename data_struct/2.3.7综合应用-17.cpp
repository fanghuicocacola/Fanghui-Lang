//17.判断循环双链表是否对称
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinkList;

bool Symmetry(DLinkList L){
    DNode *p=L->next,*q=L->prior;
    while (p!=q&&p->next!=q)
    {
        if(p->data==q->data){
            p=p->next;
            q=q->prior;
        }
        else
            return 0;
    }
    return true;
}