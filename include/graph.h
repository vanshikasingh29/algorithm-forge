#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

#define MAX_GRAPH_VERTICES 128
#define GRAPH_INFINITY 1000000000


typedef struct
{
    int destination;
    int weight;
} Edge;


typedef struct
{
    size_t vertex_count;

    Edge edges[MAX_GRAPH_VERTICES]
              [MAX_GRAPH_VERTICES];

    size_t edge_count[MAX_GRAPH_VERTICES];

} Graph;


void graph_init(
    Graph *graph,
    size_t vertex_count
);


int graph_add_edge(
    Graph *graph,
    int source,
    int destination,
    int weight
);


void bfs(
    const Graph *graph,
    int start,
    int *visited
);


void dfs(
    const Graph *graph,
    int vertex,
    int *visited
);


int dijkstra(
    const Graph *graph,
    int source,
    int target
);


#endif