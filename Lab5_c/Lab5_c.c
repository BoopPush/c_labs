// Lab5_c.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "stack.h"

int main()
{
    Queue* Qmax_item = NULL;
    Queue* Qmax_sum = NULL;
    Queue* Qtemp;
    int max_item;
    int max_sum;
    int temp_sum;
    int temp_max;
    int size_1;
    int size;
    int temp;
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    StackInit(stack);
    printf("Set queue amount ");
    scanf_s("%d", &size_1);
    while (size_1 < 1)
    {
        printf("Set queue amount ");
        scanf_s("%d", &size);
    }
    for (int i = 0; i < size_1; i++)
    {
        Qtemp = (Queue*)malloc(sizeof(Queue));
        QueueConstruct(Qtemp);
        printf("%d Set size ", i);
        scanf_s("%d", &size);
        printf("\n");
        while (size < 0)
        {
            printf("%d Set size ", i);
            scanf_s("%d", &size);
            printf("\n");
        }
        for (int j = 0; j < size; j++)
        {
            scanf_s("%d", &temp);
            printf("\n");
            push_back(Qtemp, temp);
        }
        if (!i)
        {
            max_sum = QueueSum(Qtemp);
            max_item = QueueMax(Qtemp);
            Qmax_sum = Qtemp;
            Qmax_item = Qtemp;
        }
        else
        {
            temp_sum = QueueSum(Qtemp);
            temp_max = QueueMax(Qtemp);
            if (temp_sum > max_sum)
            {
                max_sum = temp_sum;
                Qmax_sum = Qtemp;
            }
            if (temp_max >= max_sum)
            {
                max_item = temp_max;
                Qmax_item = Qtemp;
            }
        }
        push(stack, Qtemp);
    }
    printf("\nMax sum queue\nMax sum %d\n", max_sum);
    PrintQueue(Qmax_sum);
    printf("\nMax item queue\nMax item %d\n", max_item);
    PrintQueue(Qmax_item);
    PrintStack(stack);
}
