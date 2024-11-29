#include<stdio.h>
#include<iostream>
//平衡二叉树结点
typedef struct AVLNode{
    int key;         //数据域
    int balance;     //平衡因子
    struct AVLNode *lchild,*rchild;
}AVLNode,*AVLTree;