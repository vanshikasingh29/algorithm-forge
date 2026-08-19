#include "../include/graph.h"

#include <limits.h>


void graph_init(
    Graph *graph,
    size_t vertex_count
)
{
    if (graph == NULL ||
        vertex_count > MAX_GRAPH_VERTICES)
    {
        return;
    }

    graph->vertex_count =
        vertex_count;

    for (size_t i = 0;
         i < vertex_count;
         i++)
    {
        graph->edge_count[i] = 0;
    }
}


int graph_add_edge(
    Graph *graph,
    int source,
    int destination,
    int weight
)
{
    if (graph == NULL ||
        source < 0 ||
        destination < 0 ||
        (size_t)source >= graph->vertex_count ||
        (size_t)destination >= graph->vertex_count)
    {
        return 0;
    }

    size_t count =
        graph->edge_count[source];

    if (count >= MAX_GRAPH_VERTICES)
    {
        return 0;
    }

    graph->edges[source][count].destination =
        destination;

    graph->edges[source][count].weight =
        weight;

    graph->edge_count[source]++;

    return 1;
}


void bfs(
    const Graph *graph,
    int start,
    int *visited
)
{
    if (graph == NULL ||
        visited == NULL ||
        start < 0 ||
        (size_t)start >= graph->vertex_count)
    {
        return;
    }

    int queue[MAX_GRAPH_VERTICES];

    size_t front = 0;
    size_t back = 0;

    queue[back++] = start;

    visited[start] = 1;

    while (front < back)
    {
        int vertex =
            queue[front++];

        for (size_t i = 0;
             i < graph->edge_count[vertex];
             i++)
        {
            int next =
                graph->edges[vertex][i].destination;

            if (!visited[next])
            {
                visited[next] = 1;

                queue[back++] = next;
            }
        }
    }
}


void dfs(
    const Graph *graph,
    int vertex,
    int *visited
)
{
    if (graph == NULL ||
        visited == NULL ||
        vertex < 0 ||
        (size_t)vertex >= graph->vertex_count)
    {
        return;
    }

    visited[vertex] = 1;

    for (size_t i = 0;
         i < graph->edge_count[vertex];
         i++)
    {
        int next =
            graph->edges[vertex][i].destination;

        if (!visited[next])
        {
            dfs(
                graph,
                next,
                visited
            );
        }
    }
}


int dijkstra(
    const Graph *graph,
    int source,
    int target
)
{
    if (graph == NULL ||
        source < 0 ||
        target < 0 ||
        (size_t)source >= graph->vertex_count ||
        (size_t)target >= graph->vertex_count)
    {
        return -1;
    }

    int distance[MAX_GRAPH_VERTICES];
    int visited[MAX_GRAPH_VERTICES];

    for (size_t i = 0;
         i < graph->vertex_count;
         i++)
    {
        distance[i] =
            GRAPH_INFINITY;

        visited[i] = 0;
    }

    distance[source] = 0;

    for (size_t iteration = 0;
         iteration < graph->vertex_count;
         iteration++)
    {
        int current = -1;

        for (size_t i = 0;
             i < graph->vertex_count;
             i++)
        {
            if (!visited[i] &&
                (current == -1 ||
                 distance[i] < distance[current]))
            {
                current = (int)i;
            }
        }

        if (current == -1 ||
            distance[current] == GRAPH_INFINITY)
        {
            break;
        }

        visited[current] = 1;

        for (size_t i = 0;
             i < graph->edge_count[current];
             i++)
        {
            Edge edge =
                graph->edges[current][i];

            int candidate =
                distance[current] +
                edge.weight;

            if (candidate < distance[edge.destination])
            {
                distance[edge.destination] =
                    candidate;
            }
        }
    }

    if (distance[target] == GRAPH_INFINITY)
    {
        return -1;
    }

    return distance[target];
}