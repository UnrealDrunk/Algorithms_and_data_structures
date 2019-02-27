// Ввести a и b и вывести квадраты и кубы чисел от a до b.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	int a, b;
	puts("Put numbers A and B and press Enter after putting each number");
	scanf("%d %d", &a, &b);
	puts("");
	puts("The numbers between A and B are:");
	if (a < b)
	{
		for (int i = a; i <= b; i++)
			printf("%d  ", i);
	}
	else
	{
		for (int i = a; i >= b; i--)
			printf("%d  ", i);
	}
	

	puts("");
	puts("The squares between numbers A and B");


	if (a < b)
	{
		for (int i = a; i <= b; i++)
		{
			i = (int)pow(i, 2);
			printf("%d  ", i);
			i = (int)sqrt(i);
		}

	}
	else if (a > b)
	{
		for (int i = a; i >= b; i--)
		{
			i = (int)pow(i, 2);
			printf("%d  ", i);
			i = (int)sqrt(i);
		}

	}
	puts("");
	puts("The same numbers...cubed");

	if (a < b)
	{
		for (double i = a; i <= b; i++)
		{
			i = pow(i, 3);
			printf("%.0f  ", i);
			i = pow(i, 1.0/3);
		}

	}
	else if (a > b)
	{
		for (double i = a; i >= b-1; i--)
		{
			i = (pow(i, 3));
			printf("%.0f  ", i);
			i = pow(i, 1.0/3);
		}

	}


	getchar(); getchar();

	




}
