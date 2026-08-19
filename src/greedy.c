#include "../include/greedy.h"


size_t activity_selection(
    const Activity *activities,
    size_t count,
    size_t *selected
)
{
    if (activities == NULL ||
        selected == NULL ||
        count == 0)
    {
        return 0;
    }

    size_t selected_count = 0;

    int last_finish = activities[0].finish;

    selected[selected_count++] = 0;

    for (size_t i = 1; i < count; i++)
    {
        if (activities[i].start >= last_finish)
        {
            selected[selected_count++] = i;

            last_finish =
                activities[i].finish;
        }
    }

    return selected_count;
}


double fractional_knapsack(
    const double *weights,
    const double *values,
    size_t count,
    double capacity
)
{
    if (weights == NULL ||
        values == NULL ||
        capacity <= 0)
    {
        return 0.0;
    }

    /*
     * Simple implementation:
     * repeatedly select the item with the
     * highest remaining value/weight ratio.
     */

    int *used = calloc(count, sizeof(int));

    if (used == NULL)
    {
        return 0.0;
    }

    double total = 0.0;

    for (size_t step = 0; step < count; step++)
    {
        size_t best = count;

        double best_ratio = -1.0;

        for (size_t i = 0; i < count; i++)
        {
            if (!used[i] && weights[i] > 0)
            {
                double ratio =
                    values[i] / weights[i];

                if (ratio > best_ratio)
                {
                    best_ratio = ratio;
                    best = i;
                }
            }
        }

        if (best == count)
        {
            break;
        }

        used[best] = 1;

        if (weights[best] <= capacity)
        {
            total += values[best];

            capacity -= weights[best];
        }
        else
        {
            total +=
                values[best] *
                (capacity / weights[best]);

            capacity = 0;
        }

        if (capacity <= 0)
        {
            break;
        }
    }

    free(used);

    return total;
}