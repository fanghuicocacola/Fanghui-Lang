//树的先根遍历
#include<iostream>
#define MAX_TREE_SIZE 100
typedef int ElemType;
typedef struct TreeNode
{
    ElemType data;
    int parents;
}TreeNode;
void visit(TreeNode *p){
    /**Code**/
}
typedef struct PTree{                     //树的类型定义
    TreeNode nodes[MAX_TREE_SIZE];    //双亲表示
    int n;                          //结点数
} PTree;
void PreOrder(TreeNode *R){
    if(R!=NULL){
        visit(R);             //访问根节点
        while (R还有下一个子树T)
        {
            PreOrder(T);      //先根遍历下一棵子树
        }
    }
}

//树的后根遍历
void PostOrder(TreeNode *R){
    if(R!=NULL)
    while(R还有下一棵子树T)
        PostOrder(T);       //后根遍历下一棵子树
    visit(R);               //访问根节点
}