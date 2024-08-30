# Documentation for Stack Program

This document provides comprehensive documentation for a C program that implements a dynamic stack using heap memory. The program allows users to interact with the stack through a text-based menu interface, performing operations such as appending, popping, and saving/loading stack data.

## Table of Contents

- [Overview](#overview)
- [Main Module](#main-module)
    - [Imports](#imports)
    - [Function: `main`](#function-main)
- [Stack Module](#stack-module)
    - [Imports](#imports-1)
    - [Function: `get_main`](#function-get_main)
    - [Function: `print_stack`](#function-print_stackint-first-int-length)
    - [Function: `append`](#function-appendint-first-int-length-int-num)
    - [Function: `pop`](#function-popint-first-int-length-int-is_normal)
    - [Function: `load_stack`](#function-load_stackint-length)
    - [Function: `save_stack`](#function-save_stackint-stack-int-length)
- [Summary](#summary)

## Overview

The program represents a stack data structure implemented with a dynamic array. It uses heap memory for stack operations such as appending elements, removing elements from the end or the beginning, and managing the stack through file I/O operations.

## Main Module

### Imports

```c
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>
#import "stack.h"
```
- **`<stdlib.h>`**: Provides functions for memory allocation (`malloc`, `free`).
- **`<stdio.h>`**: Provides standard input/output functions (`printf`, `scanf`, `fopen`, `fprintf`).
- **`<conio.h>`**: Provides console input functions (`getch`).
- **`"stack.h"`**: Header file declaring stack-related functions.

### Function: `main()`

The `main` function drives the program, presenting a menu to the user and performing stack operations based on user input.

**Parameters:**
- None.

**Returns:**
- `int`: Exit code (typically 0).

**Description:**
- Initializes variables for stack management.
- Provides a loop that displays a menu and processes user input.
- Supports operations such as appending, popping, counting, resetting, loading, and saving the stack.
- Frees allocated memory before exiting.

**Code:**

```c
int main() {
    /* Variables */
    int num;
    int length = 0;
    char eingabe = 0;
    int *stack = NULL;
    int *ptrlen = &length;

    /* Test */
    while (eingabe != '9') {
        eingabe = get_main();
        system("cls");

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
                printf("The length of the stack is: %d\n\n", length);
                break;

            /* Stack reset */
            case '5':
                length = 0;
                free(stack);
                stack = NULL;
                printf("Stack has been reset\n\n");
                break;

            /* Stack info */
            case '6':
                print_stack(stack, length);
                break;

            /* Load stack */
            case '7':
                stack = load_stack(ptrlen);
                break;

            /* Save stack */
            case '8':
                save_stack(stack, length);
                break;

            /* Wrong entry */
            default:
                printf("Invalid entry\n\n");
        }
    }
    free(stack);
}
```

## Stack Module

### Imports

```c
#import <stdlib.h>
#import <stdio.h>
#include <conio.h>
#import "stack.h"
```
- **`<stdlib.h>`**: Provides functions for dynamic memory management.
- **`<stdio.h>`**: Provides functions for file operations and formatted output.
- **`<conio.h>`**: Provides functions for console input.
- **`"stack.h"`**: Includes declarations for stack functions.

### Function: `get_main()`

Displays the main menu and captures user input.

**Parameters:**
- None.

**Returns:**
- `char`: The user's menu selection.

**Description:**
- Prints a menu with options for stack operations.
- Reads and returns the user's input using `getch()`.

**Code:**

```c
char get_main(void) {
    printf("---------- Function Menu ----------\n");
    printf("1 - Append\n");
    printf("2 - Pop last\n");
    printf("3 - Pop first\n");
    printf("4 - Stack count\n");
    printf("5 - Stack reset\n");
    printf("6 - Stack info\n");
    printf("7 - Load stack\n");
    printf("8 - Save stack\n");
    printf("9 - Terminate\n");
    char func_eingabe = (char)getch();

    return func_eingabe;
}
```

### Function: `print_stack(int *first, int length)`

Prints the contents of the stack.

**Parameters:**
- `int *first`: Pointer to the stack's first element.
- `int length`: The number of elements in the stack.

**Returns:**
- None.

**Description:**
- Iterates through the stack and prints each element along with its index.

**Code:**

```c
void print_stack(int *first, int length) {
    printf("---------- Stack Info ----------\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t- %d\n", i, first[i]);
    }
    printf("\n");
}
```

### Function: `append(int *first, int length, int num)`

Appends a new element to the stack.

**Parameters:**
- `int *first`: Pointer to the current stack.
- `int length`: The current size of the stack.
- `int num`: The value to append.

**Returns:**
- `int *`: Pointer to the new stack with the appended value.

**Description:**
- Allocates memory for a new stack with one additional element.
- Copies the current stack to the new stack and adds the new element.
- Frees the memory of the old stack.

**Code:**

```c
int *append(int *first, int length, int num) {
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
```

### Function: `pop(int *first, int length, int is_normal)`

Removes an element from the stack.

**Parameters:**
- `int *first`: Pointer to the current stack.
- `int length`: The current size of the stack.
- `int is_normal`: Flag indicating if the element to pop is from the end (`1`) or the beginning (`0`).

**Returns:**
- `int *`: Pointer to the new stack with the element removed.

**Description:**
- Allocates memory for a new stack with one less element.
- Copies elements from the old stack to the new stack, excluding the removed element.
- Frees the memory of the old stack.

**Code:**

```c
int *pop(int *first, int length, int is_normal) {
    if (length <= 1) {
        free(first);
        return NULL;
    } else {
        int *new_stack = malloc((length - 1) * sizeof(int));
        for (int i = 0; i < length - 1; i++) {
            if (is_normal) {
                new_stack[i] = first[i];
            } else {
                new_stack[i] = first[i + 1];
            }
        }
        free(first);
        return new_stack;
    }
}
```

### Function: `load_stack(int *length)`

Loads stack data from a file.

**Parameters:**
- `int *length`: Pointer to the variable holding the stack length.

**Returns:**
- `int *`: Pointer to the stack loaded from the file.

**Description:**
- Opens `data.csv` for reading and loads integers into the stack.
- Updates the stack length based on the number of integers read.
- Closes the file after loading.

**Code:**

```c
int* load_stack(int *length) {
    int num;
    int *stack = NULL;
    *length = 0;
    FILE *fpt = fopen("data.csv", "r");

    while (fscanf(fpt, "%d%*[,\n ]", &num) == 1) {
        stack = append(stack, *length, num);
        (*length)++;
    }

    fclose(fpt);
    printf("Stack loaded\n\n");
    return stack;
}
```

### Function: `save_stack(int *stack, int length)`

Saves

stack data to a file.

**Parameters:**
- `int *stack`: Pointer to the stack to be saved.
- `int length`: The number of elements in the stack.

**Returns:**
- None.

**Description:**
- Opens `data.csv` for writing and saves the stack elements.
- Writes numbers separated by commas.
- Closes the file after saving.

**Code:**

```c
void save_stack(int *stack, int length) {
    FILE *fpt = fopen("data.csv", "w");
    for (int i = 0; i < length - 1; i++) {
        fprintf(fpt, "%d, ", stack[i]);
    }
    fprintf(fpt, "%d", stack[length - 1]);
    fclose(fpt);
    printf("Numbers saved\n\n");
}
```

## Summary

This C program provides a dynamic stack implementation using heap memory, enabling operations such as appending, popping, and managing the stack via file I/O. The `main` module handles user interactions through a menu, while the `stack` module includes functions for stack manipulation and file operations. The use of dynamic memory allows for flexible stack resizing, making the program adaptable to varying data sizes.

