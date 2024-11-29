// Created on 呀勒呀勒.

#include <iostream>
#include <stdio.h>
using namespace std;

struct ElemType{
    int value;
}
//二叉树的节点（链式存储）
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
    //struct BiNode *parent;根据实际需求决定要不要加父节点指针
}BiTNode,*BiTree;

//链式队列节点
typedef struct LinkNode{
    BiNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;  //队头队尾
}LinkQueue;

int main() {
    cout << "Hello World!";
    //定义一颗空树
    BiTree root = NULL;

    //插入根节点
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL
    root->rchild = NULL;;

    //插入新节点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;  //作为根节点的左孩子
}

//先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}


int treeDepth(BiTree T){
    if(T == NULL){
        return 0;
    }
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //树的深度=Max(左子树深度，右子树深度)+1
        return l>r ? l+1 : r+1;
    }
}

//层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);           //初始化辅助队列
    BiTree p;
    EnQueue(Q,T);          //将根节点入队
    while(!IsEmpty(Q)){   //队列不空则循环
        DeQueue(Q,p);     //队头节点出队
        visit(p);         //访问出队节点
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);//左孩子入队
        if(p->rchild!=NULL)      
            EnQueue(Q,p->rchild);//右孩子入队
    }
}

//线索二叉树结点
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;     //左右线索标志,tag为0，表示指针指向孩子，为1表示指向"线索"
}ThreadNode,*ThreadTree;

//访问结点q
void visit(BiNode *q){
    if(q==p)
        final = pre;
    else
        pre = q;
}
//辅助全局变量，用于查找结点p的前驱
BiNode *p;              //指向目标结点
BiNode *pre = NULL;    //指向当前访问结点的前驱
BiNode *final = NULL;  //用于记录最终结果
//中序线索化完整代码
//线索二叉树结点
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;     //左右线索标志,tag为0，表示指针指向孩子，为1表示指向"线索"
}ThreadNode,*ThreadTree;
//全局变量pre，指向当前访问结点的前驱
ThreadNode *pre = NULL;
//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T->lchild);   //中序遍历左子树
        visit(T);              //访问根节点
        InThread(T->rchild);   //中序遍历右子树
    }
}
//中序线索化二叉树T
void CreateInThread(ThreadTree T){
    pre = NULL;              //pre初始化为NULL
    if(T!=NULL){。           //非空二叉树才能线索化
        InThread(T);         //中序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag = 1;  //处理遍历的最后一个结点
    }
}
void visit(ThreadNode *q){
    if(q->lchild==NULL){//左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL&&pre->rchild==NULL){//后子树为空，建立后继线索
        pre->rchild=q;
        pre->rtag=1;
    }
    pre = q;
}

//中序线索二叉树找中序后继
//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *p){
    //循环找到最左下结点(不一定是叶结点)
    while(p->ltag==0)
        p = p->lchild;
    return p;
}
//在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p){
    //左子树中最左下结点
    if(p->rtag==0)
        return FirstNode(p->rchild);
    else
        return p->rchild;    //rtag==1直接返回后继线索
}
//对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void InOrder(ThreadNode *T){
    for(ThreadNode *p = FirstNode(T);p!=NULL;p=NextNode(p))
        visit(p);
}

//中序线索二叉树找中序前驱
//找到以p为根的子树，最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p){
    //循环找到最右下结点(不一定是叶结点)
    while(p->ltag == 0)
        p = p->rchild;
    return p;
}
//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode(ThreadNode *p){
    //左子树中最右下结点
    if(p->ltag == 0)
        return LastNode(p->lchild);
    else return p->lchild;    //ltag==1直接返回前驱线索
}
//对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T){
    for(ThreadNode *p=LastNode(T);p!=NULL;p=PreNode(p))
        visit(p);
}