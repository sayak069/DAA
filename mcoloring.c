#include <stdio.h>
#include <stdlib.h>
int *x;
int n, m, cnt = 0;
int G[100][100];
void nextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        int j;
        for (j = 0; j < n; j++)
        {
            if (G[k][j] && x[k] == x[j])
                break;
        }
        if (j == n)
            return;
    } while (1);
}
void mcoloring(int k)
{
    do
    {
        nextValue(k);
        if (x[k] == 0)
            return;
        if (k == n - 1)
        {
            for (int i = 0; i < n; i++)
                printf("%d ", x[i]);
            printf("\n");
            cnt++;
        }
        else
            mcoloring(k + 1);
    } while (1);
}
int main()
{
    FILE *fp = fopen("mtxMColor.txt", "r");
    if (fp == NULL)
    {
        printf("error in opening file\n");
        exit(0);
    }
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(fp, "%d", &G[i][j]) != 1)
                return 1;
        }
    }
    printf("enter no of colors: ");
    scanf("%d", &m);
    x = (int *)calloc(n, sizeof(int));
    mcoloring(0);
    printf("total soln= %d\n", cnt);
    return 0;
}