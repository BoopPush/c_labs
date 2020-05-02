#include "stdlib.h"
#include "stdio.h"

typedef struct _node
{
	int value;
	struct _node* pPrev;
	struct _node* pNext;
}Node;

typedef struct _queue
{
	int size;
	struct _node* head;
	struct _node* tail;
}Queue;

void QueueConstruct(Queue* queue)
{
	queue->size = 0;
	queue->head = queue->tail = NULL;
}

void pop_front(Queue* queue)
{
	if (!queue->size)
		return;
	Node* toDelete = queue->head;
	queue->head = toDelete->pNext;
	queue->head->pPrev = NULL;
	free(toDelete);
	queue->size--;
}

void push_back(Queue* queue, int value)
{
	if (queue->size)
	{
		Node* newTail = (Node*)malloc(sizeof(Node));
		newTail->pNext = NULL;
		newTail->pPrev = queue->tail;
		newTail->value = value;
		queue->tail->pNext = newTail;
		queue->tail = newTail;
		queue->size++;
	}
	else
	{
		queue->tail = (Node*)malloc(sizeof(Node));
		queue->tail->value = value;
		queue->head = queue->tail;
		queue->head->pPrev = NULL;
		queue->tail->pNext = NULL;
		queue->size++;
	}
}

int at(Queue* queue, int pos)
{
	if ((pos < (queue->size) / 2) && (pos < queue->size))
	{
		Node* _ptr = queue->head;
		for (int i = 0; i < pos; ++i)
		{
			_ptr = _ptr->pNext;
		}
		return _ptr->value;
	}
	else if (pos < queue->size)
	{
		Node* _ptr = queue->tail;
		for (int i = queue->size - 1; i > pos; --i)
		{
			_ptr = _ptr->pPrev;
		}
		return _ptr->value;
	}
}

void PrintQueue(Queue* queue)
{
	Node* current = queue->head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->pNext;
	}
}

int QueueSum(Queue* queue)
{
	int sum = 0;
	Node* current = queue->tail;
	while (current != NULL)
	{
		sum += current->value;
		current = current->pPrev;
	}
	return sum;
}

int QueueMax(Queue* queue)
{
	int max = queue->head->value;
	Node* current = queue->head->pNext;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->pNext;
	}
	return max;
}

void QueueDestroy(Queue* queue)
{
	while (queue->size)
		pop_front(queue);
}