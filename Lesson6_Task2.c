//Переписать программу, реализующее двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска
//в) *Добавить в программу обработку командной строки с помощью которой можно указывать
//из какого файла считывать данные, каким образом обходить дерево.

/*
 *
 *                     40
 *                    /  \
 *                   20   60
 *                  /  \   \
 *                 10  30   80
 *                           \
 *                           90
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct btnode
{
	int value;
	struct btnode *left;
	struct btnode *right;
}*root = NULL, *temp = NULL;

typedef struct btnode N;
void insert();
N* bt(int arr[], int, int);
N* new(int);
void inorder(N *t);
void createNode();
void searchPos(N *t);
void preorder(N *t);
void postorder(N *t);
void searchElem(int* arr, int n);

void main()
{
	int orderChoice, i, n;
	int arr[] = { 10, 20, 30, 40, 60, 80, 90 };
	n = sizeof(arr) / sizeof(arr[0]);

	printf("\n1- Inorder\n");
	printf("2 - postorder\n");
	printf("\nEnter choice : ");
	scanf("%d", &orderChoice);
	switch (orderChoice)
	{
	case 1:
		root = bt(arr, 0, n - 1);
		printf("Given inorder traversal as input\n");
		for (i = 0; i <= 6; i++)
			printf("%d->", arr[i]);
		printf("\npreorder traversal of tree\n");
		preorder(root);
		printf("\ninorder traversal of tree\n");
		inorder(root);
		printf("\npostorder traversal of tree\n");
		postorder(root);
		puts("");
		break;
	case 2:
		insert();
		printf("\npreorder traversal of tree\n");
		preorder(root);
		printf("\nInorder traversal of tree\n");
		inorder(root);
		printf("\npostorder traversal of tree\n");
		postorder(root);
		puts("");
		break;
	default:printf("enter correct choice");
	}
	searchElem(arr, n);
	

	getchar(); getchar();
}

/* Создать новый узел*/
N* new(int val)
{
	N* node = (N*)malloc(sizeof(N));

	node->value = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* Создать сбалансированное бинарное дерево поиска */
N* bt(int arr[], int first, int last)
{
	int mid;

	N* root = (N*)malloc(sizeof(N));
	if (first > last)
		return NULL;
	mid = (first + last) / 2;
	root = new(arr[mid]);
	root->left = bt(arr, first, mid - 1);
	root->right = bt(arr, mid + 1, last);
	return root;
}

/* Вставить узел в дерево */
void insert()
{
	int arr1[] = { 10, 30, 20, 90, 80, 60, 40 }, i;

	printf("Given post order traversal array\n");
	for (i = 0; i <= 6; i++)
	{
		printf("%d->", arr1[i]);
	}
	for (i = 6; i >= 0; i--)
	{
		createNode(arr1[i]);
		if (root == NULL)
			root = temp;
		else
			searchPos(root);
	}
}

/* Создать узел */
void createNode(int data)
{
	temp = (N *)malloc(1 * sizeof(N));

	temp->value = data;
	temp->left = temp->right = NULL;
}

/* Поиск подходящей позиции для вставки нового узла */
void searchPos(N *t)
{
	if ((temp->value > t->value) && (t->right != NULL))
		searchPos(t->right);
	else if ((temp->value > t->value) && (t->right == NULL))
		t->right = temp;
	else if ((temp->value < t->value) && (t->left != NULL))
		searchPos(t->left);
	else if ((temp->value < t->value) && (t->left == NULL))
		t->left = temp;
}

/* Симметричный обход дерева */
void inorder(N *t)
{
	if (t->left != NULL)
		inorder(t->left);
	printf("%d->", t->value);
	if (t->right != NULL)
		inorder(t->right);
}

/* отобразить обход дерева в прямом порядке */
void preorder(N *t)
{
	printf("%d->", t->value);
	if (t->left != NULL)
		inorder(t->left);
	if (t->right != NULL)
		inorder(t->right);
}

/* Отобразить обход дерева в обратном порядке */
void postorder(N *t)
{
	if (t->left != NULL)
		inorder(t->left);
	if (t->right != NULL)
		inorder(t->right);
	printf("%d->", t->value);
}


/* Поиск элемента в дереве */
void searchElem(int* arr, int n)
{
	int x, flag = 0;
	printf("Insert th element to search in tree: ");
	scanf("%d", &x);
	for (int i = 0; i <= n; i++)
	{
		if (x == arr[i])
		{
			flag = 1;
		}
			
	}
	if (flag ==1)
		puts("The element was found in the tree");
	else
		puts("The element was NOT found in the tree");
	
}
