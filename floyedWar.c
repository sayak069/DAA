// TC=O(V^3)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int V;
void printSol(int d[][V], int p[][V])
{
    printf("shortest path\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("predecessor matrix\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}
void floyed(int W[][V])
{
    int d[V][V], p[V][V];
    int i, j, k;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            d[i][j] = W[i][j];
            p[i][j] = 0;
        }
    }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k + 1;
                }
            }
        }
    }
    printSol(d, p);
}
int main()
{
    FILE *fp = fopen("mtxFloyed.txt", "r");
    int i, j;
    if (fp == NULL)
    {
        printf("error in opening file");
        exit(0);
    }
    fscanf(fp, "%d", &V);
    int W[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (fscanf(fp, "%d", &W[i][j]) != 1)
                return 1;
        }
    }
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }
    floyed(W);
    return 0;
}