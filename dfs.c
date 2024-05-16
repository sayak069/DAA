#include <stdio.h>
int n;
int visited[100] = {0};
void dfs(int adj[][n], int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int w = 0; w < n; w++)
    {
        if (adj[v][w] == 1 && visited[w] == 0)
            dfs(adj, w);
    }
}
int main()
{

    FILE *fp = fopen("mtxBFS.txt", "r");
    int i, j;
    if (fp == NULL)
    {
        printf("error in opening file");
        exit(0);
    }
    // read the no of vertices from file
    fscanf(fp, "%d", &n);
    // read adj mtx
    int adj[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (fscanf(fp, "%d", &adj[i][j]) != 1)
                return 1;
        }
    }
    int v;
    printf("enter start vertex: ");
    scanf("%d", &v);
    dfs(adj, v);
    return 0;
}