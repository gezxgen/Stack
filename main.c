/* Imports */
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>
#import "stack.h"

/* Defines */
#define LENGTH 20

/* Defines */
char get_main(void);

/* Main */
int main() {
        /* Variables */
        int num;
        char eingabe = 0;
        int stack[LENGTH];

        /* Add elements */
        for (int i=0; i<LENGTH; i++){
                stack[i] = 0;
        }

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
                        for (int i = 0; i < LENGTH; i++) {
                                if (stack[i] == 0) {
                                        stack[i] = num;
                                        break;
                                }
                        }
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
                        printf("-------------------\n");
                        for (int i = 0; i < LENGTH; i++) {
                                printf("%d\t- %d\n", i, stack[i]);
                        }
                        printf("-------------------\n");
                        break;

                        /* Wrong entry */
                default:
                        printf("Invalid entry\n\n");
                }
        }
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