//*Реализовать шейкерную сортировку.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

void ScanArr(int N, int* a);
void PrintArr(int N, int* a);
void ArrSwap(int *a, int *b);
void CocktailSort(int N, int* a);

int main()
{
	int* Arr;
	int N;
	puts("Input number of array's didgits and press Enter");
	scanf("%d", &N);
	Arr = (int*)malloc(N * sizeof(int));
	printf("Input %d didgits of Array and press Enter after putting each number\n", N);
	ScanArr(N, Arr);
	puts("The Array is: ");
	PrintArr(N, Arr);
	CocktailSort(N, Arr);
	printf("\nThe Array after Cocktail sort:\n");
	PrintArr(N, Arr);

	getchar(); getchar();
}



void ScanArr(int N, int* Arr)
{
	for (int i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
}

void PrintArr(int N, int* Arr)
{
	for (int i = 0; i < N; i++)
		printf("%d  ", Arr[i]);
}

void ArrSwap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CocktailSort(int N, int* Arr)
{
	int sort_or_not = 1;
	int Right = N;
	int left = 0;

	do {
		sort_or_not = 1;
		for(int i = left; i < Right; i++)
			if (Arr[i - 1] > Arr[i])
			{
				ArrSwap(&Arr[i - 1], &Arr[i]);
				sort_or_not = 0;
			}
		Right--;
		for(int i = Right; i > left; i--)
			if (Arr[i] < Arr[i - 1])
			{
				ArrSwap(&Arr[i], &Arr[i-1]);
				sort_or_not = 0;
			}
		left++;

	} while (sort_or_not == 0);

}
