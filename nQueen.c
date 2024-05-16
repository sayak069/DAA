// TC= O(n!)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *x;
int cnt = 0;
bool place(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
            return false;
    }
    return true;
}
void nQueen(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n - 1)
            {
                cnt++;
                for (int j = 0; j < n; j++)
                    printf("%d ", x[j] + 1);
                printf("\n");
            }
            else
                nQueen(k + 1, n);
        }
    }
}
int main()
{
    int n;
    printf("enter size of chess board: ");
    scanf("%d", &n);
    x = (int *)calloc(n, sizeof(int));
    nQueen(0, n);
    printf("total possible solutions: %d\n", cnt);
    free(x);
    return 0;
}