// Написать программу нахождения корней заданного квадратного уравнения.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int CalculateSquareEquity(int a, int b, int c, float* x1, float* x2)
{
	float D;
	D = (float)(pow(b, 2) + (4 * a * c));
	if (a == 0)
	{
		*x1 = (float)(-c / b);
		return 0;
	}
	else if (D > 0)
	{
		*x1 = (float)(-b + sqrt(D)) / (2 * a);
		*x2 = (float)(-b - sqrt(D)) / (2 * a);
		return 1;
	}
	else if (D == 0)
	{
		*x1 = (float)(-b / (2 * a));
		return 0;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	float x1 = 0;
	float x2 = 0;
	printf("This program will calculate square equation ax^2 + bx +c = 0 \n");
	printf(" Insert number a: ");
	scanf("%d", &a);
	printf("\n Insert number b: ");
	scanf("%d", &b);
	printf("\n Insert number c: ");
	scanf("%d", &c);

	int Result;
	Result = CalculateSquareEquity(a, b, c, &x1, &x2);
	switch (Result)
	{
	case 0:
		printf("Equation has just one unique root x = %.2f", x1);
		break;
	case -1:
		printf("The Equation has no roots");
		break;
	case 1:
		printf("The equation has two roots x1 = %.2f and x2 = %.2f", x1, x2);
		break;
	default:
		printf("Something went wrong %d", Result);

	}


	getchar(); getchar();
}
