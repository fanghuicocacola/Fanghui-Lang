#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
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
int main() {
	input();
	build_token_stream();
	for (int i = 0;token_stream[i].token_type!=END_TOKEN; i++) {
		print_token(token_stream[i]);
	}
	while (1);
	return 0;
}