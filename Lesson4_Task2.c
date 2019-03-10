// Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

#define N 30
#define max(a,b) ((a>b) ? a : b)
int L[N][N];

int main()
{
	char Sequence_1[N] = "GEEKBRAINS";
	char Sequence_2[N] = "GEEKMINDS";
	printf("The Sequence 1 is %s\n", Sequence_1);
	printf("The Sequence 2 is %s\n", Sequence_2);
	int Len_1, Len_2;
	int FirstMatch = 0;

	/*scanf("%s", Sequence_1);
	scanf("%s", Sequence_2);*/ // В качестве альтренативы можем каждый раз вводить новые последовательности с клавиатуры

	Len_1 = strlen(Sequence_1);
	Len_2 = strlen(Sequence_2);

	for (int j = 0; j < Len_2; j++)
	{
		if (Sequence_2[j] == Sequence_1[0])
			FirstMatch = 1;
		L[0][j] = FirstMatch;
	}
	FirstMatch = 0;
	for (int i = 0; i < Len_1; i++)
	{
		if (Sequence_1[i] == Sequence_2[0])
			FirstMatch = 1;
		L[i][0] = FirstMatch;
	}

	for (int i = 1; i < Len_1; i++)
	{
		for (int j = 1; j < Len_2; j++)
		{

			if (Sequence_1[i] == Sequence_2[j])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	printf("\nThe Longest Common Subsequence is %d\n", L[Len_1 - 1][Len_2 - 1]);

	getchar(); getchar();

}
