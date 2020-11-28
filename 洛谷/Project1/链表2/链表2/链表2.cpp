#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;				//栈指针
} SqStack;					//声明顺序栈类型
void InitStack(SqStack*& s)   //初始化顺序栈
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
void DestroyStack(SqStack*& s) //销毁顺序栈
{
	free(s);
}
bool StackEmpty(SqStack* s)		//判断栈空否
{
	return(s->top == -1);
}
bool Push(SqStack*& s, ElemType e)	 //进栈
{
	if (s->top == MaxSize - 1)    //栈满的情况，即栈上溢出
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, ElemType& e)	 //出栈
{
	if (s->top == -1)		//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, ElemType& e)	 //取栈顶元素
{
	if (s->top == -1) 		//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];
	return true;
}
bool symmetry(ElemType str[])
{
	int i;  ElemType e;
	SqStack* st;
	InitStack(st);				//初始化栈
	for (i = 0; str[i] != '\0'; i++)	//将串所有元素进栈
		Push(st, str[i]);		//元素进栈
	for (i = 0; str[i] != '\0'; i++)
	{
		Pop(st, e);				//退栈元素e
		if (str[i] != e)			//若e与当前串元素不同则不是对称串
		{
			DestroyStack(st);	//销毁栈
			return false;
		}
	}
	DestroyStack(st);			//销毁栈
	return true;
}
void trans(char* exp, char postexp[])	//将算术表达式exp转换成后缀表达式postexp
{
	char e;
	SqStack* Optr;						//定义运算符栈
	InitStack(Optr);					//初始化运算符栈
	int i = 0;							//i作为postexp的下标
	while (*exp != '\0')					//exp表达式未扫描完时循环
	{
		switch (*exp)
		{
		case '(':						//判定为左括号
			Push(Optr, '(');				//左括号进栈
			exp++;						//继续扫描其他字符
			break;
		case ')':						//判定为右括号
			Pop(Optr, e);				//出栈元素e
			while (e != '(')				//不为'('时循环
			{
				postexp[i++] = e;			//将e存放到postexp中
				Pop(Optr, e);			//继续出栈元素e
			}
			exp++;						//继续扫描其他字符
			break;
		case '+':						//判定为加或减号
		case '-':
			while (!StackEmpty(Optr))	//栈不空循环
			{
				GetTop(Optr, e);			//取栈顶元素e
				if (e != '(')				//e不是'('
				{
					postexp[i++] = e;		//将e存放到postexp中
					Pop(Optr, e);		//出栈元素e
				}
				else					//e是'(时退出循环
					break;
			}
			Push(Optr, *exp);			//将'+'或'-'进栈
			exp++;						//继续扫描其他字符
			break;
		case '*':						//判定为'*'或'/'号
		case '/':
			while (!StackEmpty(Optr))	//栈不空循环
			{
				GetTop(Optr, e);			//取栈顶元素e
				if (e == '*' || e == '/')	//将栈顶'*'或'/'运算符出栈并存放到postexp中
				{
					postexp[i++] = e;		//将e存放到postexp中
					Pop(Optr, e);		//出栈元素e
				}
				else					//e为非'*'或'/'运算符时退出循环
					break;
			}
			Push(Optr, *exp);			//将'*'或'/'进栈
			exp++;						//继续扫描其他字符
			break;
		default:				//处理数字字符
			while (*exp >= '0' && *exp <= '9') //判定为数字
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';	//用#标识一个数值串结束
		}
	}
	while (!StackEmpty(Optr))	//此时exp扫描完毕,栈不空时循环
	{
		Pop(Optr, e);			//出栈元素e
		postexp[i++] = e;			//将e存放到postexp中
	}
	postexp[i] = '\0';			//给postexp表达式添加结束标识
	DestroyStack(Optr);			//销毁栈		
}
double compvalue(char* postexp)	//计算后缀表达式的值
{
	char d, a, b, c, e;
	SqStack* Opnd;				//定义操作数栈
	InitStack(Opnd);			//初始化操作数栈
	while (*postexp != '\0')		//postexp字符串未扫描完时循环
	{
		switch (*postexp)
		{
		case '+':				//判定为'+'号
			Pop(Opnd, a);		//出栈元素a
			Pop(Opnd, b);		//出栈元素b
			c = b + a;				//计算c
			Push(Opnd, c);		//将计算结果c进栈
			break;
		case '-':				//判定为'-'号
			Pop(Opnd, a);		//出栈元素a
			Pop(Opnd, b);		//出栈元素b
			c = b - a;				//计算c
			Push(Opnd, c);		//将计算结果c进栈
			break;
		case '*':				//判定为'*'号
			Pop(Opnd, a);		//出栈元素a
			Pop(Opnd, b);		//出栈元素b
			c = b * a;				//计算c
			Push(Opnd, c);		//将计算结果c进栈
			break;
		case '/':				//判定为'/'号
			Pop(Opnd, a);		//出栈元素a
			Pop(Opnd, b);		//出栈元素b
			if (a != 0)
			{
				c = b / a;			//计算c
				Push(Opnd, c);	//将计算结果c进栈
				break;
			}
			else
			{
				printf("\n\t除零错误!\n");
				exit(0);		//异常退出
			}
			break;
		default:				//处理数字字符
			d = 0;				//将连续的数字字符转换成对应的数值存放到d中
			while (*postexp >= '0' && *postexp <= '9')   //判定为数字字符
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			Push(Opnd, d);		//将数值d进栈

			break;
		}
		postexp++;				//继续处理其他字符
	}
	GetTop(Opnd, e);			//取栈顶元素e
	DestroyStack(Opnd);		//销毁栈		
	return e;					//返回e
}
void basic_act()
{
	ElemType e;
	SqStack* s;
	printf("顺序栈s的基本运算如下:\n");
	printf("  (1)初始化栈s\n");
	InitStack(s);
	printf("  (2)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (3)依次进栈元素a,b,c,d,e\n");
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	printf("  (4)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (5)出栈序列:");
	while (!StackEmpty(s))
	{
		Pop(s, e);
		printf("%c ", e);
	}
	printf("\n");
	printf("  (6)栈为%s\n", (StackEmpty(s) ? "空" : "非空"));
	printf("  (7)释放栈\n");
	DestroyStack(s);
}
void sym_act()
{
	ElemType str[]="12e21";
	if (symmetry(str))
		printf("%s是对称串\n", str);
	else
		printf("%s不是对称串\n", str);
}
void comp_act()
{
	char exp[] = "(38-20)/6";
	char postexp[MaxSize];
	trans(exp, postexp);
	printf("中缀表达式:%s\n", exp);
	printf("后缀表达式:%s\n", postexp);
	printf("表达式的值:%g\n", compvalue(postexp));
}
int main()
{
	basic_act();
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	sym_act();
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	comp_act();

}



