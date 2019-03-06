//Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
//Функция возвращает индекс найденного элемента или -1, если элемент не найден.


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

void ScanArr(int N, int* a);
void PrintArr(int N, int* a);
void ArrSwap(int *a, int *b);
void ImproveBSort(int N, int*a);
int BinnarySearch(int N, int*a, int b);

int main()
{
	int* Arr1;
	int N;
	puts("Input number of array's didgits and press Enter");
	scanf("%d", &N);
	Arr1 = (int*)malloc(N * sizeof(int));
	printf("Input %d didgits of Array and press Enter after putting each number\n", N);
	ScanArr(N, Arr1);
	puts("The Array is: ");
	PrintArr(N, Arr1);
	ImproveBSort(N, Arr1);
	printf("\nThe Array after bubble sort:\n");
	PrintArr(N, Arr1);

	int SearchValue;
	printf("\nInput value for search in array and press Enter\n");
	scanf("%d", &SearchValue);
	printf("The result: Searched number %d was found in Array's postion index %d", SearchValue, BinnarySearch(N, Arr1, SearchValue));

	free(Arr1);

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

void ImproveBSort(int N, int* Arr)
{
	for (int i = 0; i < N; i++)
	{
		int flag = 1;
		for (int j = 0; j < N - (i + 1); j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				flag = 0;
				ArrSwap(&Arr[j], &Arr[j + 1]);
			}
		}
		if (flag == 1)
			break;
	}

}

int BinnarySearch(int N, int* Arr, int SearchValue)
{
	int Left = 0, Right = N - 1;
	int Mid = Left + (Right - Left) / 2;
	while (Left <= Right && Arr[Mid] != SearchValue)
	{
		if (Arr[Mid] < SearchValue)
			Left = Mid + 1;
		else
			Right = Mid - 1;
		Mid = Left + (Right - Left) / 2;
	}
	if (Arr[Mid] == SearchValue)
		return Mid;
	else
		return -1;

}
