# Basic C Examples

This folder contains simple C programs to illustrate fundamental concepts.

## hello

This is a classic "Hello, World!" program.
```C Memory Management/basics/hello/hello.c#L1-5
#include <stdio.h>

int main(){
    printf("hello world\\n");
    return 0;
}
```
It includes the standard input/output library (`stdio.h`) and uses the `printf` function to print the string "hello world" to the console.

## hello_formated

This example demonstrates variable declaration, initialization, and formatted output using `printf`.
```C Memory Management/basics/hello_formated/hello_formated.c#L1-12
#include <stdio.h>

int main(){
    //comment
    int a = 4;
    float x = 0.5;
    char c = 'a';
    char *str = "Hello, this is a string";

    printf("hello\\n");
    printf("Variables: a = %d, x = %f, c = %c, str = %s\\n", a, x, c, str);
    
    return 0;
}
```
It declares an integer (`a`), a float (`x`), a character (`c`), and a character pointer (`str`). It then prints a simple "hello" and a second line showing the values of these variables using format specifiers like `%d` (integer), `%f` (float), `%c` (character), and `%s` (string).

## loops

This example demonstrates the usage of `for` and `while` loops in C.
```C Memory Management/basics/loops/loops.c#L1-17
#include <stdio.h>

int main(){
    printf("for loops starting from 0 with i++:\\n");
    for (int i = 0; i < 5; i++){
        printf("%d\\n", i);
    }
    printf("\\n");

    printf("while loop:\\n");
    int iter = 0;
    while (iter < 5){
        printf("%d\\n", iter);
        iter++;
    }
}
```
It shows a `for` loop that iterates from 0 to 4 (exclusive of 5) using the post-increment operator `i++`, and a `while` loop that achieves the same iteration count, incrementing a counter variable manually.