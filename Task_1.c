//������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h); 
//��� m-����� ���� � �����������, h - ���� � ������.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
float BMI(int, float b);

int main()
{
	int Mass;
	float Height;
	printf("Enter the body mass in kilos: ");
	scanf("%d", &Mass);
	puts("");
	printf("Enter the body height in meters: ");
	scanf("%f", &Height);
	puts("");
	printf("The Body Mass Index is %.2f\n", BMI(Mass, Height));
	getchar(); getchar();
}

float BMI(int Mass, float height)
{
	float Result;
	Result = (float)Mass / (height*height);
	return Result;
}