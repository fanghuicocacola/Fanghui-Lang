//21.判断单链表是否有环
/*
设置快慢两个指针分别为fast和slow，初始时都指向链表头head。
slow每次走一步，即slow=slow->next;
fast每次走两步，即fast=fast->next->next;
由于fast比slow走的快，如果有环，那么fast一定会先进入环，而slow后进入，
当两个指针都进入环以后，经过若干操作后两个指针定能在环上相遇。
这样就可以判断一个链表是否有环。
 */
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

LNode* FinDLoopStart(LNode *head){
    LNode *fast = head, *slow = head;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(slow==fast)
            break;
    }
    if(slow==NULL||fast->next==NULL)
        return NULL;
    LNode *p1 = head,*p2=slow;
    while (p1!=p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

//当fast与slow相遇时，slow肯定没有遍历完链表，故算法的时间复杂度为O(n),空间复杂度为O(1)