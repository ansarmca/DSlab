/*
 * C Program to merge two sorted arrays using for loop
 */
 
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int i, n, j, k;
    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the elements of the first array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    int arr2[k];
    printf("Enter the elements of the second array: \n");
    for (j = 0; j < k; j++)
    {
        scanf("%d", &arr2[j]);
    }
    int arr3[n + k];
    i = j = 0;
    int in;
    for (in = 0; in < n + k; in ++)
    {
        if (i < n && j < k)
        {
            if (arr1[i] < arr2[j])
            {
                arr3[in] = arr1[i];
                i++;
            }
            else
            {
                arr3[in] = arr2[j];
                j++;
            }
        }
        else if (i < n)
        {
            arr3[in] = arr1[i];
            i++;
        }
        else
        {
            arr3[in] = arr2[j];
            j++;
        }
    }
    printf("The merged array is: \n");
    for (in = 0; in < n + k; in++)
    {
        printf("%d ", arr3[in]);
    }
    printf("\n");
    return 0;
}
Program Explanation
1. The program starts with the declaration of two arrays of integers.
2. The first and the second array are initialized with the size of the array.
3. The elements of the first and the second array are then entered by the user.
4. A loop is used to iterate through the array and merge the two arrays.
5. Print the merged array.

Time Complexity: O(n + k)
The time complexity of this algorithm is O(n + k), where n is the size of the first array and k is the size of the second array. This simplifies to O(n) as the loop is executed only once.


Space Complexity: O(n + k)
The space complexity of this algorithm is O(n + k), where n is the size of the first array and k is the size of the second array.

Runtime Test Cases
The runtime output of the C program is shown below, where the size of the first array is “3” and the items are 12, 18, and 23. The second array’s size is “3” and the items are 13, 19, and 27. It then combines both array elements and displays it.

Enter the size of the first array: 3
Enter the elements of the first array: 
12
18
23
Enter the size of the second array: 3
Enter the elements of the second array: 
13
19
27
The merged array is: 
12 13 18 19 23 27

Method 2: Merge Two Sorted Arrays in C using While Loop
In this approach, we will use a while loop to iterate through the array and merge the two arrays.

Example:
First Array = [12, 18, 40, 60]
Second Array = [47, 56, 89, 90]

Merged Array = [12, 18, 40, 47, 56, 60, 89, 90]

Program/Source Code
Here is source code of the C Program to merge two sorted arrays using while loop. The program is successfully compiled and tested using Turbo C compiler in windows environment. The program output is also shown below.

/*
 * C Program to merge two sorted arrays using while loop
 */
 
#include <stdio.h>
void main()
{
    int array1[50], array2[50], array3[100], m, n, i, j, k = 0;
    printf("\n Enter size of array Array 1: ");
    scanf("%d", &m);
 
    printf("\n Enter sorted elements of array 1: \n");
    for (i = 0; i < m; i++) 
    {
        scanf("%d", &array1[i]);
    }
 
    printf("\n Enter size of array 2: ");
    scanf("%d", &n);
 
    printf("\n Enter sorted elements of array 2: \n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &array2[i]);
    }
 
    i = 0;
    j = 0;
 
    while (i < m && j < n) 
    {
        if (array1[i] < array2[j]) 
        {
            array3[k] = array1[i];
            i++;
        }
        else 
        {
            array3[k] = array2[j];
            j++;
        }
        k++;
    }
 
    if (i >= m) 
    {
        while (j < n) 
        {
            array3[k] = array2[j];
            j++;
            k++;
        }
    }
 
    if (j >= n) 
    {
        while (i < m)
        {
            array3[k] = array1[i];
            i++;
            k++;
        }
    }
 
    printf("\n After merging: \n");
    for (i = 0; i < m + n; i++) 
    {
        printf("\n%d", array3[i]);
    }
}
