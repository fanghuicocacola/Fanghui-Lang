#pragma once
#include <stdio.h>
#include <stdlib.h>

struct IntVec 
{
	int length;
	int back;
	int* data;
};
// |1 2 3 45 567 5445                                  |
struct IntVec create_int_vec(int len);
void destroy_int_vec(struct IntVec iv);
int visit_int_vec(struct IntVec, int index);
void ipush_back(struct IntVec*, int value);
void ipop_back(struct IntVec*);
/*
	=>[.......]
*/