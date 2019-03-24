// Реализовать сортировку слиянием.

#include <iostream>
using namespace std;

void Merge(int *Arr, int first, int last);

void MergeSort(int *Arr, int first, int last);


int main()
{
	int N;
	int *Arr = new int[100];
	cout << "Size of Array > "; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cout << i << " Element > "; cin >> Arr[i];
	}
	MergeSort(Arr, 1, N); 
	cout << "Sorted Array: "; 
	for (int i = 1; i <= N; i++)
	{
		cout << Arr[i] << " ";
	}
	delete[]Arr;
	system("pause");
}

void Merge(int *Arr, int first, int last)
{
	int middle, start, final, j;
	int *mas = new int[100];
	middle = (first + last) / 2; //Middle element
	start = first; //Left side
	final = middle + 1; //Right side
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (Arr[start] < Arr[final])))
		{
			mas[j] = Arr[start];
			start++;
		}
		else
		{
			mas[j] = Arr[final];
			final++;
		}

	for (j = first; j <= last; j++) Arr[j] = mas[j];
	delete[]mas;
}

void MergeSort(int *Arr, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(Arr, first, (first + last) / 2); //Sorting left side
			MergeSort(Arr, (first + last) / 2 + 1, last); //Sorting right side
			Merge(Arr, first, last); //Merging 2 sides
		}
	}
}
