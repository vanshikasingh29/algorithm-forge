#include <stdio.h>
#include <stdlib.h>

#include "../include/bellman_ford.h"
#include "../include/floyd_warshall.h"
#include "../include/astar.h"

static int passed = 0;
static int failed = 0;

static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf("[PASS] %s\n", name);
        passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        failed++;
    }
}


/* =========================================================
   Bellman-Ford
   ========================================================= */

static void test_bellman_ford(void)
{
    BFEdge edges[] =
    {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -2},
        {2, 3, 3}
    };

    BFGraph graph =
    {
        4,
        4,
        edges
    };

    int distance[4];

    int result =
        bellman_ford(
            &graph,
            0,
            distance
        );

    assert_test(
        result == 0,
        "Bellman-Ford execution"
    );

    assert_test(
        distance[0] == 0,
        "Bellman-Ford source distance"
    );

    assert_test(
        distance[2] == 2,
        "Bellman-Ford negative edge"
    );

    assert_test(
        distance[3] == 5,
        "Bellman-Ford shortest path"
    );
}


/* =========================================================
   Floyd-Warshall
   ========================================================= */

static void test_floyd_warshall(void)
{
    int graph[4][4] =
    {
        {0,   5,  FW_INF, 10},
        {FW_INF, 0, 3,     FW_INF},
        {FW_INF, FW_INF, 0, 1},
        {FW_INF, FW_INF, FW_INF, 0}
    };

    floyd_warshall(
        4,
        graph
    );

    assert_test(
        graph[0][2] == 8,
        "Floyd-Warshall shortest intermediate path"
    );

    assert_test(
        graph[0][3] == 9,
        "Floyd-Warshall all-pairs shortest path"
    );
}


/* =========================================================
   A*
   ========================================================= */

static void test_astar(void)
{
    int grid[5][5] =
    {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    AStarPoint start =
    {
        0,
        0
    };

    AStarPoint goal =
    {
        4,
        4
    };

    int distance =
        astar_grid(
            5,
            5,
            grid,
            start,
            goal
        );

    assert_test(
        distance == 8,
        "A* shortest grid path"
    );
}


/* =========================================================
   Main
   ========================================================= */

int main(void)
{
    printf(
        "\nAlgorithm Forge - Advanced Graph Tests\n"
    );

    printf(
        "=========================================\n\n"
    );

    test_bellman_ford();

    test_floyd_warshall();

    test_astar();

    printf(
        "\nResults\n"
    );

    printf(
        "-------------------------\n"
    );

    printf(
        "Passed: %d\n",
        passed
    );

    printf(
        "Failed: %d\n",
        failed
    );

    if (failed == 0)
    {
        printf(
            "\nAll advanced graph tests passed.\n"
        );

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
