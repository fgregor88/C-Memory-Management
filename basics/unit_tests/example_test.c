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
