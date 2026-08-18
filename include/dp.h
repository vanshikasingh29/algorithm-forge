#ifndef DP_H
#define DP_H

#include <stddef.h>

/*
 * Dynamic Programming Algorithms
 */

/* Bottom-up Fibonacci: O(n) time, O(n) space */
unsigned long long fibonacci_dp(unsigned int n);

/*
 * 0/1 Knapsack.
 *
 * weights  - item weights
 * values   - item values
 * count    - number of items
 * capacity - maximum allowed weight
 *
 * Returns maximum achievable value.
 */
int knapsack_01(
    const int *weights,
    const int *values,
    size_t count,
    int capacity
);

/*
 * Longest Common Subsequence.
 *
 * Returns the length of the LCS.
 */
size_t longest_common_subsequence(
    const char *a,
    const char *b
);

#endif