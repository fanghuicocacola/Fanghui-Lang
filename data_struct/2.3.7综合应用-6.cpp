//06.有一个带头结点的单链表L,设计一个算法使其元素递增有序。
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void Ascending_Sort(LinkList &L){
    LNode *p = L->next,*pre;
    LNode *r = p->next; //保存p的后继结点
    while(p!=NULL){
        r = p->next;
        pre = L;
        while (pre->next!=NULL&&pre->next->data<p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
