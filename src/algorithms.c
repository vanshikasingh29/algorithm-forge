#include "../include/algorithms.h"


/*
 * ============================================================
 * Linear Search
 * ============================================================
 *
 * Examine each element until the target is found.
 *
 * Time: O(n)
 * Space: O(1)
 */
int linear_search(
    const int *array,
    size_t size,
    int target
)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return (int)i;
        }
    }

    return -1;
}


/*
 * ============================================================
 * Binary Search
 * ============================================================
 *
 * IMPORTANT:
 * The input array must already be sorted.
 *
 * Instead of examining every element, binary search repeatedly
 * eliminates half of the remaining search space.
 *
 * Time: O(log n)
 * Space: O(1)
 */
int binary_search(
    const int *array,
    size_t size,
    int target
)
{
    size_t left = 0;
    size_t right = size;

    while (left < right)
    {
        size_t middle =
            left + (right - left) / 2;


        if (array[middle] == target)
        {
            return (int)middle;
        }


        if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }

    return -1;
}


/*
 * ============================================================
 * Factorial
 * ============================================================
 *
 * Recursive mathematical definition:
 *
 * factorial(n) = n * factorial(n - 1)
 *
 * Base case:
 *
 * factorial(0) = 1
 *
 * Time: O(n)
 * Space: O(n)
 */
unsigned long long factorial(
    unsigned int n
)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}


/*
 * ============================================================
 * Recursive Fibonacci
 * ============================================================
 *
 * Demonstrates recursive branching.
 *
 * F(0) = 0
 * F(1) = 1
 *
 * F(n) = F(n - 1) + F(n - 2)
 *
 * This implementation is intentionally inefficient.
 *
 * Time: exponential
 * Space: O(n)
 */
unsigned long long fibonacci_recursive(
    unsigned int n
)
{
    if (n <= 1)
    {
        return n;
    }

    return
        fibonacci_recursive(n - 1) +
        fibonacci_recursive(n - 2);
}


/*
 * ============================================================
 * Recursive Array Sum
 * ============================================================
 *
 * The problem size decreases by one element on every call.
 *
 * Time: O(n)
 * Space: O(n)
 */
long recursive_sum(
    const int *array,
    size_t size
)
{
    if (size == 0)
    {
        return 0;
    }

    return
        array[size - 1] +
        recursive_sum(
            array,
            size - 1
        );
}