# Understanding the Basic Munit Unit Test (`example_test.c`)

This guide explains the `example_test.c` file line by line. It assumes you are familiar with basic C programming (like functions, arrays, and structs) but have **never used a unit testing framework before**.

## What is Unit Testing?

Unit testing is the practice of testing small, isolated pieces of code (usually functions) to ensure they behave exactly as expected. Instead of running your whole application to see if a small math function works, you write a tiny separate program—a "test"—that automatically feeds inputs to the function and checks the output.

In C, we use frameworks like **Munit** to make this easy. Munit provides tools to run these tests, report failures, and organize them.

---

## 1. Including the Framework

```c
#include <munit/munit.h>
```
To use Munit, we must include its main header file. This gives us access to all the special types (like `MunitResult`), macros (like `munit_assert_int`), and functions we need to write and run tests.

---

## 2. The Code We Want to Test

```c
// A simple function to test
int add(int a, int b) {
    return a + b;
}
```
This is a standard C function. In a real project, this would be a function inside your application that you want to verify. We call this the "System Under Test" (SUT) or "Function Under Test".

---

## 3. Writing the Actual Test

```c
// The most basic test function
static MunitResult test_simple_add(const MunitParameter params[], void* user_data) {
    (void)params; /* unused */
    (void)user_data; /* unused */

    munit_assert_int(add(1, 1), == , 2);
    return MUNIT_OK;
}
```
This function is our unit test. Let's break it down:

*   **`static MunitResult`**: Munit requires all test functions to return a `MunitResult`. This tells the framework if the test passed or failed. We use `static` so this function is only visible inside this specific file.
*   **Parameters (`params`, `user_data`)**: Munit always passes these two arguments to every test function. They are used for advanced features (like running the same test with different generated data). Because we aren't using them in this basic test, we cast them to `(void)` to tell the compiler "I know I'm not using these, please don't warn me about them."
*   **`munit_assert_int(...)`**: This is the heart of the test. An "assertion" is a statement that **must** be true. If it's false, the test fails.
    *   We are saying: "Call `add(1, 1)`. I assert that the integer result is `==` to `2`."
    *   If `add(1, 1)` returned `3`, Munit would catch it, stop the test, and print an error message.
*   **`return MUNIT_OK;`**: If the code reaches this line without any assertions failing, we tell Munit the test was a success (`MUNIT_OK`).

---

## 4. Listing Your Tests (The Test Array)

Just writing a test function isn't enough; we have to tell Munit that it exists.

```c
// The array of tests
static MunitTest tests[] = {
    { "/add/simple", test_simple_add, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Sentinel value
};
```
We create an array of `MunitTest` structs. Each struct represents one test.

*   **Test 1 (`{ "/add/simple", test_simple_add, ... }`)**:
    *   `"/add/simple"`: We give the test a name. Munit uses file-path-like names to help you organize tests.
    *   `test_simple_add`: This is a pointer to the function we wrote above.
    *   The remaining `NULL`s and `MUNIT_TEST_OPTION_NONE` are for advanced configurations (like setup/teardown functions) which we don't need right now.
*   **The "Sentinel" Value (`{ NULL, ... }`)**:
    *   How does Munit know when it has reached the end of the `tests` array? We put a completely empty test at the very end. When Munit sees `NULL` as a test name, it stops looking. This is called a sentinel value.

---

## 5. Grouping Tests into a Suite

```c
// The test suite
static const MunitSuite suite = {
    "/basic_suite", // Name of the suite
    tests,          // Array of tests
    NULL,           // Array of sub-suites
    1,              // Number of iterations
    MUNIT_SUITE_OPTION_NONE
};
```
In large projects, you might have hundreds of tests. Munit groups them into "Suites".
*   `"/basic_suite"`: The name of this collection of tests.
*   `tests`: We pass in the array we created in the previous step.
*   `NULL`: We could nest suites inside other suites, but we don't need to here.
*   `1`: How many times to run the suite (just once).

---

## 6. Running the Tests

```c
// Main function to run the suite
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
```
Every C program needs a `main` function. For our test program, the `main` function's only job is to hand control over to Munit.

*   **`munit_suite_main(...)`**: We give Munit our `suite` and any command-line arguments the user typed (`argc`, `argv`).
*   Munit takes over from here. It will run the suite, run the tests inside the suite, print beautifully formatted results to the terminal, and return `0` if everything passed (or a non-zero error code if anything failed).