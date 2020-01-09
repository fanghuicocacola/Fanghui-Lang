#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
struct IntVec create_int_vec(int len) {
	struct IntVec ret;
	ret.length = len;
	ret.back = 0;
	ret.data = (int*)malloc(sizeof(int) * len);
	if (ret.data == NULL) {
		printf("Memory drain out!");
		exit(0);
	}
	return ret;
}

void destroy_int_vec(struct IntVec iv)
{
	free(iv.data);
}

int visit_int_vec(struct IntVec iv, int index)
{
	if (iv.back <= index)
	{
		printf("error!: range out");
		exit(0);
	}
	return iv.data[index];
}
//���������һ����ȫ©�������޸�
void ipush_back(struct IntVec* iv, int value)
{
	if (iv->back > iv->length/2)
	{
		vec_realloc(iv);
	}
	(*iv).data[(*iv).back++] = value;
}
//�������Ҳ��һ����ȫ©�������޸�
void ipop_back(struct IntVec* iv)
{
	if (iv->back <= 0) {
		printf("error!: range out");
		exit(0);
	}
	(*iv).back--;
}
// ��IntVec����
// step1: ����һ������ĵط�
// step2: ��ԭ�������ݷŵ��·����

void vec_realloc(struct IntVec* iv)
{
	int* new_place = (int*)malloc(sizeof(int) * (iv->length * 2 + 1));
	for (int i = 0; i < iv->back; i++) {
		new_place[i] = iv->data[i];
	}
	free(iv->data);
	iv->data = new_place;
	iv->length = iv->length * 2 + 1;
}

/*
*/