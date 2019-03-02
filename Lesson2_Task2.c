//Реализовать функцию возведения числа a в степень b:
//Без рекурсии.
//Рекурсивно.
//*Рекурсивно, используя свойство чётности степени.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int JustPowered(int a, int b);
int RecursionPowered(int a, int b);
int EvenPowered(int a, int b);

int main()
{
	int x, y;
	puts("Input numbers X and Y and press Enter after putting each number");
	scanf("%d %d", &x, &y);
	puts("");
	printf("Without Recursion - Number X powered to Y is: %d\n", JustPowered(x, y));
	printf("Using Recursion - Number X powered to Y is: %d\n", RecursionPowered(x, y));
	printf("Using Recursion and Even - Number X powered to Y is: %d\n", EvenPowered(x, y));

	getchar(); getchar();
}

int JustPowered(int x, int y)
{
	int Result = 1;
	if (x == 0)
		return 0;

	while (y)
	{
		Result *= x;
		y--;
	}
	return Result;
}

int RecursionPowered(int x, int y)
{
	if (y == 0 && x != 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return x * RecursionPowered(x, y - 1);
}

int EvenPowered(int x, int y)
{
	int Result = 1;

	if (y == 0 && x != 0)
		return 1;
	else if (x == 0)
		return 0;
	else if (y % 2 == 0)
	{
		Result = EvenPowered(x, y / 2);
		return Result * Result;
	}
	else
	{
		return x * EvenPowered(x, y - 1);
	}

}
