#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stddef.h>

/*
 * ============================================================
 * Algorithm Library
 * Phase 3 — Algorithms & Data Structures
 *
 * Topic:
 * Searching and Recursive Algorithms
 * ============================================================
 */

/*
 * ------------------------------------------------------------
 * Search Algorithms
 * ------------------------------------------------------------
 */

/*
 * Linear Search
 *
 * Searches each element sequentially.
 *
 * Time:  O(n)
 * Space: O(1)
 *
 * Returns:
 *   index of target if found
 *   -1 otherwise
 */
int linear_search(
    const int *array,
    size_t size,
    int target
);


/*
 * Binary Search
 *
 * Requires the array to be sorted.
 *
 * Time:  O(log n)
 * Space: O(1)
 *
 * Returns:
 *   index of target if found
 *   -1 otherwise
 */
int binary_search(
    const int *array,
    size_t size,
    int target
);


/*
 * ------------------------------------------------------------
 * Recursive Algorithms
 * ------------------------------------------------------------
 */

/*
 * Factorial
 *
 * Mathematical definition:
 *
 * n! = n * (n - 1)!
 * 0! = 1
 *
 * Time:  O(n)
 * Space: O(n) due to recursion stack
 */
unsigned long long factorial(
    unsigned int n
);


/*
 * Recursive Fibonacci
 *
 * Mathematical definition:
 *
 * F(0) = 0
 * F(1) = 1
 *
 * F(n) = F(n - 1) + F(n - 2)
 *
 * This deliberately demonstrates the inefficient
 * exponential recursive solution.
 *
 * Time:  O(2^n) approximately
 * Space: O(n)
 */
unsigned long long fibonacci_recursive(
    unsigned int n
);


/*
 * Recursive Array Sum
 *
 * Calculates the sum of all elements using recursion.
 *
 * Time:  O(n)
 * Space: O(n)
 */
long recursive_sum(
    const int *array,
    size_t size
);

#endif