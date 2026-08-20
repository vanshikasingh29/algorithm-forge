#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#define FW_INF 1000000000

/*
 * Computes shortest paths between every pair
 * of vertices.
 *
 * distance must be a V x V matrix.
 */
void floyd_warshall(
    int vertex_count,
    int distance[][vertex_count]
);

#endif
