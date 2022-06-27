//20.设计一个包含有访问频度freq的双向链表。
//每次访问一个结点(Locate(L,x))，为该点的访问频度+1，并按照频度递减，频度相同的，最近访问的排在和它相同的前面
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *pre,*next;
    int freq;
}DNode,*DLinkList;

DLinkList Locate(DLinkList &L,ElemType x){
    DNode *p = L->next,*q;
    while (p!=NULL&&p->data!=x)
    {
        p = p->next;
    }
    if(!p)
        exit(0);
    else{
        p->freq++;
        if(p->pre==L||p->next->freq>p->freq)
            return p;
        if(p->next!=NULL)
            p->next->pre = p->pre;
        p->pre->next = p->next;
        q = q->pre;
        while(q!=L&&q->freq<=p->freq)
            q = q->pre;
        p->next = q->next;
        if(q->next!=NULL)
            q->next->pre = p;
        p->pre = q;
        q->next;
    }
    return p;
}
