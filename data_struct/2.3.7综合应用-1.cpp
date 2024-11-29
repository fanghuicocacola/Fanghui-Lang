//01.设计一个递归算法，删除不带头节点的单链表L中所有值为x的结点
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void Delete_1(LinkList &L,ElemType x){
    LNode *s = (LinkList)malloc(sizeof(LNode));
    LNode *p = (LinkList)malloc(sizeof(LNode));
    p->next = NULL;
    if(L == NULL)
        return ;
    if(L->data == x){
        p = L;
        L = L->next;
        free(p);
        Delete_1(L,x);
    }
    else
        Delete_1(L->next,x);
    
}
int main(){
    
}