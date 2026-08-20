#include "../include/bellman_ford.h"

int bellman_ford(
    const BFGraph *graph,
    int source,
    int *distance
)
{
    if (
        graph == NULL ||
        distance == NULL ||
        source < 0 ||
        source >= graph->vertex_count
    )
    {
        return -1;
    }

    for (int i = 0; i < graph->vertex_count; i++)
    {
        distance[i] = BF_INF;
    }

    distance[source] = 0;

    /*
     * Relax every edge V - 1 times.
     *
     * Shortest simple paths can contain at most
     * V - 1 edges.
     */
    for (
        int iteration = 0;
        iteration < graph->vertex_count - 1;
        iteration++
    )
    {
        int changed = 0;

        for (
            int i = 0;
            i < graph->edge_count;
            i++
        )
        {
            BFEdge edge = graph->edges[i];

            if (
                distance[edge.source] != BF_INF &&
                distance[edge.source] + edge.weight <
                distance[edge.destination]
            )
            {
                distance[edge.destination] =
                    distance[edge.source] + edge.weight;

                changed = 1;
            }
        }

        /*
         * Early termination:
         * if nothing changed, the solution has converged.
         */
        if (!changed)
        {
            break;
        }
    }

    /*
     * One additional relaxation detects
     * a reachable negative-weight cycle.
     */
    for (
        int i = 0;
        i < graph->edge_count;
        i++
    )
    {
        BFEdge edge = graph->edges[i];

        if (
            distance[edge.source] != BF_INF &&
            distance[edge.source] + edge.weight <
            distance[edge.destination]
        )
        {
            return 1;
        }
    }

    return 0;
}
