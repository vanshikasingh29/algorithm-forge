#include "../include/dp.h"

#include <stdlib.h>
#include <string.h>


unsigned long long fibonacci_dp(unsigned int n)
{
    if (n <= 1)
    {
        return n;
    }

    unsigned long long *dp =
        calloc(
            n + 1,
            sizeof(unsigned long long)
        );

    if (dp == NULL)
    {
        return 0;
    }

    dp[0] = 0;
    dp[1] = 1;

    for (unsigned int i = 2; i <= n; i++)
    {
        dp[i] =
            dp[i - 1] +
            dp[i - 2];
    }

    unsigned long long result = dp[n];

    free(dp);

    return result;
}


int knapsack_01(
    const int *weights,
    const int *values,
    size_t count,
    int capacity
)
{
    if (weights == NULL ||
        values == NULL ||
        capacity < 0)
    {
        return 0;
    }

    int *dp =
        calloc(
            (size_t)capacity + 1,
            sizeof(int)
        );

    if (dp == NULL)
    {
        return 0;
    }

    for (size_t i = 0; i < count; i++)
    {
        for (int w = capacity;
             w >= weights[i];
             w--)
        {
            int candidate =
                dp[w - weights[i]] +
                values[i];

            if (candidate > dp[w])
            {
                dp[w] = candidate;
            }
        }
    }

    int result = dp[capacity];

    free(dp);

    return result;
}


size_t longest_common_subsequence(
    const char *a,
    const char *b
)
{
    if (a == NULL || b == NULL)
    {
        return 0;
    }

    size_t rows = strlen(a) + 1;
    size_t cols = strlen(b) + 1;

    size_t *dp =
        calloc(
            rows * cols,
            sizeof(size_t)
        );

    if (dp == NULL)
    {
        return 0;
    }

    for (size_t i = 1; i < rows; i++)
    {
        for (size_t j = 1; j < cols; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i * cols + j] =
                    dp[(i - 1) * cols + (j - 1)] + 1;
            }
            else
            {
                size_t top =
                    dp[(i - 1) * cols + j];

                size_t left =
                    dp[i * cols + (j - 1)];

                dp[i * cols + j] =
                    top > left ? top : left;
            }
        }
    }

    size_t result =
        dp[(rows - 1) * cols + (cols - 1)];

    free(dp);

    return result;
}