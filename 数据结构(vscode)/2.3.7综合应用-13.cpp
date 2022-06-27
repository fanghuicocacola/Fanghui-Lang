//13.两个递增有序链表的合并为递减有序序列
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNOde
{
    ElemType data;
    LNOde *next;
}LNode,*LinkList;

void MergeList(LinkList &La,LinkList &Lb){
    //思路，头插法，从Lb的第一个结点开始，与La的结点比较，pa，pb记录当前表上的点
    //哪个结点大就把哪个放入新链表，放入以后，当前指针后移。
    //如果存在某个链表比较结束以后不为空，那么它的所有的结点值都比新新链表所存的大，所以采用头插法全部存入。
    LNode *r,*pa=La->next,*pb=Lb->next;
    La->next = NULL;
    while (pa!=NULL&&pb!=NULL){
        if(pa->data<=pb->data){
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        }
        else{
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if(pa!=NULL)
        pb = pa;
    while (pb!=NULL){
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}