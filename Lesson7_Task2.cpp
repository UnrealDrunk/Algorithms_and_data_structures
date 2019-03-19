// 2.	Написать рекурсивную функцию обхода графа в глубину.

#include <iostream>

using namespace std;
const int N = 5;
bool *visited = new bool[N];
/* Граф
               1
             /   \
	    /     \
	   /   3   \
	  /  /    \ \
	 5-----4-----2

*/

//матрица смежности графа
int graph[N][N] =
{
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0},
{0, 1, 0, 0, 1},
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0}
};

void Depth_First_Search(int start);

int main()
{
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Graph adjacency matrix: " << endl;
	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
		for (int j = 0; j < N; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Choose starting peak from 1 to "<< N <<" - "; 
	
	cin >> start;
	while (start < 1 || start > N)
	{
		cout << endl << "You've chosen wrong peak" << endl;
		cout << "Choose starting peak from 1 to " << N << " - ";
		cin >> start;
	} 

	//массив посещенных вершин
	bool *vis = new bool[N];
	cout << "Bypass order: ";
	Depth_First_Search(start - 1);
	cout << endl;
	delete[]visited;
	system("pause");
}
void Depth_First_Search(int start)
{
	cout << start + 1 << " ";
	visited[start] = true;
	for (int i = 0; i <= N; i++)
		if ((graph[start][i] != 0) && (!visited[i]))
			Depth_First_Search(i);
}
