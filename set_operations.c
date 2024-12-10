#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 26 // Size of the universal set (alphabet)

// Function to initialize a set with 0 (false)
void initializeSet(bool set[]) {
    for (int i = 0; i < SIZE; i++) {
        set[i] = false;
    }
}

// Function to add elements to the set
void addElements(bool set[], char elements[]) {
    for (int i = 0; elements[i] != '\0'; i++) {
        if (elements[i] >= 'a' && elements[i] <= 'z') {
            set[elements[i] - 'a'] = true;
        }
    }
}

// Function to display the set
void displaySet(bool set[]) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set[i]) {
            printf("%c ", i + 'a');
        }
    }
    printf("}\n");
}

// Function to compute union
void unionSet(bool set1[], bool set2[], bool result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = set1[i] || set2[i];
    }
}

// Function to compute intersection
void intersectionSet(bool set1[], bool set2[], bool result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = set1[i] && set2[i];
    }
}

// Function to compute difference (set1 - set2)
void differenceSet(bool set1[], bool set2[], bool result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = set1[i] && !set2[i];
    }
}

// Function to compute symmetric difference
void symmetricDifferenceSet(bool set1[], bool set2[], bool result[]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = (set1[i] || set2[i]) && !(set1[i] && set2[i]);
    }
}

int main() {
    char set1Input[SIZE], set2Input[SIZE];
    bool set1[SIZE], set2[SIZE];
    bool result[SIZE];

    // Initialize sets
    initializeSet(set1);
    initializeSet(set2);
    initializeSet(result);

    // Input sets
    printf("Enter elements of set 1 (lowercase letters only): ");
    scanf("%s", set1Input);
    printf("Enter elements of set 2 (lowercase letters only): ");
    scanf("%s", set2Input);

    // Add elements to sets
    addElements(set1, set1Input);
    addElements(set2, set2Input);

    // Perform operations
    printf("\nUnion: ");
    unionSet(set1, set2, result);
    displaySet(result);

    printf("Intersection: ");
    intersectionSet(set1, set2, result);
    displaySet(result);

    printf("Difference (set1 - set2): ");
    differenceSet(set1, set2, result);
    displaySet(result);

    printf("Symmetric Difference: ");
    symmetricDifferenceSet(set1, set2, result);
    displaySet(result);

    return 0;
}
