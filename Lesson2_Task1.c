// –еализовать функцию перевода чисел из дес€тичной системы в двоичную, использу€ рекурсию.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void GetBinnary(int x);

int main()
{
	int x;
	puts("Input decimal numder X and press Enter");
	scanf("%d", &x);
	puts("");
	GetBinnary(x);
	getchar(); getchar();
}

void GetBinnary(int x)
{
	if (x != 0)
	{
		GetBinnary(x / 2);
		printf("%d ", x % 2);
	}
}