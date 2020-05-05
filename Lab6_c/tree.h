#pragma once
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

#ifndef TREE
#define TREE

typedef struct _string
{
	char* str;
	int size;
}String;

void input(String* string)
{
	char flag = 1;
	char* str = NULL; size_t size = 32;
	if ((str = (char*)malloc(size)) == NULL)
		printf("Unable to allocate 256 bytes of memory for character buffer\n");

	int n = 0;

	while (flag)
	{
		char ch = 'o';
		while (n < size && flag)
		{
			if (ch == 13)
			{
				flag = 0;
				str[n] = '\0';
				++n;
				break;
			}
			else
			{
				ch = _getch();
				str[n] = ch;
				printf("%c", str[n++]);
			}
		}

		if ((str = (char*)realloc(str, size + 32)) == NULL)
			printf("Unable to reallocate memory for character buffer\n");

		size += 32;
	}

	string->size = n - 2;
	string->str = str;
}

typedef struct _tree_item
{
	struct _tree_item* left;
	struct _tree_item* right;
	char symbol;
}TreeItem;

void TreeInit(TreeItem* item, int symbol)
{
	item->symbol = symbol;
	item->left = NULL;
	item->right = NULL;
}

void AddItem(TreeItem* item, int symbol)
{
	if (item == NULL)
	{
		item = (TreeItem*)malloc(sizeof(TreeItem));
		item->symbol = symbol;
		item->left = item->right = NULL;
	}
	else
	{
		if (item->symbol < symbol)
		{
			if (item->right != NULL)
			{
				AddItem(item->right, symbol);
			}
			else
			{
				item->right = (TreeItem*)malloc(sizeof(TreeItem));
				item->right->symbol = symbol;
				item->right->left = item->right->right = NULL;
			}
		}
		else if (item->symbol >= symbol)
		{
			if (item->left != NULL)
			{
				AddItem(item->left, symbol);
			}
			else
			{
				item->left = (TreeItem*)malloc(sizeof(TreeItem));
				item->left->symbol = symbol;
				item->left->left = item->left->right = NULL;
			}
		}
		else
			printf("Tree item insert fault");
	}
}

void TreeConstruct(TreeItem* item, String* str)
{
	int size;
	printf("Set string\n");
	input(str);
	size = str->size;
	TreeInit(item, str->str[0]);
	for (size_t i = 1; i < size; i++)
	{
		AddItem(item, str->str[i]);
	}
}

void countLeaves(TreeItem* item, int* amount)
{
	if (item != NULL)
	{
		if ((item->left == NULL) && (item->right == NULL))
		{
			(*amount)++;
		}
		else
		{
			countLeaves(item->left, amount);
			countLeaves(item->right, amount);
		}
	}
}

void ShowTree(TreeItem* item)
{
	if (item != NULL)
	{
		ShowTree(item->left);
		printf("%c", item->symbol);
		ShowTree(item->right);
	}
}

void PrintTree(TreeItem* tree, int r)//функция вывода дерева где r-уровень
{
	if (tree->right != NULL)
		PrintTree(tree->right, ++r);
	for (int i = 0; i < (4 * r); i++)
		printf(" ");
	printf("%c\n", tree->symbol);
	if (tree->left != NULL)
		PrintTree(tree->left, ++r);
	--r;
}


#endif