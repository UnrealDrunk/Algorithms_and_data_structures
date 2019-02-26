//С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int Month = 0;
	printf("Enter the Month number from 1 to 12: ");
	scanf("%d", &Month);
	puts("");
	if (Month == 12 || Month == 1 || Month == 2)
		printf("The season is Winter\n ");
	else if (Month >= 3 && Month < 6)
		printf("The season is Spring\n ");
	else if (Month >= 6 && Month < 9)
		printf("The season is Summer\n ");
	else if (Month >= 9 && Month < 12)
		printf("The season is Autumn\n ");
	else
		puts("You've entered wrong number");

	getchar(); getchar();
}
