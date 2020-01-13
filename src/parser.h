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
	<Tiger> <sheep> <eat> // 终结符
	还可以再次推导的是非终结符
	不可以再推导叫终结符
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
