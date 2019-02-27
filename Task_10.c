//Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, 
//имеются ли в записи числа N нечетные цифры. 
//Если имеются, то вывести True, если нет — вывести False.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void CheckDidgit(int a);

int main()
{
	int N;
	puts("Put number and press Enter:");
	scanf("%d", &N);
	CheckDidgit(N);

	getchar(); getchar();
}

void CheckDidgit(int a)
{
	int Check = 0;
	while (a >= 1)
	{
		Check = a % 10;
		if (Check % 2 != 0)
		{
			printf("The didgit %d contains odd number - True", a);
			break;
		}
		else
		{
			printf("The didgit %d doesn't contain odd number - False", a);
			break;
		}

	}
}
