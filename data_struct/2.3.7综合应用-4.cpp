//04.试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

LinkList Delete_Min(LinkList &L){
    LNode *p = L->next,*pre = L;
    LNode *minpre = pre,*minp = p;
    while (p!=NULL)
    {
        if(p->data < minp->data){
            minp = p;
            minpre = pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
    return L;
}