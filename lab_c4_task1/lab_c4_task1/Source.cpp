#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* takeUserArray();

void copyCharArr(const char* arr, char(*mass)[100]);

void showArray(char(*mass)[100]);

void addLastCh(char(*mass)[100]);
void deleteCopies(char(*mass)[100]);

void moveRight(char* arr);
void moveLeft(char* arr);


int main() {

    printf("Введите многострочный текст на английском языке.\nДля завершения ввода, введите - ;\n\n");
    char* array = takeUserArray();

    char stringArray[100][100] = { '\0' };

    copyCharArr(array, stringArray);

    addLastCh(stringArray);

    deleteCopies(stringArray);

    printf("Преобразованный текст:\n\t1. Перенесена последняя буква в начало слова\n"
        "\t2. В слове оставлено только первые вхождения каждой буквы.\n\n");

    showArray(stringArray);

    return 0;
}


char* takeUserArray() {

    char* buffer = (char*)malloc(100 * sizeof(char));
    if (!buffer) {
        printf("Problem with allocating memory\n");
        return 0;
    }

    char ch;
    while ((ch = (char)getchar()) != ';') {
        static int i = 0;
        buffer[i] = ch;
        i++;
    }


    return buffer;
}


void copyCharArr(const char* arr, char(*mass)[100]) {
    int len = 0;

    int i = 0;
    while (arr[i] != '\0') {

        char buffer[100] = { '\0' };
        int j = 0;

        if (arr[i] == '\n') {
            buffer[j] = arr[i];
            strcpy_s(mass[len], buffer);
            len++;
            i++;
            continue;
        }

        while ((arr[i] != ' ') && (arr[i] != '\0') && (arr[i] != '\n')) {
            buffer[j] = arr[i];
            i++;
            j++;
        }

        buffer[j] = '\0';
        strcpy_s(mass[len], buffer);
        len++;

        if (arr[i] != '\n')
            i++;
    }
}


void showArray(char(*mass)[100]) {

    int i = 0;
    while (strcmp(mass[i], "\0")) {

        if (!strcmp(mass[i], "\n"))
            printf("%s", mass[i]);
        else
            printf("%s ", mass[i]);
        i++;
    }
    printf("\n");
}


void addLastCh(char(*mass)[100]) {

    int len = 0;
    while (strcmp(mass[len], "\0")) {
        len++;
    }

    int i;
    for (i = 0; i < len; i++) {
        moveRight(mass[i]);
        mass[i][0] = mass[i][strlen(mass[i]) - 1];
    }
}


void deleteCopies(char(*mass)[100]) {
    int rep;
    int len = 0;

    while (strcmp(mass[len], "\0")) {
        len++;
    }

    int i, j;
    for (i = 0; i < len; i++) {

        for (j = 0; j < strlen(mass[i]); j++) {

            if (mass[i][j + 1] == '\0' && (mass[i][j - 1] != mass[i][j])) {
                continue;
            }
            rep = (int)strlen(mass[i]);

            while (rep) {
                rep = (int)strlen(mass[i]) - 1 - j;

                int k;
                for (k = j + 1; k < strlen(mass[i]); k++) {

                    if (mass[i][j] == mass[i][k]) {
                        int m;

                        for (m = k; m < strlen(mass[i]); m++) {
                            mass[i][m] = mass[i][m + 1];
                        }

                    }
                    else {
                        rep--;
                    }
                }

                if (strlen(mass[i]) == 1) {
                    rep = 0;
                }
            }
        }
    }
}


void moveRight(char* arr) {

    int i;
    for (i = (int)strlen(arr) - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
}


void moveLeft(char* arr) {

    int i;
    for (i = 0; i < strlen(arr); i++) {
        arr[i] = arr[i + 1];
    }
}