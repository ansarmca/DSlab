#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int top = -1, inp_array[SIZE];

void push() {
    int x;
    if (top == SIZE - 1) {
        printf("\nStack Overflow!!");
    } else {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
        printf("\nElement %d pushed onto the stack.", x); // Display pushed element
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow!!");
    } else {
        printf("\nElement %d popped from the stack.", inp_array[top]); // Display popped element
        top = top - 1;
    }
}

void traversal() {
    if (top == -1) {
        printf("\nUnderflow!!");
    } else {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i) {
            printf("%d\n", inp_array[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nPerform operations on the stack:");
        printf("\n1. Push the element\n2. Pop the element\n3. Traversal\n4. End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                traversal();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!!");
        }
    }
}
