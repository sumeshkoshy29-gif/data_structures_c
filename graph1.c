#include <stdio.h>

int a[10][10], t[10][10];
int visited[10], stack[10];
int top = -1, n;

void dfs1(int v)
{
    int i;
    visited[v] = 1;

    for(i = 0; i < n; i++)
    {
        if(a[v][i] == 1 && visited[i] == 0)
            dfs1(i);
    }

    stack[++top] = v;
}

void dfs2(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++)
    {
        if(t[v][i] == 1 && visited[i] == 0)
            dfs2(i);
    }
}

int main()
{
    int i, j, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            t[j][i] = a[i][j];
        }
    }

    // First DFS
    for(i = 0; i < n; i++)
        visited[i] = 0;

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
            dfs1(i);
    }

    // Reset visited array
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");

    // Second DFS
    while(top != -1)
    {
        v = stack[top--];

        if(visited[v] == 0)
        {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}

