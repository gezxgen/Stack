/* Imports */
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>
#import "stack.h"

char get_main(void) {
        int func_eingabe = 0;
        printf("---------- Funktionsmenu ----------\n");
        printf("0 - Load stack\n");
        printf("1 - Append\n");
        printf("2 - Pop last\n");
        printf("3 - Pop first\n");
        printf("4 - Stack count\n");
        printf("5 - Stack reset\n");
        printf("6 - Stack info\n");
        printf("7 - Terminate\n");
        func_eingabe = getch();

        return func_eingabe;
}

void print_stack(int *first, int length) {
        printf("---------- Stackinfo ----------\n");
        for (int i=0; i<length; i++) {
                printf("%d\t- %d\n", i, *first);
                first += 1;
        }
        printf("\n");
}

int * append(int *first, int length, int num) {
        if (first == NULL) {
                int *new_stack = malloc(1 * sizeof(int));
                new_stack[0] = num;
                return new_stack;
        } else {
                int *new_stack = malloc((length + 1) * sizeof(int));

                for (int i = 0; i < length; i++) {
                        new_stack[i] = first[i];
                }

                new_stack[length] = num;
                free(first);
                return new_stack;
        }
}

int * pop(int *first, int length, int num) {
        if (length <= 1) {
                free(first);
                return NULL;
        } else {
                int * new_stack = malloc((length - 1) * sizeof(int));

                for (int i = 0; i < length-1; i++) {
                        new_stack[i] = first[i];
                }
                free(first);
                return new_stack;
        }
}
