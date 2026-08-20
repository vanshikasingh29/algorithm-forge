#ifndef ASTAR_H
#define ASTAR_H

#define ASTAR_INF 1000000000

typedef struct
{
    int x;
    int y;
} AStarPoint;

/*
 * Finds the shortest path on a rectangular grid.
 *
 * grid[y][x]:
 *
 * 0 = traversable
 * 1 = blocked
 *
 * Returns shortest path distance,
 * or ASTAR_INF if unreachable.
 */
int astar_grid(
    int rows,
    int columns,
    int grid[rows][columns],
    AStarPoint start,
    AStarPoint goal
);

#endif
