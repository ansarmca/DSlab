#include <stdio.h>
#include <string.h>

#define CHAR_SET_SIZE 26

void set_bit(char *bit_vector, char c) {
    bit_vector[c - 'a'] = 1;
}

// Using pointers to modify the input sets directly
void union_sets(char *set1, char *set2) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        set1[i] |= set2[i];
    }
}

// Using pointers to modify the input sets directly
void intersection_sets(char *set1, char *set2) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        set1[i] &= set2[i];
    }
}

// Using pointers to modify the input sets directly
void difference_sets(char *set1, char *set2) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        set1[i] &= ~set2[i];
    }
}

// Using pointers to modify the input sets directly
void complement_set(char *set) {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        set[i] = ~set[i];
    }
}

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

    // Modified to directly modify the input sets
    union_sets(set1, set2);
    printf("Union: ");
    print_set(set1);

    // Reset set1 to original state
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        set1[i] = set2[i]; // Copy set2 to set1
    }

    intersection_sets(set1, set2);
    printf("Intersection: ");
    print_set(set1);

    // Reset set1 to original state
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        set1[i] = set2[i]; // Copy set2 to set1
    }

    difference_sets(set1, set2);
    printf("Difference (Set1 - Set2): ");
    print_set(set1);

    complement_set(set1);
    printf("Complement of Set1: ");
    print_set(set1);

    return 0;
}
