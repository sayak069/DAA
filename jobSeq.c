#include <stdio.h>
#include <stdlib.h>
typedef struct js
{
    int id, dl, pr;
} js;
int max_deadline;
void sortByProfit(int n, js *a)
{
    max_deadline = a[0].dl;
    for (int i = 1; i < n; i++)
    {
        if (a[i].dl > max_deadline)
            max_deadline = a[i].dl;
        js temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].pr < temp.pr)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
void jobSeq(int n, js *a)
{
    sortByProfit(n, a);
    int *day = (int *)calloc(max_deadline + 1, sizeof(int));
    int *res = (int *)calloc(max_deadline + 1, sizeof(int));
    int tp = 0;
    for (int i = 0; i < n; i++)
    {
        if (day[a[i].dl] == 0)
        {
            day[a[i].dl] = 1;
            res[a[i].dl] = a[i].id;
            tp += a[i].pr;
        }
        else
        {
            int j = a[i].dl - 1;
            while (j >= 1)
            {
                if (day[j] == 0)
                {
                    day[j] = 1;
                    res[j] = a[i].id;
                    tp += a[i].pr;
                    break;
                }
                j--;
            }
        }
    }
    printf("seq of jobs is: ");
    for (int i = 0; i < max_deadline + 1; i++)
    {
        if (day[i] == 1)
            printf("%d ", res[i]);
    }
    printf("\ntotal profit is: %d", tp);
    free(day);
    free(res);
}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    js *a = (js *)malloc(n * sizeof(js));
    for (int i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        printf("enter profit: ");
        scanf("%d", &a[i].pr);
        printf("enter deadline: ");
        scanf("%d", &a[i].dl);
    }
    jobSeq(n, a);
    free(a);
    return 0;
}