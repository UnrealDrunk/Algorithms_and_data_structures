//Написать программу обмена значениями двух целочисленных переменных:
// a. с использованием третьей переменной;
// *без использования третьей переменной.

#include<stdio.h>

int main()
{
	int A = 3;
	int B = 29;
	printf("Before  rotation  A = %d, B = %d\n", A, B);
	int buffer = 0;
	buffer = A;
	A = B;
	B = buffer;
	printf("After rotation using third variable - buffer,  A = %d, B = %d\n", A, B);

	printf("Let's rotate another 2 variables without third variable\n");

	int C = 4;
	int D = 58;
	printf("Before  rotation  C = %d, D = %d\n", C, D);
	C = C + D;
	D = C - D;
	C = C - D;

	printf("After rotation using just two variables,  C = %d, D = %d\n", C, D);


	getchar();
}

