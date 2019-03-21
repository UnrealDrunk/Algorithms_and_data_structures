//1.	Написать функции, которые считывают матрицу смежности из файла и выводят её на экран.

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	/*Считаем граф из файла(как в методичке), текстовый файл также размещен в GitHub*/
	ifstream in("Lesson7_Task1.txt");

	if (in.is_open())
	{
		/*Мы не знаем размер матрицы, заложенной в файле. Для начала, нужно установить эту информацию
		Вначале посчитаем сколько чисел в файле*/

		int Nums_Count = 0;
		int temp;

		while (!in.eof())
		{
			in >> temp;
			Nums_Count++;
		}

		/*Количество чисел посчитано, теперь нам нужно понять сколько чисел в одной строке
		Для этого посчитаем число пробелов до знака перевода на новую строку*/

		// Переведем каретку в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof())
		{
			/*считываем символы, отлавливаем пробелы и переходы на новую строку*/
			in.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}


		//Снова переходим в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Теперь мы знаем количество чисел в файле и количество пробелов в первой строке.
		// Можем считать матрицу смежности.

		int Quantity_Strings = Nums_Count / (count_space + 1);
		int Quan_Columns = count_space + 1;
		double **Adjacency_M;
		Adjacency_M = new double*[Quantity_Strings];
		for (int i = 0; i < Quantity_Strings; i++)
			Adjacency_M[i] = new double[Quan_Columns];

		//Считаем матрицу из файла
		for (int i = 0; i < Quantity_Strings; i++)
			for (int j = 0; j < Quan_Columns; j++)
				in >> Adjacency_M[i][j];

		//Выведем матрицу консоль
		for (int i = 0; i < Quantity_Strings; i++)
		{
			for (int j = 0; j < Quan_Columns; j++)
				cout << Adjacency_M[i][j] << "  ";
			cout << "\n";
		}

		for (int i = 0; i < Quantity_Strings; i++)
			delete[] Adjacency_M[i];
		delete[] Adjacency_M;

		in.close();
	}
	else
	{
		//Если файл не найден
		cout << "file wasn't found"<< endl;
	}

	system("pause");
	
}
