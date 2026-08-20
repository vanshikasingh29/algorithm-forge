#include "../include/astar.h"

#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int g;
    int f;
} Node;

static int heuristic(
    AStarPoint a,
    AStarPoint b
)
{
    int dx = abs(a.x - b.x);
    int dy = abs(a.y - b.y);

    /*
     * Manhattan distance is admissible
     * when movement is restricted to four directions.
     */
    return dx + dy;
}

static int valid(
    int rows,
    int columns,
    int grid[rows][columns],
    int x,
    int y
)
{
    return
        x >= 0 &&
        x < columns &&
        y >= 0 &&
        y < rows &&
        grid[y][x] == 0;
}

int astar_grid(
    int rows,
    int columns,
    int grid[rows][columns],
    AStarPoint start,
    AStarPoint goal
)
{
    if (
        rows <= 0 ||
        columns <= 0 ||
        !valid(
            rows,
            columns,
            grid,
            start.x,
            start.y
        ) ||
        !valid(
            rows,
            columns,
            grid,
            goal.x,
            goal.y
        )
    )
    {
        return ASTAR_INF;
    }

    int total = rows * columns;

    int *g_score =
        malloc(
            sizeof(int) * total
        );

    int *open =
        malloc(
            sizeof(int) * total
        );

    int *closed =
        calloc(
            total,
            sizeof(int)
        );

    if (
        g_score == NULL ||
        open == NULL ||
        closed == NULL
    )
    {
        free(g_score);
        free(open);
        free(closed);

        return ASTAR_INF;
    }

    for (int i = 0; i < total; i++)
    {
        g_score[i] = ASTAR_INF;
    }

    int open_count = 0;

    int start_index =
        start.y * columns + start.x;

    g_score[start_index] = 0;

    open[open_count++] =
        start_index;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (open_count > 0)
    {
        /*
         * Select node with minimum f-score.
         */
        int best_position = 0;

        int best_index =
            open[0];

        AStarPoint best_point =
        {
            best_index % columns,
            best_index / columns
        };

        int best_f =
            g_score[best_index] +
            heuristic(
                best_point,
                goal
            );

        for (int i = 1; i < open_count; i++)
        {
            int index = open[i];

            AStarPoint point =
            {
                index % columns,
                index / columns
            };

            int f =
                g_score[index] +
                heuristic(
                    point,
                    goal
                );

            if (f < best_f)
            {
                best_f = f;
                best_position = i;
                best_index = index;
            }
        }

        /*
         * Remove selected node from open set.
         */
        open[best_position] =
            open[--open_count];

        if (best_index ==
            goal.y * columns + goal.x)
        {
            int result =
                g_score[best_index];

            free(g_score);
            free(open);
            free(closed);

            return result;
        }

        if (closed[best_index])
        {
            continue;
        }

        closed[best_index] = 1;

        AStarPoint current =
        {
            best_index % columns,
            best_index / columns
        };

        for (int direction = 0; direction < 4; direction++)
        {
            int nx =
                current.x + dx[direction];

            int ny =
                current.y + dy[direction];

            if (
                !valid(
                    rows,
                    columns,
                    grid,
                    nx,
                    ny
                )
            )
            {
                continue;
            }

            int neighbour =
                ny * columns + nx;

            if (closed[neighbour])
            {
                continue;
            }

            int tentative_g =
                g_score[best_index] + 1;

            if (
                tentative_g <
                g_score[neighbour]
            )
            {
                g_score[neighbour] =
                    tentative_g;

                open[open_count++] =
                    neighbour;
            }
        }
    }

    free(g_score);
    free(open);
    free(closed);

    return ASTAR_INF;
}
