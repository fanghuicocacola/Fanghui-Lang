//03.设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void R_Print(LinkList &L){
    if(L->next!=NULL)
    {
        R_Print(L->next);
    }
    if(L!=NULL)
        printf("%d",L->data);
}
void R_Ignore_Head(LinkList L){
    if(L->next!=NULL)
        R_Print(L->next);
}

int main(){
    
}