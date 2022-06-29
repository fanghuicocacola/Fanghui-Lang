//25.设计一个空间复杂度为O(1)的算法，使得线性表L={a1,a2,a3,...,an}按照{a1,an,a2,an-1,a3,an-2,...}重新排列
/*
1)算法的基本设计思想
先观察L={a1,a2,a3,...,an-1,an}和L'{a1,an,a2,an-1,a3,an-2,...}，
发现L'是由L摘取第一个元素再摘取倒数第一个元素...依次合并而成的。
为了方便链表后半段取元素，需要先将L后半段原地逆置(按照题目要求的时间复杂度，不能借助栈)，
否则每取最后一个结点都需要遍历一次链表。
1.先找出链表L的中间结点，为此设置两个指针p和q，指针p每次走一步，指针q每次走两步，当指针q到达链表时，指针p正好再链表的中间结点；
2.然后将L的后半段结点原地逆置。
3.从单链表前后两段中依次各取一个结点，按要求重排。
*/
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void change_list(LinkList &h){
    LNode *p,*q,*r,*s;
    p=q=h;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
        if(q->next!=NULL)
            q = q->next;
    }
    q = p->next;
    p->next = NULL;
    while (q!=NULL)
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = h->next;
    q = p->next;
    p->next=NULL;
    while (q!=NULL)
    {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}

//第一步找中间结点的时间复杂度为O(n),第二步逆置的时间复杂度为O(n),
//第三步合并链表的时间复杂度为O(n),所以该算法的时间复杂度为O(n)。