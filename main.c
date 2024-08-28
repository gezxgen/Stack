/* Imports */
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>
#import "stack.h"

/* Defines */
char get_main(void);
void print_stack(int *, int);
int * append(int *, int, int);

/* Main */
int main() {
        /* Variables */
        int num;
        int length = 0;
        char eingabe = 0;
        int *stack = NULL;

        /* Test */
        while (eingabe != '7') {
                eingabe = get_main();

                switch (eingabe) {
                        /* Load stack */
                case 0:
                        printf("Not implemented yet...");
                        break;

                        /* Append */
                case '1':
                        printf("Which number would you like to append? ");
                        scanf("%d", &num);
                        stack = append(stack, length, num);
                        length++;
                        printf("Number added\n\n");
                        break;

                        /* Pop last */
                case '2':
                        printf("%d", eingabe);
                        break;

                        /* Pop first */
                case '3':
                        printf("%d", eingabe);
                        break;

                        /* Stack count */
                case '4':
                        printf("%d", eingabe);
                        break;

                        /* Stack reset */
                case '5':
                        printf("%d", eingabe);
                        break;

                        /* Stack info */
                case '6':
                        print_stack(stack, length);
                        break;

                        /* Wrong entry */
                default:
                        printf("Invalid entry\n\n");
                }
        }
        free(stack);
}

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

