#include <stdio.h>

// Function to sort an array 
void sortArray(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to merge two arrays 
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int arr3[]) {
    int i;
    for (i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }
    for (i = 0; i < size2; i++) {
        arr3[size1 + i] = arr2[i];
    }
}

int main() {
    int i, n, k;

    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int arr1[n];
    
    printf("Enter the elements of the first array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    // Display unsorted first array
    printf("First Unsorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Display the first sorted array
    sortArray(arr1, n);
    printf("The first sorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    int arr2[k];

    printf("Enter the elements of the second array: \n");
    for (i = 0; i < k; i++) {
        scanf("%d", &arr2[i]);
    }

    // Display unsorted second array
    printf("Second Unsorted Array: \n");
    for (i = 0; i < k; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Display the second sorted array
    sortArray(arr2, k);
    printf("The second sorted array is: \n");
    for (i = 0; i < k; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Merge the two sorted arrays
    int arr3[n + k];
    mergeArrays(arr1, n, arr2, k, arr3);

    // Display the merged unsorted array
    printf("The merged unsorted array is: \n");
    for (i = 0; i < n + k; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Sort the merged array 
    sortArray(arr3, n + k);
    printf("The merged sorted array is: \n");
    for (i = 0; i < n + k; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
