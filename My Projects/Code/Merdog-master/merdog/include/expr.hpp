#pragma once
#include "parser_node.hpp"
#include "lexer.hpp"
namespace Mer
{
	class NonOp :public ParserNode
	{
	public:
		Mem::Object execute()override
		{
			return nullptr;
		}
		size_t get_type()override
		{
			return Mem::BasicType::BVOID;
		}
	private:
	};
	class Index :public ParserNode
	{
	public:
		Index(ParserNode* l, size_t _index) :left(l), index(_index) {}
		Mem::Object execute()override
		{
			return left->execute()->operator[](std::make_shared<Mem::Int>(index));
		}
		size_t get_type()override
		{
			return left->get_type();
		}
	private:
		ParserNode* left;
		size_t index;
	};
	class ContainerIndex :public ParserNode
	{
	public:
		ContainerIndex(size_t _pos, ParserNode* _expr) :pos(_pos), expr(_expr) {}
		Mem::Object execute()override;
	private:
		size_t pos;
		ParserNode* expr;
	};
	class BinOp :public ParserNode
	{
	public:
		BinOp(ParserNode *l, Token *o, ParserNode* r) :left(l), op(o), right(r)
		{

		}
		Mem::Object execute()override;
		size_t get_type()override
		{
			return left->get_type();
		}
		virtual ~BinOp()
		{
			delete left;
			delete right;
		}
	private:
		ParserNode *left;
		Token *op;
		ParserNode *right;
	};
	class UnaryOp :public ParserNode
	{
	public:
		UnaryOp(Token *t, ParserNode* e) :op(t), expr(e) {}
		Mem::Object execute()override;
		size_t get_type()override
		{
			return expr->get_type();
		}
		virtual ~UnaryOp()
		{
			delete expr;
		}
	private:
		Token * op;
		ParserNode* expr;
	};
	class Structure;
	class CompoundObject;
	class Expr;
	class Type;
	
	class InitList :public ParserNode
	{
	public:
		InitList(size_t sz);
		Mem::Object execute()override;
		std::vector<Mem::Object> get_array();
		size_t get_type()override
		{
			return type;
		}
		virtual ~InitList();
	private:
		std::vector<Expr*> init_v;
		size_t type;
		size_t size;
	};
	class Expr :public ParserNode
	{
	public:
		Expr() :is_bool(false),tree(and_or()) {}
		size_t get_type()override
		{
			if (is_bool)
			{
				return Mem::BOOL;
			}
			if (tree == nullptr)
				return Mem::BVOID;
			return tree->get_type();
		}
		Mem::Object execute()override
		{
			return tree->execute();
		}
		ParserNode *root() { return tree; }
		inline bool constant()const override
		{
			return false;
		}
		virtual ~Expr() {
			if(tree!=nullptr)
				delete tree;
		}
		// to undertake a particular operation, make use of tree then set tree as a nullptr, delete Expr.
		bool is_bool = true;
		ParserNode *tree;
		size_t expr_type;
	private:

		ParserNode *and_or();
		ParserNode *expr();
		ParserNode *nexpr();
		ParserNode *term();
		ParserNode *factor();
	};
	class Assign :public ParserNode
	{
	public:
		enum AssignType
		{
			None,
			Add, Sub, Div, Mul,
			Null,
		};
		Assign(AssignType a, ParserNode* l, Token* o, ParserNode* r) :asType(a), left(l), op(o), right(r) {}
		Mem::Object execute()override;
		virtual ~Assign()
		{
			delete right;
		}
	private:
		AssignType asType;
		ParserNode* left;
		Token *op;
		ParserNode* right;
	};
	class ImplicitConvertion:public Expr
	{
	public:
		ImplicitConvertion(size_t _type);
		Mem::Object execute()override;
	private:
		size_t type;
	};
}