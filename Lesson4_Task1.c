// Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
// В условии задаачи предложено использовать матрицу 3х3, но получается не очень репрезентативно.
// Поэтому мною была сотсавлена матрица 5х5

#include <stdio.h>
#define N 5
#define M 5

void PrintWays(int n, int m, int Arr[N][M]);


int main()
{
	int MAP[N][M] =
	{ {1,1,1,1,0},
	  {0,1,1,0,0},
	  {0,0,1,1,1},
	  {0,1,1,1,1},
	  {0,1,1,1,1} };

	int Arr[N][M];
	for (int j = 0; j < M; j++)
	{
		if (MAP[0][j] == 1)
			Arr[0][j] = 1;
		else
			Arr[0][j] = 0;
	}

	for (int i = 1; i < N; i++)
	{
		if(MAP[i][0] ==1)
			Arr[i][0] = 1;
		else
			Arr[i][0] = 0;

		for (int j = 1; j < M; j++)
		{
			if (MAP[i][j] == 1)
				Arr[i][j] = Arr[i][j - 1] + Arr[i - 1][j];
			else
				Arr[i][j] = 0;
		}
			
	}
	PrintWays(N, M, Arr);
	getchar();

}

void PrintWays(int n, int m, int Arr[N][M])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%4d", Arr[i][j]);
		printf("\n");
	}
}
