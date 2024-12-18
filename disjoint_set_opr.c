#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];  // Parent array
int rank[MAX];    // Rank array

// MakeSet function
void makeSet(int x) {
    parent[x] = x;  // Parent points to itself
    rank[x] = 0;    // Initial rank is 0
    printf("MakeSet: Created set for element %d\n", x);
}

// FindSet function with path compression
int findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]);  // Path compression
    }
    return parent[x];
}

// Union function
void unionSets(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX == rootY) {
        printf("Union: Elements %d and %d are already in the same set.\n", x, y);
        return;
    }

    // Union by rank
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }

    printf("Union: Merged sets containing %d and %d.\n", x, y);
}

// Main function
int main() {
    int choice, x, y, n;

    printf("Enter the number of elements in the universal set: ");
    scanf("%d", &n);

    // Initialize all elements
    for (int i = 0; i < n; i++) {
        makeSet(i);
    }

    // Menu-driven program
    while (1) {
        printf("\nDisjoint Set Operations:\n");
        printf("1. MakeSet\n");
        printf("2. FindSet\n");
        printf("3. Union\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to create a set for: ");
                scanf("%d", &x);
                if (x >= 0 && x < n) {
                    makeSet(x);
                } else {
                    printf("Invalid element. Please enter a value between 0 and %d.\n", n - 1);
                }
                break;

            case 2:
                printf("Enter element to find its set representative: ");
                scanf("%d", &x);
                if (x >= 0 && x < n) {
                    printf("FindSet: Representative of %d is %d\n", x, findSet(x));
                } else {
                    printf("Invalid element. Please enter a value between 0 and %d.\n", n - 1);
                }
                break;

            case 3:
                printf("Enter two elements to perform union: ");
                scanf("%d %d", &x, &y);
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    unionSets(x, y);
                } else {
                    printf("Invalid elements. Please enter values between 0 and %d.\n", n - 1);
                }
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
