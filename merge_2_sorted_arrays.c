#include <stdio.h>

int main(void)
{
    int i, n, j, k, max = 0;

    // Input for the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the elements of the first array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        if (arr1[i] > max) {
            max = arr1[i];  // Find the maximum element for counting sort
        }
    }

    // Input for the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    int arr2[k];
    printf("Enter the elements of the second array: \n");
    for (j = 0; j < k; j++)
    {
        scanf("%d", &arr2[j]);
        if (arr2[j] > max) {
            max = arr2[j];  // Update max if needed
        }
    }

    // Sorting the first array using Counting Sort
    int count1[max + 1];  // Array to store count of each element (0 to max)
    for (i = 0; i <= max; i++) {
        count1[i] = 0;  // Initialize count array with 0
    }
    for (i = 0; i < n; i++) {
        count1[arr1[i]]++;  // Count each element in arr1
    }

    printf("The first sorted array is: \n");
    for (i = 0; i <= max; i++) {
        while (count1[i]--) {  // Print sorted arr1
            printf("%d ", i);
        }
    }
    printf("\n");

    // Sorting the second array using Counting Sort
    int count2[max + 1];  // Array to store count for the second array
    for (i = 0; i <= max; i++) {
        count2[i] = 0;  // Initialize count array with 0
    }
    for (i = 0; i < k; i++) {
        count2[arr2[i]]++;  // Count each element in arr2
    }

    printf("The second sorted array is: \n");
    for (i = 0; i <= max; i++) {
        while (count2[i]--) {  // Print sorted arr2
            printf("%d ", i);
        }
    }
    printf("\n");

    // Merging the two arrays and sorting the merged array using Counting Sort
    int arr3[n + k];  // Merged array
    for (i = 0; i < n; i++) {
        arr3[i] = arr1[i];  // Copy arr1 into arr3
    }
    for (j = 0; j < k; j++) {
        arr3[n + j] = arr2[j];  // Copy arr2 into arr3
    }

    int count3[max + 1];  // Array to count the merged array elements
    for (i = 0; i <= max; i++) {
        count3[i] = 0;  // Initialize count array with 0
    }
    for (i = 0; i < n + k; i++) {
        count3[arr3[i]]++;  // Count elements in arr3
    }

    printf("The merged sorted array is: \n");
    for (i = 0; i <= max; i++) {
        while (count3[i]--) {  // Print sorted merged array
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
