#include <stdio.h>

int main()
{
    int n, i, j, min, u, v;
    int cost[10][10], visited[10] = {0};
    int mincost = 0, edges = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] == 1 && visited[j] == 0)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(min == 999)
        {
            printf("Graph is not connected\n");
            return 0;
        }

        printf("%d -> %d = %d\n", u, v, min);

        mincost = mincost + min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

