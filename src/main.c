#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
// 第一步:
//比如你的程序要处理这样一个表达式
/*
" 1*2+3*123 + 1456 " 
Token token_stream[1000];
void build_token_stream(string str)
{}
step 1->一个单词一个单词的分拣出来
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