#include<stdio.h>
#include<iostream>

//二叉排序树结点
typedef struct BSTNode
{
    int key;
    BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//在二叉排序树中查找值为key的结点（非递归）
BSTNode *BST_Search(BSTree T,int key){
    while (T!=NULL&&key!=T->key)       //若树空或等于根结点值，则结束循环
    { 
        if(key<T->key)                 //小于，则在左子树上查找
            T=T->lchild;               //大于，则在右子树上查找
        else
            T=T->rchild;
    }
    return T;
}
//在二叉排序树中查找值为key的结点（递归）
BSTNode *BST_Search_2(BSTree T,int key){
    if(T==NULL)
        return NULL;     //查找失败
    if(key==T->key)
        return T;        //查找成功
    else if(key < T->key)
        return BST_Search_2(T->lchild,key);  //在左子树中找
    else
        return BST_Search_2(T->rchild,key);  //在右子树中找
}

//在二叉排序树中插入关键字为k的新结点(递归实现)(最坏时间复杂度O(h))
int BST_Insert(BSTree &T,int k){
    if(T==NULL){                            //原数为空，新插入的结点为根结点
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild=NULL;
        return 1;                           //返回1，插入成功
    }
    else if(k==T->key)                      //树中存在相同关键字的结点，插入失败
        return 0;
    else if(k<T->key)                       //插入到T的左子树
        return BST_Insert(T->lchild,k);
    else                                    //插入到T的右子树
        return BST_Insert(T->rchild,k);     
}

//按照str[]中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T,int str[],int n){
    T = NULL;                          //初始时T为空树
    int i=0;
    while (i<n)                        //依次将每个关键字插入到二叉排序树中
    {
        BST_Insert(T,str[i]);
        i++;
    }
    
}