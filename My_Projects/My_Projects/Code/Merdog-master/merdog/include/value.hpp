#pragma once
#include <vector>
#include "parser_node.hpp"
#include "lexer.hpp"
#include "../include/parser.hpp"
namespace Mer
{
	class Expr;
	class FunctionBase;
	class StructureBase;
	//����ֵ���� literal-const
	class LConV :public ParserNode
	{
	public:
		LConV(Token *t);
		size_t get_type()override
		{
			return type;
		}
		Mem::Object execute()override
		{
			return obj;
		}
		std::string to_string()override
		{
			return "num";//tok->to_string();
		}
		inline bool constant()const override
		{
			return true;
		}
	private:
		size_t type;
		Mem::Object obj;
	};

	class Namespace;

	class GVar :public ParserNode
	{
	public:
		GVar(Namespace *ns,Token *o);
		size_t get_type()override
		{
			return type;
		}
		Mem::Object execute()override
		{
			return obj;
		}
		inline bool constant()const override
		{
			return false;
		}
	private:
		Namespace * names;
		size_t type;
		Mem::Object obj;
	};

	class Variable :public ParserNode
	{
	public:
		Variable(Token *tok);
		Variable(Token *tok, size_t _pos) :id(tok), pos(_pos) {}
		size_t get_type()override;
		Mem::Object execute()override;
	private:
		Token * id;
		size_t pos;
	};
	class FunctionCall :public ParserNode
	{
	public:
		FunctionCall(const std::vector<size_t> &types, size_t _index, FunctionBase * fun, std::vector<Expr*>& exprs);
		size_t get_type()override;
		Mem::Object execute()override;
	private:
		size_t index;
		FunctionBase * func;
		std::vector<Expr*> argument;
	};

	struct WordRecorder;
	Assign::AssignType _token_to_assType();

	namespace Parser
	{

		/*
		ParserNode *build_init_list(Namespace *names);
		*/
		ParserNode *parse_array(WordRecorder* var_info);
		ParserNode *parse_id();
		ParserNode *parse_var(WordRecorder* var_info);
		ParserNode *_parse_id_wn(Namespace *names);
		//FunctionCall *parse_function_call(Mer::Expr *co_caller,StructureBase *sb);
		FunctionCall *parse_function_call(Namespace *names);
		Namespace *kill_namespaces();
	}
}