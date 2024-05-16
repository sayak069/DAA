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
void heapify(int a[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (parent >= 0)
    {
        if (a[parent] < a[i])
        {
            int t = a[parent];
            a[parent] = a[i];
            a[i] = t;
            heapify(a, n, parent);
        }
    }
}
void insert(int a[], int n, int x)
{
    n++;
    a[n - 1] = x;
    heapify(a, n, n - 1);
}
int main()
{
    int n, x;
    int *a = (int *)malloc(sizeof(int));
    printf("enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter val: ");
        scanf("%d", &x);
        insert(a, i, x);
    }
    display(a, 0, n - 1);
    return 0;
}