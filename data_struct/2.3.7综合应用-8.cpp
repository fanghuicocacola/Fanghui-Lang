//08.给定两个单链表，编写算法找出两个链表的公共结点。
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

int Length(LinkList L1){
    int length=1;
    /**代码**/
    return length;
}
LinkList Search_lst_Common(LinkList L1,LinkList L2){
    int len1=Length(L1),len2=Length(L2),dist;
    LinkList longList,shortList;
    if(len1>len2){
        longList=L1->next;
        shortList=L2->next;
        dist=len1-len2;
    }
    else{
        longList=L2->next;
        shortList=L1->next;
        dist=len2-len1;
    }
    while (dist--)
        longList=longList->next;
    while (longList!=NULL)
    {
        if(longList==shortList)
            return longList;
        else{
            longList = longList->next;
            shortList = shortList->next;
        }
    }//while
    return NULL;
}