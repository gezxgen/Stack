/* Imports */
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>
#import "stack.h"

/* Main */
int main() {
        /* Variables */
        int num;
        int length = 0;
        char eingabe = 0;
        int *stack = NULL;

        /* Test */
        while (eingabe != '9') {
                eingabe = get_main();

                switch (eingabe) {
                        /* Append */
                case '1':
                        printf("Which number would you like to append? ");
                        scanf("%d", &num);
                        stack = append(stack, length, num);
                        length++;
                        printf("Number appended\n\n");
                        break;

                        /* Pop last */
                case '2':
                        stack = pop(stack, length, 1);
                        length--;
                        printf("Number popped\n\n");
                        break;


                        /* Pop first */
                case '3':
                        stack = pop(stack, length, 0);
                        length--;
                        printf("Number popped\n\n");
                        break;

                        /* Stack count */
                case '4':
                        printf("Die laenge des Stacks betraegt: %d\n\n", length);
                        break;

                        /* Stack reset */
                case '5':
                        length = 0;
                        free(stack);
                        stack = NULL;
                        printf("Stack wurde zurueckgesetzt\n\n");
                        break;

                        /* Stack info */
                case '6':
                        print_stack(stack, length);
                        break;

                        /* Load stack */
                case '7':
                        printf("Not implemented yet...");
                        break;
                        /* Save stack */

                case '8':
                        printf("Not implemented yet...");
                        break;

                        /* Wrong entry */
                default:
                        printf("Invalid entry\n\n");
                }
        }
        free(stack);
}
