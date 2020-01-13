#pragma once
#include <stdio.h>
extern struct Token token_stream[100000];
extern int token_stream_pos;
void print_token(struct Token tok);
struct Token next_token();
struct Token build_int_v(long long n);
struct Token build_real_v(long double s);
struct Token build_op(enum Tag t);
void build_token_stream();
// 123 -> "123"
char* int_to_str(long long tmp);
char* real_to_str(double tmp);
struct Token;
char* tok_to_str(struct Token tok,char *str);
enum Tag {
	INTEGER = 0, REAL, LP, RP, WORD, COMMA,
	PLUS, MINUS, MUL, DIV, END_TOKEN
};
struct Token {
	enum Tag token_type;
	union {
		long long int_v;
		double real_v;
		char id_name[8];
	};
};
