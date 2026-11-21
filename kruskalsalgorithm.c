#include <stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i] != 0)
        i = parent[i];

    return i;
}

int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int cost[10][10];
    int i, j, u, v, a, b;
    int min, mincost = 0;
    int n, edges = 1;

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
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("%d -> %d = %d\n", a, b, min);
            mincost = mincost + min;
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

