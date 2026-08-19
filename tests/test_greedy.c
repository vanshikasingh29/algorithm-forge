#include <stdio.h>
#include <stdlib.h>

#include "../include/greedy.h"


int main(void)
{
    int passed = 0;
    int failed = 0;


    printf("\nGreedy Algorithm Tests\n");
    printf("============================\n\n");


    Activity activities[] =
    {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9}
    };


    size_t selected[5];


    size_t count =
        activity_selection(
            activities,
            5,
            selected
        );


    if (count == 4)
    {
        printf("[PASS] Activity selection\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Activity selection\n");
        failed++;
    }


    double weights[] =
    {
        10.0,
        20.0,
        30.0
    };


    double values[] =
    {
        60.0,
        100.0,
        120.0
    };


    double result =
        fractional_knapsack(
            weights,
            values,
            3,
            50.0
        );


    if (result > 239.9 &&
        result < 240.1)
    {
        printf("[PASS] Fractional knapsack\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Fractional knapsack\n");
        failed++;
    }


    printf("\nPassed: %d\n", passed);
    printf("Failed: %d\n", failed);


    return failed == 0
        ? EXIT_SUCCESS
        : EXIT_FAILURE;
}