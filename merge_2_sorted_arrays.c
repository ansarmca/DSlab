#include <stdio.h>

int main(void)
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

    // Input for the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    int arr2[k];
    printf("Enter the elements of the second array: \n");
    for (j = 0; j < k; j++)
    {
        scanf("%d", &arr2[j]);
    }

    // Merging the two arrays into arr3
    int arr3[n + k];
    for (i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (j = 0; j < k; j++)
    {
        arr3[n + j] = arr2[j];
    }

    // Sorting the merged array using simple bubble sort
    int total_size = n + k;
    for (i = 0; i < total_size - 1; i++)
    {
        for (j = 0; j < total_size - i - 1; j++)
        {
            if (arr3[j] > arr3[j + 1])
            {
                // Swap the elements
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }

    // Printing the merged sorted array
    printf("The merged sorted array is: \n");
    for (i = 0; i < total_size; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
