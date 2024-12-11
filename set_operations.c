#include <stdio.h>
#include <string.h>

#define UNIVERSAL_SIZE 26

void inputSet(int set[]) {
    char input[100];
    printf("Enter elements of the set (without spaces, lowercase a-z): ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        set[input[i] - 'a'] = 1;
    }
}

void displaySet(int set[]) {
    printf("{ ");
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        if (set[i]) {
            printf("%c ", i + 'a');
        }
    }
    printf("}\n");
}

void unionSet(int set1[], int set2[], int result[]) {
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        result[i] = set1[i] | set2[i];
    }
}

void intersectionSet(int set1[], int set2[], int result[]) {
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        result[i] = set1[i] & set2[i];
    }
}

void differenceSet(int set1[], int set2[], int result[]) {
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        result[i] = set1[i] & !set2[i];
    }
}

void complementSet(int set[], int universalSet[], int result[]) {
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        result[i] = universalSet[i] & !set[i];
    }
}

int main() {
    int universalSet[UNIVERSAL_SIZE] = {1};
    int set1[UNIVERSAL_SIZE] = {0}, set2[UNIVERSAL_SIZE] = {0};
    int result[UNIVERSAL_SIZE] = {0};
    for (int i = 0; i < UNIVERSAL_SIZE; i++) {
        universalSet[i] = 1;
    }

    printf("Universal set: { a b c d e f g h i j k l m n o p q r s t u v w x y z }\n");

    printf("Input Set 1:\n");
    inputSet(set1);

    printf("Input Set 2:\n");
    inputSet(set2);

    printf("\nSet 1: ");
    displaySet(set1);
    printf("Set 2: ");
    displaySet(set2);

    unionSet(set1, set2, result);
    printf("\nUnion of Set 1 and Set 2: ");
    displaySet(result);

    intersectionSet(set1, set2, result);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(result);

    differenceSet(set1, set2, result);
    printf("Difference of Set 1 and Set 2 (Set1 - Set2): ");
    displaySet(result);

    complementSet(set1, universalSet, result);
    printf("Complement of Set 1: ");
    displaySet(result);

    complementSet(set2, universalSet, result);
    printf("Complement of Set 2: ");
    displaySet(result);

    return 0;
}
