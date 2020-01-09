#include <stdio.h>
#include "lexer.h"
int token_stream_pos = 0;
void print_token(struct Token tok) {
	switch (tok.token_type)
	{
	case INTEGER:
		printf("<INTEGER:%lld>", tok.int_v);
		break;
	case REAL:
		printf("<REAL:%lf>", tok.real_v);
		break;
	case LP:
		printf("< ( >");
		break;
	case RP:
		printf("< ) >");
		break;
	case PLUS:
		printf("< + >");
		break;
	case MINUS:
		printf("< - >");
		break;
	case MUL:
		printf("< * >");
		break;
	case DIV:
		printf("< / >");
		break;
	case COMMA:
		printf("< , >");
		break;
	default:
		printf("<ERROR>");
		break;
	}
}

struct Token next_token()
{
	return token_stream[token_stream_pos++];
}

struct Token build_int_v(long long n) {
	struct Token ret;
	ret.token_type = INTEGER;
	ret.int_v = n;
	return ret;
}

struct Token build_real_v(long double s) {
	struct Token ret;
	ret.token_type = REAL;
	ret.real_v = s;
	return ret;
};

struct Token build_op(enum Tag t) {
	struct Token ret;
	ret.token_type = t;
	return ret;
}

struct Token token_stream[100000];

char buf[1000];

char* cur_p = NULL;

void input() {
	cur_p = buf;
	scanf_s("%s", cur_p, 1000);
}

struct Token str_to_int() {
	long long ret = 0;
	while (isdigit(*cur_p)) {
		ret *= 10;
		ret += *cur_p - '0';
		cur_p++;
	}
	if (*cur_p == '.') {
		// 跳过小数点
		cur_p++;
		double real_part = 0;
		// 记录小数点的移了几位
		double bit_tag = 0.1;
		while (isdigit(*cur_p)) {
			real_part += bit_tag * (*cur_p - '0');
			bit_tag *= 0.1;
			cur_p++;
		}
		cur_p--;
		return build_real_v(ret + real_part);
	}
	cur_p--;
	return build_int_v(ret);
}
/*1.34+45*/
void build_token_stream()
{
	int index = 0;
	while (*cur_p != '\0') {
		if (isdigit(*cur_p))
			token_stream[index++] = str_to_int();
		else if (*cur_p == '+')
			token_stream[index++] = build_op(PLUS);
		else if (*cur_p == '-')
			token_stream[index++] = build_op(MINUS);
		else if (*cur_p == '*') // multiply
			token_stream[index++] = build_op(MUL);
		else if (*cur_p == '/')
			token_stream[index++] = build_op(DIV);
		else if (*cur_p == '(')
			token_stream[index++] = build_op(LP);
		else if (*cur_p == ')')
			token_stream[index++] = build_op(RP);
		else if (*cur_p == ',')
			token_stream[index++] = build_op(COMMA);
		cur_p++;
	}
	token_stream[index++] = build_op(END_TOKEN);
}