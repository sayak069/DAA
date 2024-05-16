// TC=O(VE)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int V;
int *d;
void display()
{
    printf("\nvertex\t\tdist\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t\t%d\n", i, d[i]);
    }
}
bool bellmanFord(int G[][V], int s)
{
    d = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        d[i] = INT_MAX;
    d[s] = 0;
    for (int cnt = 0; cnt < V - 1; cnt++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (G[u][v] && d[v] > d[u] + G[u][v] && d[u] != INT_MAX)
                    d[v] = d[u] + G[u][v];
            }
        }
    }

    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (G[u][v] && d[u] != INT_MAX && d[v] > d[u] + G[u][v])
                return false;
        }
    }
    return true;
}
int main()
{
    FILE *fp = fopen("mtxBell.txt", "r");
    int i, j, s;
    if (fp == NULL)
    {
        printf("error in opening file");
        exit(0);
    }
    fscanf(fp, "%d", &V);
    int G[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (fscanf(fp, "%d", &G[i][j]) != 1)
                return 1;
        }
    }
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }
    do
    {
        printf("enter source: ");
        scanf("%d", &s);
        if (s >= 0 && s < V)
        {
            if (bellmanFord(G, s))
                display();
            else
                printf("negative weighted cycle exixts");
        }
        else
        {
            printf("wrong vertex");
            break;
        }
    } while (1);
    free(d);
    fclose(fp);
    return 0;
}