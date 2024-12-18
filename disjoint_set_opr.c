#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the structure for each disjoint set element
typedef struct {
    int parent;
    int rank;
} DisjointSet;

// Declare the disjoint set array
DisjointSet sets[MAX];

// Function to initialize a set for an element (MakeSet)
void makeSet(int x) {
    sets[x].parent = x;  // Parent points to itself
    sets[x].rank = 0;    // Initial rank is 0
    printf("MakeSet: Created set for element %d\n", x);
}

// Function to find the representative of the set containing x (FindSet)
int findSet(int x) {
    if (sets[x].parent != x) {
        sets[x].parent = findSet(sets[x].parent);  // Path compression
    }
    return sets[x].parent;
}

// Function to perform the union of two sets (Union)
void unionSets(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX == rootY) {
        printf("Union: Elements %d and %d are already in the same set.\n", x, y);
        return;
    }

    // Attach smaller rank tree under larger rank tree
    if (sets[rootX].rank < sets[rootY].rank) {
        sets[rootX].parent = rootY;
    } else if (sets[rootX].rank > sets[rootY].rank) {
        sets[rootY].parent = rootX;
    } else {
        sets[rootY].parent = rootX;
        sets[rootX].rank++;
    }

    printf("Union: Merged sets containing %d and %d.\n", x, y);
}

// Main function with menu
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

