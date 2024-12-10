#include <stdio.h>
#include <string.h>

#define CHAR_SET_SIZE 26

// Set the bit corresponding to the character
void set_bit(char *bit_vector, char c) {
    if (c >= 'a' && c <= 'z') {
        bit_vector[c - 'a'] = 1;
    }
}

// Perform the union of two sets
void union_sets(const char *set1, const char *set2, char *result) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        result[i] = set1[i] | set2[i];
    }
}

// Perform the intersection of two sets
void intersection_sets(const char *set1, const char *set2, char *result) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        result[i] = set1[i] & set2[i];
    }
}

// Perform the difference of two sets (set1 - set2)
void difference_sets(const char *set1, const char *set2, char *result) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        result[i] = set1[i] & ~set2[i];
    }
}

// Complement a set
void complement_set(const char *set, char *result) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        result[i] = set[i] ? 0 : 1;
    }
}

// Print a set
void print_set(const char *set) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        if (set[i]) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
}

int main() {
    char set1[CHAR_SET_SIZE] = {0};
    char set2[CHAR_SET_SIZE] = {0};
    char result[CHAR_SET_SIZE] = {0};
    char input[CHAR_SET_SIZE + 1];

    printf("Enter set1: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        set_bit(set1, input[i]);
    }

    printf("Enter set2: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        set_bit(set2, input[i]);
    }

    printf("Set1: ");
    print_set(set1);

    printf("Set2: ");
    print_set(set2);

    union_sets(set1, set2, result);
    printf("Union: ");
    print_set(result);

    intersection_sets(set1, set2, result);
    printf("Intersection: ");
    print_set(result);

    difference_sets(set1, set2, result);
    printf("Difference (Set1 - Set2): ");
    print_set(result);

    complement_set(set1, result);
    printf("Complement of Set1: ");
    print_set(result);

    return 0;
}
