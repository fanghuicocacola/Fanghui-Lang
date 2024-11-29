//02.在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，
//假设值为x的结点不唯一，试编写算法以实现上述操作。
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void Delate_2(LinkList &L,ElemType x){
    LNode *p = L->next,*pre = L,*q;
    while (p!=NULL)
    {
        if(p->data == x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else{
            pre=p;
            p = p->next;
        }
    }
}

void Delate_3(LinkList &L,ElemType x){
    LNode *p = L->next,*r=L,*q;
    while (p!=NULL)
    {
        if(p->data!=x){
            r->next = p;
            r = p;
            p = p->next;
        }
        else{
            q=p;
            p=p->next;
            free(q);
        }
    }
    r->next=NULL;
}

int main(){

}