//3.	Написать функцию обхода графа в ширину

#include <iostream>
using namespace std;
const int N = 4;
/*
Граф  
       1 - - - -2
	   |       /  |
	   |	   /    |
	   |	 /      |
	   |	/       |
	   | /        |
	    3  ------4  


*/

//матрица смежности графа
int GM[N][N] =
{
{0, 1, 1, 0},
{0, 0, 1, 1},
{1, 0, 0, 1},
{0, 1, 0, 0}
};

void Breadth_First_Search(bool *visited, int unit);

int main()
{
	int start;
	bool *visited = new bool[N];
	cout << "Graph adjacency matrix: " << endl;
	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
		for (int j = 0; j < N; j++)
			cout << " " << GM[i][j];
		cout << endl;
	}
	cout << "Choose starting peak from 1 to " << N << " - ";
	cin >> start;
	while (start < 1 || start > N)
	{
		cout << endl << "You've chosen wrong peak" << endl;
		cout << "Choose starting peak from 1 to " << N << " - ";
		cin >> start;
	}

	cout << "Bypass order: ";
	Breadth_First_Search(visited, start - 1);
	cout << endl;
	delete[]visited;
	system("pause");
}

void Breadth_First_Search(bool *visited, int unit)
{
	int *queue = new int[N];
	int count, head;
	for (int i = 0; i < N; i++)
		queue[i] = 0;
	count = 0; head = 0;
	queue[count++] = unit;
	visited[unit] = true;
	while (head < count)
	{
		unit = queue[head++];
		cout << unit + 1 << " ";
		for (int i = 0; i < N; i++)
			if (GM[unit][i] && !visited[i])
			{
				queue[count++] = i;
				visited[i] = true;
			}
	}
	delete[]queue;
}
