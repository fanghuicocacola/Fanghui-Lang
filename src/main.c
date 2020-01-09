#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
#include "vector.h"
// ��һ��:
//������ĳ���Ҫ��������һ�����ʽ
/*
" 1*2+3*123 + 1456 " 
Token token_stream[1000];
void build_token_stream(string str)
{}
step 1->һ������һ�����ʵķּ����
<INTEGER: int_v:1> <PLUS> <INTEGER:int_v: 1> 
*/
void lexer() {
	input();
	build_token_stream();
	for (int i = 0; token_stream[i].token_type != END_TOKEN; i++) {
		print_token(token_stream[i]);
	}
}
int main() {
	struct IntVec vec = create_int_vec(1);
	for (int i = 0; i < 1000; i++) {
		ipush_back(&vec, i);
	}
	for (int i = 0; i < 100; i++) {
		printf("%d", visit_int_vec(vec, i));
	}
	ipop_back(&vec);
	while (1);
	return 0;
}