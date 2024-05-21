#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct edge
{
    int u, v;
    int cost;
} edge;
void heapify(edge *e, int edgecnt, int i)
{
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < edgecnt && e[left].cost < e[smallest].cost)
        smallest = left;
    if (right < edgecnt && e[right].cost < e[smallest].cost)
        smallest = right;
    if (smallest != i)
    {
        edge t = e[i];
        e[i] = e[smallest];
        e[smallest] = t;
        heapify(e, edgecnt, smallest);
    }
}
void buildHeap(edge *e, int edgecnt)
{
    for (int i = (edgecnt / 2) - 1; i >= 0; i--)
        heapify(e, edgecnt, i);
}
void Union(int i, int j, int parent[])
{
    parent[i] = j;
}
int Find(int i, int parent[])
{
    while (parent[i] >= 0)
        i = parent[i];
    return i;
}
int krushkal(int n, edge *e, int edgecnt, int t[][2])
{
    // construct min heap from edge cost
    buildHeap(e, edgecnt);

    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1;

    int i = 0, mincost = 0;
    while (i < n - 1 && edgecnt != 0)
    {
        // delete a min cost edge from heap and reheapify
        edge temp = e[0];
        e[0] = e[edgecnt - 1];
        edgecnt--;
        heapify(e, edgecnt, 0);

        int j = Find(temp.u, parent);
        int k = Find(temp.v, parent);
        if (j != k)
        {
            t[i][0] = temp.u;
            t[i][1] = temp.v;
            i++;
            mincost += temp.cost;
            Union(j, k, parent);
        }
    }
    if (i == n - 1)
    {
        printf("edges of spanning tree is\n");
        for (int i = 0; i < n - 1; i++)
            printf("%d %d\n", t[i][0] + 1, t[i][1] + 1);
        return mincost;
    }
    else
    {
        printf("no MST\n");
        return -1;
    }
}
int main()
{
    FILE *fp = fopen("mtxPrim.txt", "r");
    if (fp == NULL)
    {
        printf("error in opening file\n");
        exit(0);
    }
    int V, edgecnt = 0;
    fscanf(fp, "%d", &V);
    int cost[V][V];
    // read cost mtx
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (fscanf(fp, "%d", &cost[i][j]) != 1)
                return 1;
        }
    }
    // get edge count
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (cost[i][j] != INT_MAX)
                edgecnt++;
        }
    }
    // create edge array
    edge *e = (edge *)malloc(edgecnt * sizeof(edge));
    int k = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (cost[i][j] != INT_MAX)
            {
                e[k].u = i;
                e[k].v = j;
                e[k].cost = cost[i][j];
                k++;
            }
        }
    }
    int t[V - 1][2];
    int mincost = krushkal(V, e, edgecnt, t);
    printf("mincost of mst= %d\n", mincost);
    fclose(fp);
    return 0;
}