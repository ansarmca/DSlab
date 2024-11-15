#include <stdio.h>
#include <stdlib.h>

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
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                printf("Enter the data to insert: ");
                scanf("%d", &data);                 
                insertAtAny(data, position);
                break;
                
            case 4:
                printf("Current List: ");
                traversal();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
