#include <stdio.h>

#include "../include/algorithms.h"
#include "../include/dp.h"
#include "../include/greedy.h"
#include "../include/graph.h"
#include "../include/avl.h"


int main(void)
{
    printf("\n");
    printf("============================================\n");
    printf("             ALGORITHM FORGE\n");
    printf("============================================\n");


    /*
     * Search Algorithms
     */

    int values[] =
    {
        10, 20, 30, 40, 50
    };

    printf("\nSearch Algorithms\n");
    printf("----------------------------\n");

    printf(
        "Linear search for 30: index %d\n",
        linear_search(
            values,
            5,
            30
        )
    );

    printf(
        "Binary search for 40: index %d\n",
        binary_search(
            values,
            5,
            40
        )
    );


    /*
     * Dynamic Programming
     */

    printf("\nDynamic Programming\n");
    printf("----------------------------\n");

    printf(
        "Fibonacci DP F(10): %llu\n",
        fibonacci_dp(10)
    );


    /*
     * Graph Algorithms
     */

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

    printf("\nGraph Algorithms\n");
    printf("----------------------------\n");

    printf(
        "Shortest path 0 -> 4: %d\n",
        dijkstra(
            &graph,
            0,
            4
        )
    );


    /*
     * AVL Tree
     */

    AVLNode *root = NULL;

    int tree_values[] =
    {
        30, 20, 10, 25, 40, 50
    };

    for (size_t i = 0; i < 6; i++)
    {
        root =
            avl_insert(
                root,
                tree_values[i]
            );
    }

    printf("\nBalanced Tree\n");
    printf("----------------------------\n");

    printf(
        "AVL tree height: %d\n",
        avl_height(root)
    );

    printf(
        "Search for 25: %s\n",
        avl_search(root, 25) != NULL
            ? "found"
            : "not found"
    );

    avl_free(root);


    printf("\n");
    printf("Algorithm Forge demonstration complete.\n");
    printf("\n");

    return 0;
}