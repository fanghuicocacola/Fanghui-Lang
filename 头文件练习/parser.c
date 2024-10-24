#include "parser.h"
#include "info.h"
char* parser()
{
	return expr();
}
// 1+2+3*3)

char* expr() // +, -将Term 练成一个Expr
{
	if (token_stream[token_stream_pos].token_type == END_TOKEN)
	{
		printf("Radio Gaga");
		return 1;
	}
	push_info("(");

	char* ok = term();
	if (ok == NULL) {
		printf("factor: syntax error!");
		return 0;
	}
	struct Token tok = next_token();
	while (tok.token_type == PLUS || tok.token_type == MINUS) {
		ok = term();
		if (term() == 0)
		{
			return NULL;
		}
	}
	return 1;
}
char* term()// */ 将Factor连接成一个Term
{
	int ok = factor();
	if (ok == 0) {
		printf("term: syntax error!");
		return 0;
	}
	struct Token tok = next_token();
	while (tok.token_type == DIV || tok.token_type == MUL) {
		ok = factor();
		if (factor() == 0)
		{
			return 0;
		}
	}
	return 1;
}
// Factor * Facot /Factor * F /F *F 
// x*x*y + 3*x*y
// T+T-T+T-T-T
// 支持括号
char* factor()
{
	struct Token tok = next_token();
	if (tok.token_type == INTEGER || tok.token_type == REAL)
	{
		return 1;
	}
	printf("factor: syntax error!");
	print_token(tok);
	return 0;
}