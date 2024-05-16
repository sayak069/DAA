#include <stdio.h>
#include <stdlib.h>
void display(int *a, int s, int e)
{
    for (int i = s; i <= e; i++)
        printf("%d ", a[i]);
}
void maxMin(int *a, int i, int j, int *max, int *min)
{
    if (i == j)
        *max = *min = a[i];
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            *min = a[i];
            *max = a[j];
        }
        else
        {
            *max = a[i];
            *min = a[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1 = *max, min1 = *min;
        // left part
        maxMin(a, i, mid, max, min);

        printf("\n");
        display(a, i, mid);
        printf("\nmaxl= %d", *max);
        printf("\nminl= %d", *min);
        // right part
        maxMin(a, mid + 1, j, &max1, &min1);

        printf("\n");
        display(a, mid + 1, j);
        printf("\nmaxr= %d", max1);
        printf("\nminr= %d", min1);
        // compare
        if (*max < max1)
            *max = max1;
        if (*min > min1)
            *min = min1;
    }
}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    printf("enter ele: ");
    for (int i = 0; i < n; i++)
        scanf("%d", (a + i));

    display(a, 0, n - 1);

    int max = 0, min = 0;
    maxMin(a, 0, n - 1, &max, &min);
    printf("\nmax= %d", max);
    printf("\nmin= %d", min);
    return 0;
}