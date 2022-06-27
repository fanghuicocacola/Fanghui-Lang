//10.将一个带头结点的单链表A分解为两个带头结点的单链表A和B,
//使得A表中含有原表中序号为奇数的元素,而B表中含有原表中序号为偶数的元素,且保持其相对顺序不变.
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

LinkList DisCreat_1(LinkList &A){
    //将表A中结点按序号的奇偶性分解到表A或B中
    int i = 0;
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A,*rb = B,*p;
    p = A->next;
    A->next = NULL;
    while (p!=NULL)
    {
        i++;
        if(i%2==0){
            rb->next = p;
            rb = p;
        }
        else{
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}