#include "../include/object.hpp"
#include "../include/memory.hpp"
#include "../include/lexer.hpp"
#include "../include/namespace.hpp"
#include "../include/function.hpp"
#include "../include/word_record.hpp"
using namespace Mer::Mem;


std::string Mer::Mem::type_to_string(BasicType bt)
{
	switch (bt)
	{
	case Mer::Mem::BVOID:
		return "void";
	case Mer::Mem::BOOL:
		return "bool";
	case Mer::Mem::INT:
		return "int";
	case Mer::Mem::DOUBLE:
		return "double";
	case Mer::Mem::STRING:
		return "string";
	default:
		break;
	}
	return "";
}

size_t Mer::Mem::get_type_code(Token * tok)
{
	switch (tok->get_tag())
	{
	case VOID_DECL:
		return BVOID;
	case INTEGER_DECL:
		return INT;
	case REAL_DECL:
		return DOUBLE;
	case BOOL_DECL:
		return BOOL;
	case STRING_DECL:
		return STRING;
	case ID:
	{
		auto info = Mer::this_namespace->sl_table->find(Id::get_value(token_stream.this_token()));
		if (info == nullptr)
			throw Error("id: " + Id::get_value(token_stream.this_token()) + "no found");
		return info->get_type();

	}
	default:
		throw Error(tok->to_string() + " unknown type ");
	}
}

size_t &Mer::Mem::type_no()
{
	static size_t this_type_index = 10;
	return this_type_index;
}
// to DO 
size_t Mer::Mem::get_ctype_code()
{
	size_t container_type;
	size_t element_type;
	container_type = Parser::get_type();
	if (token_stream.this_tag() != LT)
	{
		return container_type;
	}
	token_stream.match(LT);
	element_type = get_ctype_code();
	token_stream.match(GT);
	return merge_two_type(container_type, element_type);
}

size_t Mer::Mem::merge_two_type(size_t c, size_t e)
{
	static std::map<std::pair<size_t, size_t>, size_t> type_m;
	std::pair<size_t, size_t> key = { c,e };
	auto result = type_m.find(key);
	if (result != type_m.end())
		return result->second;
	type_map.insert({ type_counter + 1,new ComplexType(c, e) });
	type_m.insert({ { c,e }, (size_t)type_counter });
	return (size_t)type_counter;
}

Mer::Mem::Object Mer::Mem::create_var_t(size_t type)
{
	switch (type)
	{
	case INT:
		return std::make_shared<Int>(6832);
	case DOUBLE:
		return std::make_shared<Double>(0.0);
	case BOOL:
		return std::make_shared<Bool>(true);
	case STRING:
		return std::make_shared<String>("");
	default:
		break;
	}
	throw Error("Mer::Mem::Object Mer::Mem::create_var_t(size_t type) Unsupported type.");
}

Mer::Mem::Object  Mer::Mem::Int::Convert(int type)
{
	switch (type)
	{
	case INT:
		return std::make_shared<Int>(value);
	case DOUBLE:
		return std::make_shared<Double>(value);
	case BOOL:
		return std::make_shared<Bool>(value);
	default:
		throw Error("int cannot convert to " + type_to_string((BasicType)type));
		break;
	}
}

Object Mer::Mem::Double::operator=(Object v) {

	value = std::static_pointer_cast<Double>(v->Convert(DOUBLE))->value;
	return Convert(Mem::DOUBLE);
}

Mer::Mem::Object Mer::Mem::Double::Convert(int type)
{
	switch (type)
	{
	case INT:
		return std::make_shared<Int>(value);
	case DOUBLE:
		return std::make_shared<Double>(value);
	default:
		throw Error("double cannot convert to " + type_to_string((BasicType)type));
	}
}

Mer::Mem::Object Mer::Mem::Bool::Convert(int type)
{
	switch (type)
	{
	case BOOL:
		return std::make_shared<Bool>(value);
	case INT:
		return std::make_shared<Int>(value);
	default:
		throw Error("type-convert error");
	}
}

bool Mer::Mem::Type::convertible(const size_t & t)
{
	return convertible_types.find(t) != convertible_types.end();
}

void Mer::Mem::Type::add_compatible_type(size_t type_code)
{
	convertible_types.insert(type_code);
}


