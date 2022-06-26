//05.试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1).
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

LinkList Reverse_1(LinkList &L){
    LNode *p,*r;
    p=L->next;//避过头结点，因为头结点为空
    L->next=NULL;//先将L的第一个结点设为空，等待p指针将结点连接上
    while (p!=NULL)
    {
        r=p->next;//记下p的后继
        p->next = L->next;//一次只连一个结点，所以p的后继为空
        L->next = p;//接上p所指结点
        p = r;//p续上p的后继
    }
    return L
}

LinkList Reverse_2(LinkList &L){
    LNode *pre,*p=L->next,*r=p->next;//p指向第一个结点，r指向第二个结点
    p->next=NULL;//p的后继为空
    while (r!=NULL)
    {
        //以第一次循环为例，第一步：pre指向第一个结点(即原p所指结点)，p移动到第二个结点(即r所指位置)，
        //r移动到第三个结点(即r的后继)。第二步：将p的后继改为它的上一个结点(即pre)。
        //以此类推，每次向后遍历都将p的后继改为它的上一个，pre负责存储p的上一个结点，r负责存储p的下一个结点。
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;
    }
    L->next=p;//最后将逆置好的没有头结点的链表凭借到只有一个头结点的L链表上，实现带头结点的逆置。
    return L;
}