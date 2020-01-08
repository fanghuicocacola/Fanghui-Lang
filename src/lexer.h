#pragma once
#include <stdio.h>
extern struct Token token_stream[100000];
void print_token(struct Token tok);
struct Token build_int_v(long long n);
struct Token build_real_v(long double s);
struct Token build_op(enum Tag t);
void build_token_stream();
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
