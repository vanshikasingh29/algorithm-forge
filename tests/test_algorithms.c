#include <stdio.h>
#include <stdlib.h>

#include "../include/algorithms.h"


static int passed = 0;
static int failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf("[PASS] %s\n", name);
        passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        failed++;
    }
}


int main(void)
{
    int values[] =
    {
        10, 20, 30, 40, 50
    };


    printf("\nAlgorithm Tests\n");
    printf("============================\n\n");


    assert_test(
        linear_search(
            values,
            5,
            30
        ) == 2,
        "Linear search"
    );


    assert_test(
        linear_search(
            values,
            5,
            99
        ) == -1,
        "Linear search missing value"
    );


    assert_test(
        binary_search(
            values,
            5,
            40
        ) == 3,
        "Binary search"
    );


    assert_test(
        binary_search(
            values,
            5,
            99
        ) == -1,
        "Binary search missing value"
    );


    assert_test(
        factorial(5) == 120,
        "Factorial"
    );


    assert_test(
        fibonacci_recursive(10) == 55,
        "Recursive Fibonacci"
    );


    int array[] =
    {
        1, 2, 3, 4
    };


    assert_test(
        recursive_sum(
            array,
            4
        ) == 10,
        "Recursive array sum"
    );


    printf(
        "\nPassed: %d\n",
        passed
    );

    printf(
        "Failed: %d\n",
        failed
    );


    return failed == 0
        ? EXIT_SUCCESS
        : EXIT_FAILURE;
}