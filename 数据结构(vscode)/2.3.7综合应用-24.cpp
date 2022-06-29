//24.单链表保存了m个整数，要求设计算法在时间上尽可能高效，对于m个数中绝对值相同的数，只保留第一个出现的数值。
/*
1)算法的基本设计思想:
  1.算法的核心思想是用时间换空间。使用辅助数组记录链表中已出现的数值，从而只需要对链表进行一趟扫描
  2.因为|data|<=n,故辅助数组q的大小为n+1，各元素的初值均为0。依次扫描链表中的各结点，同时检查q[|data|]的值，
    若为0则保留该结点，并令q[|data|]=1;否则将该结点删除。 
 */

#include<iostream>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

void func(LinkList &h,int n){
    LNode *p = h,*r;
    int *q,m;
    q = (int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++)
        q[i] == 0;
    while (p->next!=NULL)
    {
        m = p->next->data>0?p->next->data:-p->next->data;
        if(q[m] == 0){
            q[m] == 1;
            p = p->next;
        }
        else{
            r = p->next;
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}

//算法的时间复杂度为O(m),空间复杂度为O(n)