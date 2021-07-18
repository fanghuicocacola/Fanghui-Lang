#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "test.h"
#define Stack_size 100
#define No_in_Stack -1
#define In_Stack 0
#define Finish 1
typedef struct MAZE
{
	char c;
	int Count;
	int backx;
	int backy;
	int flag;

}M;
typedef struct S
{
	char Stack_obj[Stack_size];
	int Stack_pos[Stack_size][2];
	int top;
}Seq_Stack;
int flag = 0;
void InitStack(S* s)
{
	s->top = -1;
}
int Push(S* s, char c, int m, int n)
{
	if (s->top == Stack_size - 1)
		return false;
	(s->top)++;
	s->Stack_obj[s->top] = c;
	s->Stack_pos[s->top][0] = m;
	s->Stack_pos[s->top][1] = n;
	return true;
}
int Pop(S* s)
{
	if (s->top == -1)
		return false;
	int c;
	//c=s->Stack_obj[s->top];

	(s->top)--;
	return s->top;
}
int GetTop(S s)
{
	if (s.top == -1)
		return false;
	else
		return s.Stack_obj[s.top];
}
void ClearStack(S* s)
{
	s->top == -1;
}
bool IsEmpty(S s)
{
	if (s.top == -1)
		return true;
	else
		return false;
}
bool IsFull(S s)
{
	if (s.top == Stack_size - 1)
		return true;
	else
		return false;
}
void Show(char maze[][11])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%s", maze[i]);
	}
}
void recursion_Go(char maze[][11], int m, int n)
{
	if (maze[m][n] == 'E')
	{
		flag = Finish;
		maze[m][n] = '*';
		return;
	}
	//cout<<"flag:   "<<flag<<endl;;
	if ((maze[m][n + 1] == ' ' || maze[m][n + 1] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m, n + 1);
		if (flag == Finish)
			return;
	}
	if ((maze[m + 1][n] == ' ' || maze[m + 1][n] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m + 1, n);
		if (flag == Finish)
			return;
	}
	if ((maze[m][n - 1] == ' ' || maze[m][n - 1] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m, n - 1);
		if (flag == Finish)
			return;
	}
	if ((maze[m - 1][n] == ' ' || maze[m - 1][n] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m - 1, n);
		if (flag == Finish)
			return;
	}
	maze[m][n] = '!';
}
void non_recursion_Go(char maze[][11], int m, int n)
{
	int p = 0;
	S s;
	InitStack(&s);
	M Maze[10][11];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			Maze[i][j].c = maze[i][j];
			Maze[i][j].Count = 0;
			Maze[i][j].backx = 0;
			Maze[i][j].backy = 0;
			Maze[i][j].flag = No_in_Stack;
		}
	}
	char c;
	int top;
	int a, b;
	Push(&s, Maze[m][n].c, m, n);
	Maze[m][n].flag = In_Stack;
	while (!IsEmpty(s))
	{
		top = Pop(&s);
		//p++;
		c = s.Stack_obj[top + 1];
		a = s.Stack_pos[top + 1][0];
		b = s.Stack_pos[top + 1][1];
		//cout<<p<<' '<<a<<' '<<b<<' '<<top<<endl;
		Maze[a][b].c = '*';
		//Maze[a][b].flag=p;
		if (c == ' ' || c == 'S')
		{
			Maze[a][b].c = '*';
			if (Maze[a - 1][b].c == ' ' || Maze[a - 1][b].c == 'E')
			{
				if (Maze[a - 1][b].flag == No_in_Stack)
				{
					Push(&s, Maze[a - 1][b].c, a - 1, b);
					Maze[a][b].Count++;
					Maze[a - 1][b].backx = a;
					Maze[a - 1][b].backy = b;
					Maze[a - 1][b].flag = In_Stack;
				}
			}
			if (Maze[a][b - 1].c == ' ' || Maze[a][b - 1].c == 'E')
			{
				if (Maze[a][b - 1].flag == No_in_Stack)
				{
					Push(&s, Maze[a][b - 1].c, a, b - 1);
					Maze[a][b].Count++;
					Maze[a][b - 1].backx = a;
					Maze[a][b - 1].backy = b;
					Maze[a][b - 1].flag = In_Stack;
				}
			}
			if (Maze[a + 1][b].c == ' ' || Maze[a + 1][b].c == 'E')
			{
				if (Maze[a + 1][b].flag == No_in_Stack)
				{
					Push(&s, Maze[a + 1][b].c, a + 1, b);
					Maze[a][b].Count++;
					Maze[a + 1][b].backx = a;
					Maze[a + 1][b].backy = b;
					Maze[a + 1][b].flag = In_Stack;
				}
			}
			if (Maze[a][b + 1].c == ' ' || Maze[a][b + 1].c == 'E')
			{
				if (Maze[a][b + 1].flag == No_in_Stack)
				{
					Push(&s, Maze[a][b + 1].c, a, b + 1);
					Maze[a][b].Count++;
					Maze[a][b + 1].backx = a;
					Maze[a][b + 1].backy = b;
					Maze[a][b + 1].flag = In_Stack;
				}
			}
		}
		if (c == 'E')
		{
			Maze[a][b].c = '*';
			break;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Maze[i][j].c == '*' && Maze[i][j].Count == 0)
				{
					Maze[Maze[i][j].backx][Maze[i][j].backy].Count--;
					Maze[i][j].c = '!';
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Maze[i][j].Count == 0 && Maze[i][j].c == '*')
				{
					Maze[i][j].c = '!';
				}
			}
		}
		//        for(int i=0;i<10;i++)
		//        {
		//            for(int j=0;j<10;j++)
		//            {
		//                cout<<Maze[i][j].Count;
		//            }
		//            cout<<endl;
		//        }
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			maze[i][j] = Maze[i][j].c;
			//cout<<Maze[i][j].flag<<' ';
		}
		//cout<<endl;
	}
}
void acm20()
{
	char maze[10][11];
	getchar();
	for (int i = 0; i < 10; i++)
	{
		fgets(maze[i], 10, stdin);
	}
	int a, b;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 'S')
			{
				a = i;
				b = j;
			}
		}
	}
	//recursion_Go(maze,a,b);
	non_recursion_Go(maze, a, b);
	Show(maze);
}
int main( )
{
    acm20( );
}