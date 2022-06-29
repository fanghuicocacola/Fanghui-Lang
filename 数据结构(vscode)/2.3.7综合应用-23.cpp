//23.时间上尽可能高效，找出两个链表的共同后缀的起始位置
/*
本题的结构体是单链表，采用双指针法。
用指针p,q分别扫描str1和str2，当p,q指向同一个地址时，即找到共同后缀的起始位置
1）本题的基本设计思想如下:
   1.分别求出str1和str2所指的两个链表的长度m和n。
   2.将两个链表以表尾对齐：令指针p，q分别指向str1和str2的头结点，
     若m>=n，则指针p先走，使p指向链表中的第m-n+1个结点；
     若m<n，则使q指向链表中的第n-m+1个结点，即使指针p和q所指向的结点到表尾的长度相等
   3.反复将指针p和q同步向后移动，当p，q指向同一位置时停止，即为共同后缀的起始位置，算法结束
*/

#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;
//求链表长度的函数
int listlen(LNode *head){
    int len = 0;
    while (head->next!=NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

LNode* find_addr(LNode *str1,LNode *str2){
    int m,n;
    LNode *p,*q;
    m = listlen(str1);
    n = listlen(str2);
    for (p=str1;m>n;n--)
        p = p->next;
    for (q=str2;m<n;n--)
        q = q->next;
    while (p->next!=NULL&&p->next!=q->next)
    {
        p = p->next;
        q = q->next;
    }
    return p->next;
}

//时间复杂度为O(len1+len2)或O(max(len1,len2))，其中len1，len2分别为两个链表的长度。