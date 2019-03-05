//Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной
//и не оптимизированной программы. 
//Написать функции сортировки, которые возвращают количество операций.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

void ArrSwap(int *a, int *b);
void ScanArr(int N, int* a);
void PrintArr(int N, int* a);
void BubbleSort(int N, int* a);
void ImproveBSort(int N, int*a);
// do not change zeros, otherwise counters will be broken
int Swaps_1 = 0;
int Swaps_2 = 0;
int Ops_1 = 0;
int Ops_2 = 0;

int main()
{
	int* Arr1;
	int* Arr2;
	int N;
	
	//using bubble sort
	puts("Input number of array's didgits and press Enter");
	scanf("%d", &N);
	Arr1 = (int*)malloc(N * sizeof(int));
	printf("Input %d didgits of Array and press Enter after putting each number\n", N);
	ScanArr(N, Arr1);
	puts("The Array is: ");
	PrintArr(N, Arr1);
	BubbleSort(N, Arr1);
	printf("\nThe Array after bubble sort:\n");
	PrintArr(N, Arr1);

	// Next we'll try to improve bubble sort
	Arr2 = (int*)malloc(N * sizeof(int));
	printf("\nInput %d didgits of Array 2 and press Enter after putting each number\n", N);
	ScanArr(N, Arr2);
	puts("The Array is: ");
	PrintArr(N, Arr2);
	ImproveBSort(N, Arr2);
	printf("\nThe Array after Improved bubble sort:\n");
	PrintArr(N, Arr2);
	puts("");
	printf("Program used %d Swaps and %d Operations for bubble sort of Array\n", Swaps_1, Ops_1);
	printf("Program used %d Swaps and %d Operations for improved bubble sort of Array\n", Swaps_2, Ops_2);

	free(Arr1);
	free(Arr2);
	getchar(); getchar();

}

void ArrSwap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

void BubbleSort(int N, int* Arr)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++)
		{
			Ops_1++;
			if (Arr[j] > Arr[j + 1])
			{
				ArrSwap(&Arr[j], &Arr[j + 1]);
				Swaps_1++;
			}
		}
			
}

void ImproveBSort(int N, int* Arr)
{
	for (int i = 0; i < N; i++)
	{
		int flag = 1;
		for (int j = 0; j < N - (i + 1); j++)
		{
			Ops_2++;
			if (Arr[j] > Arr[j + 1])
			{
				flag = 0;
				ArrSwap(&Arr[j], &Arr[j + 1]);
				Swaps_2++;
			}
		}
			if (flag == 1)
				break;		
	}

}
