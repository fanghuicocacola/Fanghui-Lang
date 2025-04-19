//07.设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，
//删除表中所有介于给定的两个值(作为函数参数给出)之间的元素的元素(若存在)。
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void RangeDelete(LinkList &L,int min,int max){
    LNode *pr=L,*p=L->next;
    while (p!=NULL)
    {
        if(p->data>min&&p->data<max)
        {
            pr->next = p->next;
            free(p);
            p=pr->next;
        }
        else{
            pr=p;
            p=p->next;
        }
    }
}

