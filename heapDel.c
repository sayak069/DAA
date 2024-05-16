#include <stdio.h>
#include <stdlib.h>
void display(int a[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void heapify(int *a, int n, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int lar = i;
    if (l < n && a[l] > a[lar])
    {
        lar = l;
    }
    if (r < n && a[r] > a[lar])
    {
        lar = r;
    }
    if (lar != i)
    {
        int t = a[lar];
        a[lar] = a[i];
        a[i] = t;
        heapify(a, n, lar);
    }
}
void delete(int *a, int *n)
{
    a[0] = a[*n - 1];
    (*n)--;
    heapify(a, *n, 0);
}
int main()
{
    int n, ch;
    int *a = (int *)malloc(sizeof(int));
    printf("enter size: ");
    scanf("%d", &n);
    printf("enter ele: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    display(a, 0, n - 1);
    while (1)
    {
        printf("enter 1 to del and 0 to exit: ");
        scanf("%d", &ch);
        if (ch)
        {
            delete (a, &n);
            display(a, 0, n - 1);
        }
        else
            exit(0);
    }
    return 0;
}