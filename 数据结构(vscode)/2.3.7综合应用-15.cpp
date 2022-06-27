//15.求两个链表元素的交集，放入新的链表
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNOde
{
    ElemType data;
    LNOde *next;
}LNode,*LinkList;

LinkList Union(LinkList &la,LinkList &lb){
    LNode *pa,*pb,*pc,*u;
    pa = la->next;
    pb = lb->next;
    pc = la;
    while (pa!=NULL&&pb!=NULL){
        if(pa->data == pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
        }
        else if(pa->data<pb->data)
        {
            u = pa;
            pa = pa->next;
            free(u);
        }
        else{
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa!=NULL){
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb!=NULL){
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
}