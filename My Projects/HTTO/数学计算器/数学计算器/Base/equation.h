#pragma once
#include "Count.h"
#include <vector>
namespace Htto
{
	namespace Count
	{
		//�򵥷���
		class Equation
		{
		public:
			//�򵥷��̽��޵�Ԫ����x һ�η��̺Ͷ��η���
			static std::vector<Fraction> solve(const std::string & str);
			static Polynomial get_polynomial(const std::string & str);
			static Polynomial merage(const std::string & left, const std::string & right);
		private:
		};
		//��ʽ����,���ݼ򵥷���.
		class Equation3 :Equation
		{
		public:
			static std::vector<Fraction> solve(const std::string & str);
			static Rational_fraction get_rational_fraction(const std::string & str);
			static Rational_fraction merage(const std::string & left, const std::string & right);
		};
		//��Ԫ����1�η���
		class Equation2:Equation
		{
		public:
			static std::map<std::string, Fraction>solve(const std::vector<std::string>& vec);
	//	protected:
			static Polynomial convert_single_to_polynomial(const std::string & vname, const Polynomial & poly);
		public:
			static Fraction solve_driver(std::string v, const std::map<std::string, Polynomial>& table);
		};
	}
}