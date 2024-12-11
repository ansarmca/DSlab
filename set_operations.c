#include <stdio.h>
#include <string.h>

#define UNIVERSAL_SIZE 26

// Convert a bit vector to a set representation and display it
void displaySetFromBitVector(int set) {
    printf("{ ");
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        if (set & (1 << i)) {
            printf("%c ", i + 'a');
        }
    }
    printf("}\n");
}

// Input elements and set the corresponding bits in the bit vector
int inputSetAsBitVector() {
    int set = 0;
    char input[100];
    printf("Enter elements of the set (without spaces, lowercase a-z): ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        set |= (1 << (input[i] - 'a'));
    }

    return set;
}

// Bitwise operations for union, intersection, and difference
int unionSetBitVector(int set1, int set2) {
    return set1 | set2;
}

int intersectionSetBitVector(int set1, int set2) {
    return set1 & set2;
}

int differenceSetBitVector(int set1, int set2) {
    return set1 & ~set2;
}

int complementSetBitVector(int set, int universalSet) {
    return ~set & universalSet;
}

int main() {
    int universalSet = (1 << UNIVERSAL_SIZE) - 1; // All 26 bits set
    int set1 = 0, set2 = 0, result = 0;

    printf("Universal set: { a b c d e f g h i j k l m n o p q r s t u v w x y z }\n");

    printf("Input Set 1:\n");
    set1 = inputSetAsBitVector();

    printf("Input Set 2:\n");
    set2 = inputSetAsBitVector();

    printf("\nSet 1: ");
    displaySetFromBitVector(set1);
    printf("Set 2: ");
    displaySetFromBitVector(set2);

    result = unionSetBitVector(set1, set2);
    printf("\nUnion of Set 1 and Set 2: ");
    displaySetFromBitVector(result);

    result = intersectionSetBitVector(set1, set2);
    printf("Intersection of Set 1 and Set 2: ");
    displaySetFromBitVector(result);

    result = differenceSetBitVector(set1, set2);
    printf("Difference of Set 1 and Set 2 (Set1 - Set2): ");
    displaySetFromBitVector(result);

    result = complementSetBitVector(set1, universalSet);
    printf("Complement of Set 1: ");
    displaySetFromBitVector(result);

    result = complementSetBitVector(set2, universalSet);
    printf("Complement of Set 2: ");
    displaySetFromBitVector(result);

    return 0;
}
