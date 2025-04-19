#pragma once
#include "polynomial.h"
#include "factorization.h"
#include "Count.h"
//polynomial����ʹ��std::string ���һ��Rational_fraction����ʱΪ���ӷ�ĸ�������
namespace Htto
{
	class Rational_fraction
	{
	public:
		Rational_fraction() = default;
		Rational_fraction(const Polynomial & mol, const Polynomial & den) :m_molecular(mol), m_denomilator(den) {}
		Rational_fraction(const Polynomial & poly) { m_molecular = poly, m_denomilator = Polynomial("1"); }
		Rational_fraction(const std::string & str) :Rational_fraction(Polynomial(str)) {}
		std::string ToString()const;
		Rational_fraction get_reciprocal()const;
		Rational_fraction operator+ (const Rational_fraction&)const;
		Rational_fraction operator- (const Rational_fraction&)const;
		Rational_fraction operator* (const Rational_fraction&)const;
		Rational_fraction operator/ (const Rational_fraction&)const;
		bool operator== (const Rational_fraction &)const;
		void simplification();
		Polynomial& molecular() { return m_molecular; }
		Polynomial& denmonilator() { return m_denomilator; }
#ifdef CONSOLE_DEBUG
		void debug();
		int get_int_value();
		 operator int(){ return get_int_value(); }
#endif
	private:
		friend Rational_fraction operator- ( Rational_fraction param);
	
		//����
		Polynomial m_molecular;
		//��ĸ
		Polynomial m_denomilator;
	};
}