#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int prims(int n, int cost[][n], int t[][2])
{
    int i, j, k, l, mc = INT_MAX;
    // find mincost edge (k,l)
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (cost[i][j] < mc)
            {
                mc = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
    t[0][0] = k;
    t[0][1] = l;

    int near[n];
    for (i = 0; i < n; i++)
    {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = near[l] = -1;
    // add rest n-2 edges
    for (i = 1; i < n - 1; i++)
    {
        int min = INT_MAX;
        for (int idx = 0; idx < n; idx++)
        {
            if (near[idx] != -1 && cost[idx][near[idx]] < min)
            {
                min = cost[idx][near[idx]];
                j = idx;
            }
        }

        mc += cost[j][near[j]];
        t[i][0] = j;
        t[i][1] = near[j];
        
        near[j]=-1;
        // update near
        for (int k1 = 0; k1 < n; k1++)
        {
            if (near[k1] != -1 && cost[k1][near[k1]] > cost[k1][j])
            {
                near[k1]=j;
            }
        }
    }
    return mc;
}
int main()
{
    FILE *fp = fopen("mtxPrim.txt", "r");
    if (fp == NULL)
    {
        printf("error in opening file\n");
        exit(0);
    }
    int row, col, i, j;
    fscanf(fp, "%d %d", &row, &col);
    int cost[row][col];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (fscanf(fp, "%d", &cost[i][j]) != 1)
                return 1;
        }
    }
    int t[row - 1][2];
    int mincost = prims(row, cost, t);
    printf("mincost of spanning tree is= %d\n", mincost);
    printf("edges of spanning tree is\n");
    for (i = 0; i < row - 1; i++)
    {
        printf("%d %d\n", t[i][0], t[i][1]);
    }
    fclose(fp);
    return 0;
}