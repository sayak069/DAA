#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n, f = -1, r = -1;
int q[100];
bool isEmpty()
{
    if (f == -1)
        return 1;
    return 0;
}
void enQ(int x)
{
    if (isEmpty())
        f++;
    q[++r] = x;
}
int deQ()
{
    int x = q[f];
    if (f == r)
        f = r = -1;
    else
        f++;
    return x;
}
void bfs(int adj[][n], int v)
{
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int u = v;
    visited[v] = 1;
    do
    {
        for (int w = 0; w < n; w++)
        {
            if (adj[u][w] == 1 && visited[w] == 0)
            {
                visited[w] = 1;
                enQ(w);
            }
        }
        printf("%d ", u);
        if (isEmpty())
            break;
        else
            u = deQ();
    } while (1);
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
    bfs(adj, v);
    return 0;
}