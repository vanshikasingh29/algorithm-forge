#include "../include/floyd_warshall.h"

void floyd_warshall(
    int vertex_count,
    int distance[][vertex_count]
)
{
    /*
     * k = intermediate vertex
     * i = source
     * j = destination
     *
     * Recurrence:
     *
     * D[i][j] =
     * min(
     *     D[i][j],
     *     D[i][k] + D[k][j]
     * )
     */
    for (int k = 0; k < vertex_count; k++)
    {
        for (int i = 0; i < vertex_count; i++)
        {
            if (distance[i][k] == FW_INF)
            {
                continue;
            }

            for (int j = 0; j < vertex_count; j++)
            {
                if (distance[k][j] == FW_INF)
                {
                    continue;
                }

                int candidate =
                    distance[i][k] +
                    distance[k][j];

                if (candidate < distance[i][j])
                {
                    distance[i][j] = candidate;
                }
            }
        }
    }
}
