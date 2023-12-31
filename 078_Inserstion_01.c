#include <stdio.h>
#include <stdlib.h>

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

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Insert(struct Node **p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0)
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = *p;
        *p = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            if (*p == NULL)
                return; // handle the case where p becomes NULL
            p = &((*p)->next);
        }
        t->next = *p ? (*p)->next : NULL;
        *p = t;
    }
}

int main()
{
    Insert(&first, 0, 15);
    Insert(&first, 0, 8);
    Insert(&first, 0, 9);
    Insert(&first, 1, 10);

    Display(first);

    return 0;
}
