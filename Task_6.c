// ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "RU");
	int Age, N1, N2;
	printf("������� ������� �������� �� 1 �� 150\n");
	scanf("%d", &Age);
	N1 = Age % 10;
	N2 = Age % 100;
	
	if (N1 == 1 && N2 != 11)
		printf("������� %d ���", Age);
	if (N1 >= 2 && N1 <= 4 && (N2 <10 || N2 > 20))
		printf("������� %d ����", Age);
	else
		printf("������� %d ���", Age);
	

	getchar(); getchar();
}