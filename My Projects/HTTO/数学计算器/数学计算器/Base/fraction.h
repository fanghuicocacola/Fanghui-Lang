#pragma once
#include "simple_algorithm.h"
#include <string>
#include <vector>
#include <iostream>
#include <initializer_list>
namespace Htto
{
	class Radical_Number;
	class Radical_Exp;
	class Radical_Number
	{
	private:
		friend class Radical_Exp;
		friend Radical_Number operator-(Radical_Number op);
		long inNumber=1;
		long outNumber=1;
	public:
		Radical_Number(int front, int in) :outNumber(front), inNumber(in) {}
		Radical_Number(std::string str);
		Radical_Number() { Radical_Number(1, 1); };

		Radical_Number(int num) { Radical_Number(num, 1); };
		void simplification();//����
		float get_numsqrt()const;
		void numsqrt();//����
		std::string ToString()const;//���string
#ifdef DEBUG
		void displayDEG()
		{
			std::
				<< "frontNumber:" << outNumber << "\t";
			std::cout << "insideNumber:" << inNumber << "\n";
		}
#endif
		int inNum();
		int outNum();
		Radical_Number StrSimpleCount(std::string str);
		Radical_Number set(std::string setStr);
		//=====================operator===========================
		Radical_Exp operator+(const Radical_Number & op)const;
		Radical_Exp operator-(const Radical_Number & op)const;
		Radical_Number operator*(const Radical_Number & op)const;
		Radical_Number operator/(const Radical_Number & op)const;
		Radical_Number operator= (const int & num);
		//====================class-type conversions===================
		operator Radical_Exp()const;
		operator float()const;
		operator std::string()const;
		operator int()const;
	};
	class Radical_Exp
	{
	private:
		friend class Fraction;
		friend class Radical_Number;
		std::vector<Radical_Number> ExpVec;
	public:
		Radical_Exp() = default;
		Radical_Exp(std::string str);
		Radical_Exp(std::initializer_list<Radical_Number> RNL) { for (auto  au : RNL) { ExpVec.push_back(au); } }
		std::string ToString()const;
		float get_numsqrt()const;
		void reset(std::string str);
		void simplification();
		void reduceByNumber(int num);
		bool isSingle();
		bool isNature();
		//==============================����====================================
		/*���ַ�����δ�༭����Exp��Number֮��������������ʾ�Ľ�Numberת��ΪExp*/
		friend Radical_Exp operator-(Radical_Exp op);//���ʽ�෴��
		Radical_Exp operator+(Radical_Exp Exp)const;
		Radical_Exp operator-(Radical_Exp Exp)const;
		Radical_Exp operator*(Radical_Exp op)const;
		Radical_Exp operator* (Radical_Number op)const;
		//û�г���???��ȻĿǰû��
		int GetMaxGCD();
		//=============================class-type conversion===================
		operator float()const;//convert into a float type
	};
	class Fraction
	{
	private:
		friend Fraction operator-(const Fraction fra);
		//����
		Radical_Exp m_molecular;
		//��ĸ
		Radical_Exp m_denomilator;
	public:
		Fraction():m_denomilator("1"),m_molecular("0"){ }
		Fraction(Radical_Exp up, Radical_Exp under);
		Fraction(std::string str);
		Fraction(int a, int b);
		Fraction(float fla);
		Fraction(const Fraction & fra);
		Fraction(Fraction && fra)noexcept = default;
		Fraction& operator= (const Fraction & fra);
		//======================���ò���====================
		Fraction pow(int times);//���������times�η�
		Fraction get_sqrt_value()const;
		void numsqrt();//����.
		void simplification();//����
		void reciprocal();//ȡ����
		Fraction get_reciprocal()const;//��ס����������ܿ��Ը��á�
		std::string ToString()const;//��ΪString
		bool is_interger()const;
	    bool is_square()const;
		float get_float_value()const;
		//=================operator=========================
		Fraction operator+(const Fraction & op)const;
		Fraction& operator+=(const Fraction & op);
		Fraction& operator-=(const Fraction & op);
		Fraction operator-(const Fraction & op)const;
		Fraction operator*(const Fraction & op)const;
		Fraction operator/(const Fraction & op)const;
		bool operator==(const Fraction & op)const;
		bool operator<(const Fraction & op)const;
		bool operator>(const Fraction & op)const;
		bool operator<=(const Fraction & op)const;
		bool operator>=(const Fraction & op)const;
		operator float()const;
	};
}
