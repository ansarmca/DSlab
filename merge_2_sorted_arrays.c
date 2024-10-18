#include <stdio.h>

// Function to sort an array 
void sortArray(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to merge two arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int arr3[])
{
    int i;
    for (i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }
    for (i = 0; i < size2; i++)
    {
        arr3[size1 + i] = arr2[i];
    }
}

int main()
{
    int i, n, j, k;

    // Input for the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the elements of the first array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("First Unsorted Array  : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Sorting the first array
    sortArray(arr1, n);

    // Printing the first sorted array
    printf("The first sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    

    // Input for the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    int arr2[k];
    printf("Enter the elements of the second array: \n");
    for (j = 0; j < k; j++)
    {
        scanf("%d", &arr2[j]);
    }

    printf("Second Unsorted Array : \n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Sorting the second array
    sortArray(arr2, k);

    // Printing the second sorted array
    printf("The second sorted array is: \n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Merging the two arrays into arr3
    int arr3[n + k];
    mergeArrays(arr1, n, arr2, k, arr3);

    printf("The merged unsorted array is: \n");
    for (i = 0; i < n + k; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Sorting the merged array
    sortArray(arr3, n + k);

    // Printing the merged sorted array
    printf("The merged sorted array is: \n");
    for (i = 0; i < n + k; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
