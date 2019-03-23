//1.	Реализовать сортировку подсчётом

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>


//сортировка методом подсчета
void CountingSort(int n, int Arr[], int sortedMass[]);


int main()
{
	
	int N;
	puts("Input number of array's didgits and press Enter: ");
	scanf("%d", &N);
	int *Arr, *sortedArr;
	Arr = (int *)malloc(N * sizeof(int));
	sortedArr = (int *)malloc(N * sizeof(int));
	printf("Input the array elements:\n");
	for (int i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
	CountingSort(N, Arr, sortedArr);
	printf("Sorted array:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", sortedArr[i]);
	puts("");
	free(Arr);
	free(sortedArr);
	getchar(); getchar();
	
}
void CountingSort(int n, int Arr[], int sortedMass[])
{
	int k;
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < n; j++)
		{
			if (Arr[i] > Arr[j])
				k++;
		}
		sortedMass[k] = Arr[i];
	}
}
