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
    struct Node *newnode;
    newnode = createNode(data);

    if (header == NULL) {
        header = newnode;
    } else {
        newnode->link = header;
        header = newnode;
    }
}

void printList() {
    struct Node *current = header;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}

int main() {
    insertAtFront(10);
    insertAtFront(20);

    printList();

    return 0;
}
