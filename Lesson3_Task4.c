//*Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

void ArrSwap(int *a, int *b);
void ScanArr(int N, int* a);
void PrintArr(int N, int* a);
void BubbleSort(int N, int* a);
void ImproveBSort(int N, int*a);
void ReloadOpsSwaps();
void CopyArr(int N, int* a1, int* a2);
void CocktailSort(int N, int* a);
void SelectionSort(int N, int* a);


int Swaps = 0, Ops = 0;

int main()
{
	int* Arr_for_BS;
	int* Arr_for_IbS;
	int* Arr_for_CS;
	int* Arr_for_SS;


	int N;

	puts("Input number of array's didgits and press Enter");
	scanf("%d", &N);
	printf("Input %d didgits of Array and press Enter after putting each number\n", N);

	Arr_for_BS = (int*)malloc(N * sizeof(int));
	ScanArr(N, Arr_for_BS);

	Arr_for_IbS = (int*)malloc(N * sizeof(int));
	CopyArr(N, Arr_for_BS, Arr_for_IbS);

	Arr_for_CS = (int*)malloc(N * sizeof(int));
	CopyArr(N, Arr_for_BS, Arr_for_CS);

	Arr_for_SS = (int*)malloc(N * sizeof(int));
	CopyArr(N, Arr_for_BS, Arr_for_SS);

	puts("The Array for Bubble sorting  is: ");
	PrintArr(N, Arr_for_BS);
	printf("\nThe Array for Improved bubble sorting  is:\n");
	PrintArr(N, Arr_for_IbS);
	printf("\nThe Array for Cocktail sorting  is:\n");
	PrintArr(N, Arr_for_CS);
	printf("\nThe Array for Selection sorting  is:\n");
	PrintArr(N, Arr_for_SS);

	puts("");

	BubbleSort(N, Arr_for_BS);
	printf("\nThe Array after bubble sort:\n");
	PrintArr(N, Arr_for_BS);
	printf("\nProgram used %d Swaps and %d Operations for bubble sort of Array\n", Swaps, Ops);

	ReloadOpsSwaps();
	
	ImproveBSort(N, Arr_for_IbS);
	printf("\nThe Array after Improved bubble sort:\n");
	PrintArr(N, Arr_for_IbS);
	printf("\nProgram used %d Swaps and %d Operations for Improved bubble sort of Array\n", Swaps, Ops);

	ReloadOpsSwaps();

	CocktailSort(N, Arr_for_CS);
	printf("\nThe Array after Cocktail  sort:\n");
	PrintArr(N, Arr_for_CS);
	printf("\nProgram used %d Swaps and %d Operations for Cocktail sort of Array\n", Swaps, Ops);

	ReloadOpsSwaps();

	SelectionSort(N, Arr_for_SS);
	printf("\nThe Array after Selection  sort:\n");
	PrintArr(N, Arr_for_CS);
	printf("\nProgram used %d Swaps and %d Operations for Selection sort of Array\n", Swaps, Ops);


	free(Arr_for_BS);
	free(Arr_for_IbS);
	free(Arr_for_CS);
	free(Arr_for_SS);

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
			Ops++;
			if (Arr[j] > Arr[j + 1])
			{
				ArrSwap(&Arr[j], &Arr[j + 1]);
				Swaps++;
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
			Ops++;
			if (Arr[j] > Arr[j + 1])
			{
				flag = 0;
				ArrSwap(&Arr[j], &Arr[j + 1]);
				Swaps++;
			}
		}
		if (flag == 1)
			break;
	}

}

void ReloadOpsSwaps()
{
	Ops = 0;
	Swaps = 0;

}

void CopyArr(int N, int* Arr1, int* Arr2)
{
	for (int i = 0; i < N; i++)
		Arr2[i] = Arr1[i];

}
void CocktailSort(int N, int* Arr)
{
	int sort_or_not = 1;
	int Right = N;
	int left = 0;

	do {
		sort_or_not = 1;
		for (int i = left; i < Right; i++)
		{
			Ops++;
			if (Arr[i - 1] > Arr[i])
			{
				ArrSwap(&Arr[i - 1], &Arr[i]);
				sort_or_not = 0;
				Swaps++;
			}
		}
		Right--;
		for (int i = Right; i > left; i--)
		{
			Ops++;
			if (Arr[i] < Arr[i - 1])
			{
				ArrSwap(&Arr[i], &Arr[i - 1]);
				sort_or_not = 0;
				Swaps++;
			}
		}
		left++;

	} while (sort_or_not == 0);

}

void SelectionSort(int N, int* Arr)
{
	
	int jmin;
	for (int i = 0; i < N; i++)
	{
		jmin = i;
		for (int j = i + 1; j < N; j++)
		{
			Ops++;
			if (Arr[j] < Arr[jmin])
				jmin = j;
		}
		ArrSwap(&Arr[i], &Arr[jmin]);
		Swaps++;
		
	}

}
