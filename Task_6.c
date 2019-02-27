// Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "RU");
	int Age, N1, N2;
	printf("Введите возраст человека от 1 до 150\n");
	scanf("%d", &Age);
	N1 = Age % 10;
	N2 = Age % 100;
	
	if (N1 == 1 && N2 != 11)
		printf("Персоне %d год", Age);
	if (N1 >= 2 && N1 <= 4 && (N2 <10 || N2 > 20))
		printf("Персоне %d года", Age);
	else
		printf("Персоне %d лет", Age);
	

	getchar(); getchar();
}
