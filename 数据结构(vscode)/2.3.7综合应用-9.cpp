//09.给定一个带表头结点的单链表，设head为头指针，结点结构为(data,next),data为整型元素,next为指针,
//试写出算法:按递增次序输出单链表中各结点的数据元素,并释放结点所占的存储空间(要求:不允许使用数组作为辅助空间)
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void Min_Delete(LinkList &head){
    LNode *u;//暂存需要删除的结点
    while (head->next!=NULL)
    {
        LNode *pre=head;
        LNode *p=pre->next;
        while (p->next!=NULL)
        {
            if(p->next->data<pre->next->data)
                pre=p;
            p=p->next;
        }
        printf("%d",pre->next->data);
        u=pre->next;
        pre->next=u->next;
        free(u);
    }//while
    free(head);
}