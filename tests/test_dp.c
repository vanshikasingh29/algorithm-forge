#include <stdio.h>
#include <stdlib.h>

#include "../include/dp.h"


int main(void)
{
    int passed = 0;
    int failed = 0;


    printf("\nDynamic Programming Tests\n");
    printf("============================\n\n");


    if (fibonacci_dp(10) == 55)
    {
        printf("[PASS] Fibonacci DP\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Fibonacci DP\n");
        failed++;
    }


    int weights[] =
    {
        2, 3, 4
    };

    int values[] =
    {
        3, 4, 5
    };


    if (
        knapsack_01(
            weights,
            values,
            3,
            5
        ) == 7
    )
    {
        printf("[PASS] 0/1 Knapsack\n");
        passed++;
    }
    else
    {
        printf("[FAIL] 0/1 Knapsack\n");
        failed++;
    }


    if (
        longest_common_subsequence(
            "ABCBDAB",
            "BDCABA"
        ) == 4
    )
    {
        printf("[PASS] Longest Common Subsequence\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Longest Common Subsequence\n");
        failed++;
    }


    printf("\nPassed: %d\n", passed);
    printf("Failed: %d\n", failed);


    return failed == 0
        ? EXIT_SUCCESS
        : EXIT_FAILURE;
}