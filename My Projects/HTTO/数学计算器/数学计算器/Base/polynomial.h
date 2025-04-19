#pragma once
#include "monomial.h"
#include <vector>
#include <set>
#include <algorithm>
#include <initializer_list>
#define CONSOLE_DEBUG
namespace Htto
{
	namespace Count
	{
		class factorization;
	}
	//����ʽ��
	//��ע�⣬����ʽ�����(operator/)��������ģ��㷨�ϵ����⣩���һ���2��Сʱ���Խ������������ʧ���ˡ����ҷ�����fraction��bug����Ǹ�������ޣ������벻Ҫʹ��.
	//����һ������ʽ��û������ġ��ҽ�дһ����ʽ��������������⡣
	class Polynomial
	{
		friend class Count::factorization;
		friend Polynomial operator-(Polynomial  fra);
		friend class Equation2;
		friend class Rational_fraction;
	public:
		Polynomial() = default;
		Polynomial(std::string str);
		Polynomial(const Polynomial & poly) :data(poly.data) {}
		Polynomial(Polynomial && poly)noexcept { data = poly.data; }
		Polynomial(const std::initializer_list<Monomial> & ms)
		{
			data = ms;
		}
		void simplification()const;
		Polynomial reciprocal()const;
		std::string ToString()const;
		std::size_t  term_count()const;
		std::size_t variable_count()const;
		Fraction max_times()const;
		void sort()const;
		bool operator==(const Polynomial )const;
		Polynomial & operator =(const Polynomial &) = default;
		Polynomial operator +(const Polynomial &)const;
		Polynomial operator -(const Polynomial &)const;
		Polynomial operator *(const Polynomial &)const;
		Polynomial operator /(const Polynomial &)const;
		Polynomial& operator +=(const Polynomial &);
		Polynomial& operator -=(const Polynomial &);
		Polynomial& operator *=(const Polynomial &);
		Polynomial& operator /=(const Polynomial &);
		//���������ϵ��
		bool isSingle()const { return term_count() == 1; }
		void remove_term(const Monomial & mono);
		std::list<std::string> get_variable_list()const;
		bool isNumber()const;
		Fraction get_value(const std::map<std::string,Fraction> & vtable)const;
		Fraction find(std::string str);
		Monomial & operator [](size_t sz) { return data[sz]; }
#ifdef CONSOLE_DEBUG
		std::vector<Monomial> debug()
		{
			return data;
		}
#endif
		int convert_to_int() { return (int)data[0].coef; }
		operator int() { return convert_to_int(); }

		void get_rid_of_zero_monomial()const;
	private:
		mutable std::vector<Monomial> data;
		void push_monomial(const std::string & str);
	};
}