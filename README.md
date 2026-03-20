# C Memory Management

This project contains various examples and exercises related to C programming, with a focus on memory management concepts.

## basics

This folder contains simple C programs to illustrate fundamental concepts.

### hello

This is a classic "Hello, World!" program.
```C Memory Management/basics/hello/hello.c#L1-5
#include <stdio.h>

int main(){
    printf("hello world\\n");
    return 0;
}
```
It includes the standard input/output library (`stdio.h`) and uses the `printf` function to print the string "hello world" to the console.

### hello_formated

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

### loops

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

### functions

This example demonstrates how to define and use functions in C.
```C Memory Management/basics/functions/functions.c#L1-12
#include <stdio.h>

void greeting(char *name);

int main(){
    greeting("Filip\\n");
    return 0;
}

void greeting(char *name){
    printf("Hello, %s", name);
}
```
It defines a `greeting` function that takes a character pointer (string) as an argument and prints a personalized greeting to the console. The `main` function then calls this `greeting` function.

### unit_tests

This example demonstrates how to set up and run a basic unit test with Munit. It includes a simple `add` function and a test case (`test_add`) to verify its correctness.
```C Memory Management/basics/unit_tests/example_test.c#L1-47
#include <stdio.h>
#include <munit/munit.h>

// A simple function to test
int add(int a, int b) {
    return a + b;
}

// Test function for the add function
static MunitResult test_add(const MunitParameter params[], void* user_data) {
    (void)params; /* unused */
    (void)user_data; /* unused */

    // Test case 1: Positive numbers
    munit_assert_int(add(2, 3), == , 5);

    // Test case 2: Negative numbers
    munit_assert_int(add(-2, -3), == , -5);

    // Test case 3: Positive and negative
    munit_assert_int(add(5, -2), == , 3);

    // Test case 4: Zero
    munit_assert_int(add(0, 0), == , 0);

    return MUNIT_OK;
}

// Define the array of tests
static MunitTest tests[] = {
    { "/add-function-test", test_add, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Sentinel value
};

// Define the test suite
static const MunitSuite suite = {
    "/example_suite", // Name of the suite
    tests,            // Array of tests
    NULL,             // Array of sub-suites (none in this example)
    1,                // Number of iterations (optional, 1 for single run)
    MUNIT_SUITE_OPTION_NONE
};

// Main function to run the suite
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
```

