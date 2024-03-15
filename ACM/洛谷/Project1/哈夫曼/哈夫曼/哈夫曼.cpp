#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OVERFLOW	-1
typedef struct {
	unsigned int weight;//权重
	unsigned int partent, lchild, rchild;
}HTNode, * HuffmanTree;
typedef int Status;
typedef char** HuffmanCode;

void Select(HuffmanTree* HT, int n, int* s1, int* s2) {
	int i;
	unsigned int min = 9999;
	int temp1 = 0, temp2 = 0;
	for (i = 1; i <= n; i++) {
		if ((*HT)[i].partent == 0 && (*HT)[i].weight < min) {
			min = (*HT)[i].weight;
			temp1 = i;
		}
	}
	*s1 = temp1;
	min = 9999;
	for (i = 1; i <= n; i++) {
		if ((*HT)[i].partent == 0 && (*HT)[i].weight < min && temp1 != i) {
			min = (*HT)[i].weight;
			temp2 = i;
		}
	}
	*s2 = temp2;
}
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int w[], int n) {
	//w存放n个字符的权值(均>0)，构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC。
	if (n <= 1)return;
	int m = 2 * n - 1;
	(*HT) = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	if (!(*HT))exit(OVERFLOW);
	int i;
	for (i = 1; i <= n; ++i) {
		(*HT)[i].weight = w[i];//权值
		(*HT)[i].partent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	for (i = n + 1; i <= m; ++i) {
		(*HT)[i].weight = 0;
		(*HT)[i].partent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}
	int s1, s2;
	for (i = n + 1; i <= m; ++i) {	//建哈夫曼树
		//在HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
		Select(HT, i - 1, &s1, &s2);
		(*HT)[s1].partent = i; (*HT)[s2].partent = i;
		(*HT)[i].lchild = s1; (*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	//---从叶子到根逆向求每个字符的哈夫曼编码---
	(*HC) = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	if (!(*HC))exit(OVERFLOW);
	char* cd = (char*)malloc(n * sizeof(char));
	if (!cd)exit(OVERFLOW);
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i) {
		int start = n - 1;
		int f = 0;
		for (int c = i, f = (*HT)[i].partent; f != 0; c = f, f = (*HT)[f].partent)
			if ((*HT)[f].lchild == c)cd[--start] = '0';
			else cd[--start] = '1';
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));
		if (!(*HC)[i])exit(OVERFLOW);
		strcpy((*HC)[i], &cd[start]);
	}
	free(cd);
}


void main() {
	HuffmanTree HT;
	HuffmanCode HC;
	printf("请输入待编码字符个数:");
	int n;
	scanf_s("%d", &n);
	int w[100];
	printf("请输入对应字符的权值:");
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &w[i]);
	}
	HuffmanCoding(&HT, &HC, w, n);
	for (int i = 1; i <= 2 * n - 1; i++) {
		printf("%d:\t%d\t%d\t%d\t%d\n", i, HT[i].weight, HT[i].partent, HT[i].lchild, HT[i].rchild);
	}
	for (int i = 1; i <= n; i++) {
		printf("权值为%d的哈夫曼编码:%s\n", w[i], HC[i]);
	}
}

