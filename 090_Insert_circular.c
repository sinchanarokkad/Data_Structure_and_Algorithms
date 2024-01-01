#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Head;


void Insert(struct Node **head, int position, int x)
{
    struct Node *t, *p;
    int i;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (position == 0)
    {
        if (*head == NULL)
        {
            *head = t;
            t->next = *head;
        }
        else
        {
            p = *head;
            while (p->next != *head)
                p = p->next;
            p->next = t;
            t->next = *head;
            *head = t;
        }
    }
    else
    {
        p = *head;
        for (i = 0; i < position - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}


void Display(struct Node *h)
{
    struct Node *temp = h;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != h);
    printf("\n");
}

int main()
{
    Head = NULL;

  
    Insert(&Head, 0, 1);
    Insert(&Head, 1, 2);
    Insert(&Head, 2, 3);

   
    printf("Circular Linked List: ");
    Display(Head);

    return 0;
}
