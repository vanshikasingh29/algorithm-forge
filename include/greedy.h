#ifndef GREEDY_H
#define GREEDY_H

#include <stddef.h>

typedef struct
{
    int start;
    int finish;
} Activity;


/*
 * Selects the maximum number of
 * non-overlapping activities.
 *
 * Activities must be sorted by finish time.
 */
size_t activity_selection(
    const Activity *activities,
    size_t count,
    size_t *selected
);


/*
 * Fractional knapsack.
 *
 * Unlike 0/1 knapsack, fractions of items
 * may be selected.
 */
double fractional_knapsack(
    const double *weights,
    const double *values,
    size_t count,
    double capacity
);

#endif