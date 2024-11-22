#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *header = NULL;

struct Node *createNode(int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insertAtFront(int data) {
    struct Node *new_node = createNode(data);

    if (header == NULL) {
        header = new_node;
    } else {
        new_node->next = header;
        header->prev = new_node;
        header = new_node;
    }
}

void insertAtEnd(int data) {
    struct Node *new_node = createNode(data);

    if (header == NULL) {
        header = new_node;
    } else {
        struct Node *temp = header;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Adjust pointers to add the new node
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void printList() {
    struct Node *temp = header;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtFront(10);
    insertAtFront(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printList();

    return 0;
}