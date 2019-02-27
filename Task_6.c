// ¬вести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом Ђгодї, Ђгодаї или Ђлетї.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "RU");
	int Age, N1, N2;
	printf("¬ведите возраст человека от 1 до 150\n");
	scanf("%d", &Age);
	N1 = Age % 10;
	N2 = Age % 100;
	
	if (N1 == 1 && N2 != 11)
		printf("ѕерсоне %d год", Age);
	if (N1 >= 2 && N1 <= 4 && (N2 <10 || N2 > 20))
		printf("ѕерсоне %d года", Age);
	else
		printf("ѕерсоне %d лет", Age);
	

	getchar(); getchar();
}