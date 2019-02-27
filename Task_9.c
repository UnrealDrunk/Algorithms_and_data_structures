//Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K,
//а также остаток от этого деления.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int N, K, Quot, Rem, a, b;
	puts("put number N and press Enter");
	scanf("%d", &N);
	puts("put number K and press Enter");
	scanf("%d", &K);
	Quot = 0;
	a = N;
	b = K;
	while (a >= b)
	{
		Quot++;
		a -= b;
	}
	Rem = a;

	printf("Quotient from division %d and %d = %d\n", N, K, Quot);
	printf("Remainder of the division %d and %d = %d\n", N, K, Rem);

	getchar(); getchar();
}
