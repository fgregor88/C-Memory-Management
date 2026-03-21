#include <munit/munit.h>

// A simple function to test
int add(int a, int b) {
    return a + b;
}

// The most basic test function
static MunitResult test_simple_add(const MunitParameter params[], void* user_data) {
    (void)params; /* unused */
    (void)user_data; /* unused */

    munit_assert_int(add(1, 1), == , 2);
    return MUNIT_OK;
}

// The array of tests
static MunitTest tests[] = {
    { "/add/simple", test_simple_add, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Sentinel value
};

// The test suite
static const MunitSuite suite = {
    "/basic_suite", // Name of the suite
    tests,          // Array of tests
    NULL,           // Array of sub-suites
    1,              // Number of iterations
    MUNIT_SUITE_OPTION_NONE
};

// Main function to run the suite
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}