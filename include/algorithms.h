#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stddef.h>

/*
 * Search Algorithms
 */

/* Linear search: O(n) */
int linear_search(
    const int *array,
    size_t size,
    int target
);

/* Binary search: O(log n) */
int binary_search(
    const int *array,
    size_t size,
    int target
);

/*
 * Recursive Algorithms
 */

/* Factorial: O(n) */
unsigned long long factorial(unsigned int n);

/* Fibonacci: exponential recursive baseline */
unsigned long long fibonacci_recursive(unsigned int n);

/* Array summation: O(n) */
long recursive_sum(
    const int *array,
    size_t size
);

#endif