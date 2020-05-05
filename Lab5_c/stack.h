#pragma once
#include "queue.h"

typedef struct _stack_node
{
	void* pPrev;
	Queue* data;
}StackNode;

typedef struct _stack
{
	void* offsetPtr;
	int size;
}Stack;

void StackInit(Stack* stack)
{
	stack->size = 0;
	stack->offsetPtr = NULL;
}

void push(Stack* stack, Queue* data)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->pPrev = stack->offsetPtr;
	newNode->data = data;
	stack->offsetPtr = newNode;
	stack->size++;
}

void pop(Stack* stack)
{
	if (!stack->size)
		return;
	else
	{
		StackNode* toDelete = (StackNode*)stack->offsetPtr;
		stack->offsetPtr = toDelete->pPrev;
		free(toDelete);
		stack->size--;
	}
}

Queue* peek(Stack* stack)
{
	return ((StackNode*)stack->offsetPtr)->data;
}

void PrintStack(Stack* stack)
{
	int i = 0;
	while (stack->size)
	{
		printf("\n%d,Queue address %d\n", i, stack->offsetPtr);
		PrintQueue((Queue*)stack->offsetPtr);
		pop(stack);
	}
}

void StackDestroy(Stack* stack)
{
	while (stack->size)
		pop(stack);
}