#include<iostream>
#include<stdio.h>
#define ElemType char

typedef struct {      //查找表的数据结构（顺序表）
    ElemType *elem;   //动态数组基地址
    int TableLen;     //表的长度
}SSTable;

//顺序查找
int Search_Seq(SSTable ST,ElemType key){
    int i;
    for(i=0;i<ST.TableLen && ST.elem[i]!=key;++i);
    //查找成功，则返回元素下标；查找失败，则返回-1
    return i==ST.TableLen? -1 : i;
}

int Search_Seq2(SSTable ST,ElemType key){
    ST.elem[0]=key;     //哨兵
    int i;
    for(i=ST.TableLen;ST.elem[i]!=key;--i);
    //查找成功，则返回元素下标；查找失败，则返回-1
    return i;
}

typedef struct      //查找表的数据结构（顺序表）
{
    ElemType *elem; //动态数组基址
    int TableLen;   //表的长度
}SSTable;

//折半查找
int Binary_Search(SSTable L,ElemType key){
    int low=0,high=L.TableLen-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;      //取中间位置
        if(L.elem[mid]==key)
            return mid;        //查找成功则返回所在位置
        else if(L.elem[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

//分块查找
typedef struct 
{
    ElemType maxValue;
    int low,high;
}Index;

//顺序表存储实际元素
ElemType List[100];
