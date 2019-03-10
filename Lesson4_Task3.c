//***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу. 

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

int i, j, n, nsqr, q;
int dx[9], dy[9], h[9][9];

void PrintField();
int t(int i, int x, int y);

int main()
{
	dx[1] = 2; dx[2] = 1; dx[3] = -1; dx[4] = -2;
	dx[5] = -2; dx[6] = -1; dx[7] = 1; dx[8] = 2;
	dy[1] = 1; dy[2] = 2; dy[3] = 2; dy[4] = 1;
	dy[5] = -1; dy[6] = -2; dy[7] = -2; dy[8] = -1;
	n = 5;       nsqr = n * n; // Здесь устанавливаем размер доски, в данном случаe 5х5, но программа сработает и с 8x8;
	system("cls");
	h[1][1] = 1;
	if (t(2, 1, 1) == 0) printf("\nNo Solutions");
	else PrintField();
	getchar();
}

void PrintField()
{
	int p, r;
	int Turns = 0;
	for (p = 1; p <= n; p++)
	{
		for (r = 1; r <= n; r++)
		{
			printf("%2d ", h[p][r]);
			if (Turns < h[p][r])
				Turns = h[p][r];
		}

		printf("\n");
	}
	printf("\n");
	printf("We need %d turns to get through every cell over the field\n", Turns);
}

int t(int i, int x, int y)
// возвращает 1, если доска заполнена, 0 - если нет продолжений
{
	int j, u, v, q1 = 0;
	for (j = 1; (!q1) && (j <= 8); j++)
	{
		u = x + dx[j];
		v = y + dy[j];
		if (1 <= u && u <= n && 1 <= v && v <= n && h[u][v] == 0)
		{
			h[u][v] = i;
			if (i < nsqr)
			{
				q1 = t(i + 1, u, v);
				if (q1 == 0) 
					h[u][v] = 0;
			}
			else q1 = 1;
		}
	}
	return q1;
}
