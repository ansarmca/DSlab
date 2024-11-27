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
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertAtAny(int data, int position) {
    struct Node *new_node = createNode(data);
    struct Node *temp = header;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void deleteAtFront() {
    if (header == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = header;
    header = header->next;

    if (header != NULL) {
        header->prev = NULL;
    }
    free(temp);
}

void traversal() {
    struct Node *temp = header;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    int data, position;

    while (1) {
        printf("\n1. Insert at Front\n2. Insert at End\n3. Insert at Any\n4. Delete at Front\n5. Traverse\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);                
                insertAtAny(data, position);
                break;
            case 4:
                deleteAtFront();
                break;
            case 5:
                traversal();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
