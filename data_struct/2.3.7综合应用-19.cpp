//19.每次输出当前循环单链表中最小值，并删除，直到链表为空
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void Del_All(LinkList &L){
    LNode *p,*pre,*minp,*minpre;
    while (L->next!=L)
    {
        p=L->next;
        pre=L;
        minp = p;
        minpre = pre;
        while(p!=L){
            if(p->data<minp->data){
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d",minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}