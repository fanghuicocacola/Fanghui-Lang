#pragma once
#include <string>
#include "object.hpp"
namespace Mer
{
	class ParserNode
	{
	public:
		ParserNode()
		{
			line_no = get_line_no();
		}
		
		virtual ~ParserNode() {}
		virtual std::string to_string()
		{
			return "<empty_node>";
		}
		inline virtual bool constant()const
		{
			return false;
		}
		virtual size_t get_type()
		{
			return 0;
		}
		virtual Mem::Object execute() 
		{
			throw std::runtime_error("called by an indefinite var");
		}
		size_t line_no;
	};
}
