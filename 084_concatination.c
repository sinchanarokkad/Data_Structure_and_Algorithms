#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL, *second = NULL;

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void create(int A[], int n, struct Node **head) {
    int i;
    struct Node *t, *last;
    *head = (struct Node *)malloc(sizeof(struct Node));
    (*head)->data = A[0];
    (*head)->next = NULL;
    last = *head;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void concatenate(struct Node *p, struct Node *q) {
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}

int main() {
    int A[] = {10, 20, 30, 40};
    int B[] = {50, 60, 70, 80};
    
    create(A, 4, &first);
    create(B, 4, &second);

    printf("First List: ");
    display(first);

    printf("Second List: ");
    display(second);

    concatenate(first, second);

    printf("Concatenated List: ");
    display(first);

    return 0;
}
