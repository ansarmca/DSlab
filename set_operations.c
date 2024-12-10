#include <stdio.h>
#include <string.h>

#define UNIVERSAL_SIZE 26

// Function to input a set and convert it to a bit vector
int inputSet() {
    char input[100];
    int set = 0; // Bit vector initialized to 0
    printf("Enter elements of the set (without spaces, lowercase a-z): ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        set |= (1 << (input[i] - 'a')); // Set the bit corresponding to the character
    }
    return set;
}

// Function to display a set from its bit vector representation
void displaySet(int set) {
    printf("{ ");
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        if (set & (1 << i)) {
            printf("%c ", i + 'a');
        }
    }
    printf("}\n");
}

// Function to perform union of two sets
int unionSet(int set1, int set2) {
    return set1 | set2; // Bitwise OR
}

// Function to perform intersection of two sets
int intersectionSet(int set1, int set2) {
    return set1 & set2; // Bitwise AND
}

// Function to perform difference of two sets (set1 - set2)
int differenceSet(int set1, int set2) {
    return set1 & ~set2; // Bitwise AND with complement
}

// Function to perform complement of a set with respect to the universal set
int complementSet(int set) {
    int universalSet = (1 << UNIVERSAL_SIZE) - 1; // All bits set for a-z
    return universalSet & ~set; // Bitwise AND with complement
}

int main() {
    printf("Universal set: { a b c d e f g h i j k l m n o p q r s t u v w x y z }\n");

    // Input sets
    printf("Input Set 1:\n");
    int set1 = inputSet();

    printf("Input Set 2:\n");
    int set2 = inputSet();

    printf("\nSet 1: ");
    displaySet(set1);

    printf("Set 2: ");
    displaySet(set2);

    // Union
    int unionResult = unionSet(set1, set2);
    printf("\nUnion of Set 1 and Set 2: ");
    displaySet(unionResult);

    // Intersection
    int intersectionResult = intersectionSet(set1, set2);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(intersectionResult);

    // Difference
    int differenceResult = differenceSet(set1, set2);
    printf("Difference of Set 1 and Set 2 (Set1 - Set2): ");
    displaySet(differenceResult);

    // Complement of Set 1
    int complementResult1 = complementSet(set1);
    printf("Complement of Set 1: ");
    displaySet(complementResult1);

    // Complement of Set 2
    int complementResult2 = complementSet(set2);
    printf("Complement of Set 2: ");
    displaySet(complementResult2);

    return 0;
}
