#include <stdio.h>
#include <stdlib.h>

#include "../include/graph.h"


int main(void)
{
    int passed = 0;
    int failed = 0;


    Graph graph;

    graph_init(
        &graph,
        5
    );


    graph_add_edge(&graph, 0, 1, 4);
    graph_add_edge(&graph, 0, 2, 2);
    graph_add_edge(&graph, 2, 1, 1);
    graph_add_edge(&graph, 1, 3, 5);
    graph_add_edge(&graph, 2, 3, 8);
    graph_add_edge(&graph, 3, 4, 3);


    printf("\nGraph Algorithm Tests\n");
    printf("============================\n\n");


    if (dijkstra(&graph, 0, 4) == 11)
    {
        printf("[PASS] Dijkstra shortest path\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Dijkstra shortest path\n");
        failed++;
    }


    int visited[5] = {0};

    bfs(
        &graph,
        0,
        visited
    );


    if (
        visited[0] &&
        visited[1] &&
        visited[2] &&
        visited[3] &&
        visited[4]
    )
    {
        printf("[PASS] Breadth-first search\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Breadth-first search\n");
        failed++;
    }


    printf("\nPassed: %d\n", passed);
    printf("Failed: %d\n", failed);


    return failed == 0
        ? EXIT_SUCCESS
        : EXIT_FAILURE;
}