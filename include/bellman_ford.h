#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#define BF_INF 1000000000

typedef struct
{
    int source;
    int destination;
    int weight;
} BFEdge;

typedef struct
{
    int vertex_count;
    int edge_count;
    BFEdge *edges;
} BFGraph;

/*
 * Computes shortest paths from a source vertex.
 *
 * Returns:
 *   0  -> success
 *   1  -> negative-weight cycle detected
 *  -1  -> invalid input
 */
int bellman_ford(
    const BFGraph *graph,
    int source,
    int *distance
);

#endif
