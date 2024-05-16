// TC=O((V+E)logV)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
int V;
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}
void printSol(int d[], int parent[], int s)
{
    printf("vertex\t\tdist\t\tpath");
    for (int i = 0; i < V; i++)
    {
        printf("\n%d\t\t%d\t\t%d ", i, d[i], s);
        printPath(parent, i);
    }
}
int extractMin(int d[], bool spt[])
{
    int min = INT_MAX, minIdx;
    for (int i = 0; i < V; i++)
    {
        if (spt[i] == false && d[i] <= min)
        {
            min = d[i];
            minIdx = i;
        }
    }
    return minIdx;
}
void dijkastra(int cost[][V])
{
    int d[V], parent[V], i, s;
    bool spt[V];
    for (i = 0; i < V; i++)
    {
        d[i] = INT_MAX;
        spt[i] = false;
        parent[i] = -1;
    }
    printf("enter source: ");
    scanf("%d", &s);
    d[s] = 0;
    // while Q is not empty
    for (int cnt = 0; cnt < V - 1; cnt++)
    {
        int u = extractMin(d, spt);
        spt[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!spt[v] && cost[u][v] && d[u] != INT_MAX && d[v] > d[u] + cost[u][v])
            {
                parent[v] = u;
                d[v] = d[u] + cost[u][v];
            }
        }
    }
    printSol(d, parent, s);
}
int main()
{
    FILE *fp = fopen("matrixDj.txt", "r");
    int i, j;
    if (fp == NULL)
    {
        printf("error in opening file");
        exit(0);
    }
    fscanf(fp, "%d", &V);
    int cost[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (fscanf(fp, "%d", &cost[i][j]) != 1)
                return 1;
        }
    }
    printf("cost matrix is\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    dijkastra(cost);
    fclose(fp);
    return 0;
}