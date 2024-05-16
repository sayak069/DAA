#include <stdio.h>
#include <stdlib.h>
typedef struct ks
{
    float profit;
    float weight;
    float pByw;
} ks;
void print(ks *k, int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f\t", k[i].profit);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%.2f\t", k[i].weight);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%.2f\t", k[i].pByw);
    printf("\n");
}
void swap(ks *ks1, ks *ks2)
{
    ks t = *ks1;
    *ks1 = *ks2;
    *ks2 = t;
}
int partition(ks *a, int s, int e)
{
    float pi = a[e].pByw;
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (a[j].pByw > pi)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[e], &a[i + 1]);
    return i + 1;
}
void qusort(ks *a, int s, int e)
{
    if (s >= e)
        return;
    int p = partition(a, s, e);
    qusort(a, s, p - 1);
    qusort(a, p + 1, e);
}
float knapsack(int m, int n, ks *k)
{
    qusort(k, 0, n - 1);
    printf("after sort\n");
    print(k, n);
    int i;
    float tp = 0.0;
    for (i = 0; i < n; i++)
    {
        if (k[i].weight <= m)
        {
            m -= k[i].weight;
            tp += k[i].profit;
        }
        else
        {
            tp += m / k[i].weight * k[i].profit;
            break;
        }
    }
    return tp;
}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    ks *ks1 = (ks *)malloc(n * sizeof(ks));
    for (int i = 0; i < n; i++)
    {
        printf("enter profit: ");
        scanf("%f", &ks1[i].profit);
        printf("enter weight: ");
        scanf("%f", &ks1[i].weight);
        ks1[i].pByw = ks1[i].profit / ks1[i].weight;
    }
    print(ks1, n);
    int m;
    printf("enter max weight: ");
    scanf("%d", &m);
    printf("total profit= %.2f\n", knapsack(m, n, ks1));
    return 0;
}