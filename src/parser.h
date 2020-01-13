#pragma once

/*
	<Integer> <+> <Integer>
	Integer + Integer
	Expr-> Term + Expr
		-> Term - Expr
		-> Term
	Term-> Factor *(or /) Factor *(or /) *(or /)Factor
	Factor -> Integer
		   -> Real 
		   -> (Expr)

*/
/*
	CFG: Context Free Grammar:
	<Tiger> <sheep> <eat> // �ս��
	�������ٴ��Ƶ����Ƿ��ս��
	���������Ƶ����ս��
	S-> N v N
	N-> Tiger
	N-> sheep
	v-> eat
	Tiger eat Tiger 
	Tiger eat sheep
	sheep eat sheep
	sheep eat Tiger 
*/
#include "lexer.h"
/*
Interpreter: Lexer-> Parser -> Check -> Run
Compiler: Lexer-> Parser -> Check -> bin
*/
enum NodeType {
	BinOp,Factor
};
char* parser();
char* expr();
char* term();
char* factor();
