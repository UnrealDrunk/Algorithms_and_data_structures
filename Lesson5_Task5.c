//Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <ctype.h>

#define SIZE 50

char Expn[SIZE];
int StackNumber = -1;

void Push(char elem);
char Pop();
int OpPrecedence(char elem);

int main()
{                         
	char Infix[50], Postfix[50], Char, Element;
	int i = 0, k = 0;
	printf("\n\nPut the Infix Expression, for example (3+5)*4, or (a+b)/c etc.\n");
	puts("Please, keep attention to '(' ')', avoid mistakes, otherwise program won't work");
	scanf("%s", Infix);
	Push('#');
	while ((Char = Infix[i++]) != '\0')
	{
		if (Char == '(') 
			Push(Char);
		else if (isalnum(Char)) 
				Postfix[k++] = Char;
			else if (Char == ')')
			{
				while (Expn[StackNumber] != '(')
					Postfix[k++] = Pop();
				Element = Pop();
			}
			else
			{       
				while (OpPrecedence(Expn[StackNumber]) >= OpPrecedence(Char))
					Postfix[k++] = Pop();
				Push(Char);
			}
	}
	while (Expn[StackNumber] != '#')
		Postfix[k++] = Pop();

	Postfix[k] = '\0';
	printf("\n\nOur Infix Expression is %s  Postfix Expression: %s\n", Infix, Postfix);
	
	getchar(); getchar();
}

void Push(char elem)
{
	Expn[++StackNumber] = elem;
}

char Pop()
{
	return(Expn[StackNumber--]);
}

int OpPrecedence(char elem)
{
	switch (elem)
	{
	case '#': return 0;
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	}
}
