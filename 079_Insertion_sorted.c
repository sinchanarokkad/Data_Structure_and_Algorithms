#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *create(int A[], int n)
{
    int i;
    struct Node *first = NULL, *t, *last;

    if (n > 0)
    {
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

    return first;
}

void SortedInsert(struct Node **p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*p == NULL)
        *p = t;
    else
    {
        while (*p && (*p)->data < x)
        {
            q = *p;
            p = &((*p)->next);
        }
        if (*p == q)
        {
            t->next = *p;
            *p = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    struct Node *first = create(A, 5);

    Display(first);

    SortedInsert(&first, 15);
    Display(first);

    return 0;
}
