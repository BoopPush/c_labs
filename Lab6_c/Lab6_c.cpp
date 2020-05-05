// Lab6_c.c : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "tree.h"

int main()
{
    TreeItem* root = (TreeItem*)malloc(sizeof(TreeItem));
    String* string = (String*)malloc(sizeof(String));
    int leavesAmount = 0;
    TreeConstruct(root, string);
    countLeaves(root, &leavesAmount);
    system("cls");
    printf("\nYour tree\n");
    PrintTree(root, 0);
    printf("\n\n%d leaves", leavesAmount);
}
