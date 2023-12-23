#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Min(struct Node *p)
{
    int min = INT_MAX;

    while (p)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int RMin(struct Node *p)
{
    int x = 0;

    if (p == NULL)
        return INT_MAX;
    x = RMin(p->next);
    if (x < p->data)
        return x;
    else
        return p->data;
}

void freeList(struct Node *p)
{
    struct Node *temp;
    while (p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    printf("Min %d\n", Min(first));
    printf("RMin %d\n", RMin(first));

    
    freeList(first);

    return 0;
}
