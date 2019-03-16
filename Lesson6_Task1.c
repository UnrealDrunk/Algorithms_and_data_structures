//1.	Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе получается сумма кодов символов.
// В данной программе реализуем несколько различных хэш функций

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<malloc.h>

const int MaxLenStr = 50;
unsigned int Hash37(const char* str);
unsigned int HashFAQ6(const char * str);
unsigned int HashRot13(const char * str);
unsigned int HashLy(const char * str);
unsigned int HashRs(const char * str);

int main()
{
	printf("Create your Password\n");
	char* Password;
	Password = (char*)malloc(MaxLenStr);
	gets_s(Password, MaxLenStr);
	printf("Your password is %s\n", Password);
	printf("Using Hash 37 code %d\n", Hash37(Password));
	printf("Using Hash FAQ6 code %d\n", HashFAQ6(Password));
	printf("Using Hash Rot13 code %d\n", HashRot13(Password));
	printf("Using Hash Ly code %d\n", HashLy(Password));
	printf("Using Hash Rs code %d\n", HashRs(Password));

	free(Password);
	getchar(); getchar();
}
unsigned int Hash37(const char* str)
{
	unsigned int hash = 2139062143;

	for (; *str; str++)
		hash = 37 * hash + *str;

	return hash;

}

unsigned int HashFAQ6(const char * str)
{
	unsigned int hash = 0;

	for (; *str; str++)
	{
		hash += (unsigned char)(*str);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;

}
unsigned int HashRot13(const char * str)
{
	unsigned int hash = 0;

	for (; *str; str++)
	{
		hash += (unsigned char)(*str);
		hash -= (hash << 13) | (hash >> 19);
	}

	return hash;

}

unsigned int HashLy(const char * str)
{
	unsigned int hash = 0;

	for (; *str; str++)
		hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;

	return hash;

}
unsigned int HashRs(const char * str)
{
	static const unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	for (; *str; str++)
	{
		hash = hash * a + (unsigned char)(*str);
		a *= b;
	}

	return hash;

}
