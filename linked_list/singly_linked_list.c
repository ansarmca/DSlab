#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int data;
    struct Node *link;
};

struct Node *header = NULL;

struct Node *createNode(int data) {
    struct Node *newnode;
    newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void insertAtFront(int data) {
    struct Node *newnode = createNode(data);

    if (header == NULL) {
        header = newnode;
    } else {
        newnode->link = header;
        header = newnode;
    }
}

void insertAtEnd(int data) {
    struct Node *newnode = createNode(data);

    if (header == NULL) {
        header = newnode;
    } else {
        struct Node *current = header;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = newnode;
    }
}

void insertAtAny(int data, int position) {
    struct Node *newnode = createNode(data);

    if (position == 1) {
        newnode->link = header;
        header = newnode;
    } else {
        struct Node *current = header;
        int i;
        for (i = 1; i < position - 1 && current != NULL; i++) {
            current = current->link;
        }
        if (current == NULL) {
            printf("Position out of bounds. Inserting at the end.\n");
            insertAtEnd(data);
        } else {
            newnode->link = current->link;
            current->link = newnode;
        }
    }
}

void traversal() {
    struct Node *ptr = header;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main() {
    int position, data;

    insertAtFront(100);
    insertAtFront(200);
    insertAtFront(300);

    insertAtEnd(400);
    insertAtEnd(500);

    printf("List before insertion at any position:\n");
    traversal();

    printf("Enter position: ");
    scanf("%d", &position);

    printf("Enter data: ");
    scanf("%d", &data);
    
    insertAtAny(data, position);

    printf("List after insertion at specified position:\n");
    traversal();

    return 0;
}
