#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Simple linear search.
 */
static int linear_search(
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
 * Binary search requires sorted input.
 */
static int binary_search(
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


static double benchmark_linear(
    const int *array,
    size_t size,
    int target
)
{
    clock_t start = clock();

    volatile int result =
        linear_search(
            array,
            size,
            target
        );

    (void)result;

    clock_t end = clock();

    return (double)(end - start) /
           CLOCKS_PER_SEC;
}


static double benchmark_binary(
    const int *array,
    size_t size,
    int target
)
{
    clock_t start = clock();

    volatile int result =
        binary_search(
            array,
            size,
            target
        );

    (void)result;

    clock_t end = clock();

    return (double)(end - start) /
           CLOCKS_PER_SEC;
}


int main(void)
{
    const size_t sizes[] =
    {
        1000,
        10000,
        100000,
        1000000
    };

    const size_t count =
        sizeof(sizes) /
        sizeof(sizes[0]);

    printf(
        "\nAlgorithm Forge - Search Benchmark\n"
    );

    printf(
        "===================================\n\n"
    );

    printf(
        "%12s %18s %18s\n",
        "Input",
        "Linear (s)",
        "Binary (s)"
    );

    for (size_t i = 0; i < count; i++)
    {
        size_t size = sizes[i];

        int *array =
            malloc(
                sizeof(int) * size
            );

        if (array == NULL)
        {
            fprintf(
                stderr,
                "Allocation failed.\n"
            );

            return EXIT_FAILURE;
        }

        for (size_t j = 0; j < size; j++)
        {
            array[j] = (int)j;
        }

        int target =
            (int)(size - 1);

        double linear =
            benchmark_linear(
                array,
                size,
                target
            );

        double binary =
            benchmark_binary(
                array,
                size,
                target
            );

        printf(
            "%12zu %18f %18f\n",
            size,
            linear,
            binary
        );

        free(array);
    }

    return EXIT_SUCCESS;
}
