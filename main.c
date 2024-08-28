/* Imports */
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>

/* Defines */
#define LENGTH 20

/* Defines */
int get_main(void);

/* Main */
int main() {
        /* Variables */
        char end;
        int eingabe = 0;
        int stack[LENGTH];

        /* Test */
        while (eingabe != 7) {
                eingabe = get_main();

                switch (eingabe) {
                /* Load stack */
                case 1:
                        printf("%d", eingabe);
                        break;

                /* Load stack */
                case 2:
                        printf("%d", eingabe);
                        break;

                /* Load stack */
                case 3:
                        printf("%d", eingabe);
                        break;

                /* Load stack */
                case 4:
                        printf("%d", eingabe);
                        break;

                /* Load stack */
                case 5:
                        printf("%d", eingabe);
                        break;

                /* Load stack */
                case 6:
                        printf("%d", eingabe);
                        break;

                /* Wrong entry */
                default:
                        printf("Invalid entry");
                }
        }


        /* Ending */
        printf("Druecke eine beliebige Taste...");
        end = getch();
}

int get_main(void) {
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
        scanf("%d", &func_eingabe);

        return func_eingabe;
}