#include<stdio.h>
int i,j;
void swap(int* a, int* b)
{
 int t = *a;
 *a = *b;
 *b = t;
}
 int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
	// If current element is smaller than or
	// equal to pivot
	if (arr[j] <= pivot)
	{
	    i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
	printf("%d ", arr[i]);
    printf("\n");
}
void main()
{
 int arr[100],n;
 clrscr();
 printf("\nEnter the number of elements to be sorted\n");
 scanf("%d",&n);
 printf("\nEnter the elements to be sorted:\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 quickSort(arr, 0, n-1);
 printf("Sorted array: \n");
 printArray(arr, n);
 getch();
}