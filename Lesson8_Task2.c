//Реализовать быструю сортировку.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int n = 7;
int first, last;

void Quicksort(int *Arr, int first, int last);
void CopyArr(int N, int* Arr1, int* Arr2);

int main()
{

	int *Arr = (int*)malloc(n - sizeof(int));
	int *sortedArr = (int*)malloc(n - sizeof(int));
	srand((unsigned int)time(NULL));
	puts("Source Array");
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 10;
		printf("%d  ", Arr[i]);
	}
	first = 0; last = n - 1;
	Quicksort(Arr, first, last);
	CopyArr(n, Arr, sortedArr);
	
	printf("\nResult Array:\n");
	for (int i = 0; i < n; i++)
		printf("%d  ", sortedArr[i]);
	free(Arr);
	free(sortedArr);
	system("pause");
}

void Quicksort(int *Arr, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = Arr[(f + l) / 2];
	do
	{
		while (Arr[f] < mid) f++;
		while (Arr[l] > mid) l--;
		if (f <= l)
		{
			count = Arr[f];
			Arr[f] = Arr[l];
			Arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) Quicksort(Arr, first, l);
	if (f < last) Quicksort(Arr, f, last);
}

void CopyArr(int N, int* Arr1, int* Arr2)
{
	for (int i = 0; i < N; i++)
		Arr2[i] = Arr1[i];

}
