//Найти максимальное из четырех чисел. Массивы не использовать.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Max_Num(int a, int b, int c, int d);

int main()
{
	int A, B, C, D;

	printf("Enter four numbers; press enter after recording each number:\n");
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("The Maximum number is %d", Max_Num(A, B, C, D));
	getchar(); getchar();

}

int Max_Num(int a, int b, int c, int d)
{
	int Result = 0;

	if (Result < a)
		Result = a;
	if (Result < b)
		Result = b;
	if (Result < c)
		Result = c;
	if (Result < d)
		Result = d;
		
	return Result;
}
