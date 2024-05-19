// TC=O(n^3)
#include <stdio.h>
#include <limits.h>
#define max 20
void printParenthesization(int i, int j, int s[][max])
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        // similar to msort calls
        printParenthesization(i, s[i][j], s);
        printParenthesization(s[i][j] + 1, j, s);
        printf(")");
    }
}
int mtxChain(int n, int dim[])
{
    int m[max][max] = {0};
    int s[max][max] = {0};
    // d= j - i
    for (int d = 1; d <= n - 1; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;
            int min = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    printf("\nM table\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }
    printf("\nS table\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d\t", s[i][j]);
        printf("\n");
    }
    printParenthesization(1, n, s);
    return m[1][n];
}
int main()
{
    int n;
    int dim[max];
    printf("enter no of matrices: ");
    scanf("%d", &n);
    printf("enter dimension array: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &dim[i]);
    printf("\nmin no of multiplication= %d\n", mtxChain(n, dim));
    return 0;
}