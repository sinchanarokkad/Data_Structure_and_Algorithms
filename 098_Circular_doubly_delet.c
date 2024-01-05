#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
       
        struct Node* last = (*head)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}


void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* toDelete = NULL;

    
    do {
        if (current->data == key) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != *head);

    if (toDelete == NULL) {
        printf("Node with key %d not found\n", key);
        return;
    }

    if (toDelete == *head) {
        *head = toDelete->next;
    }
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;


    free(toDelete);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;

  
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}


int main() {
    struct Node* head = NULL;

   
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

   
    printf("Initial circular doubly linked list: ");
    displayList(head);

   
    deleteNode(&head, 2);
    printf("After deleting node with value 2: ");
    displayList(head);

   
    deleteNode(&head, 1);
    printf("After deleting node with value 1: ");
    displayList(head);

    
    deleteNode(&head, 4);
    printf("After deleting node with value 4: ");
    displayList(head);

   
    deleteNode(&head, 3);
    printf("After deleting node with value 3: ");
    displayList(head);

    return 0;
}
