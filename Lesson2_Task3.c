//Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
//Первая: Прибавь 1. Вторая: умножь на 2. Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. 
//Сколько существует программ, которые число 3 преобразуют в число 20? 
//а) с использованием массива; б) с использованием рекурсии.

#include<stdio.h>
int Count_Arr();
int Count_Rec(int x);

int main()
{
	printf("The result of counting programs using array - %d programs\n", Count_Arr());
	printf("The result of counting programs using recursion - %d programs\n ", Count_Rec(20));

	getchar();
}

int Count_Arr()
{
	int Arr[21];
	Arr[2] = 0;
	Arr[3] = 1;
	for (int i = 4; i < 21; i++)
	{
		if (i % 2 == 0)
			Arr[i] = Arr[i - 1] + Arr[i / 2];
		else
			Arr[i] = Arr[i - 1];
	}
	return Arr[20];
}

int Count_Rec(int x)
{
	if (x == 2)
		return 0;
	else if (x == 3)
		return 1;
	else if (x % 2 == 0)
		return Count_Rec(x - 1) + Count_Rec(x / 2);
	else
		return Count_Rec(x - 1);

}
