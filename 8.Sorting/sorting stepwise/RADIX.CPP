#include <iostream.h>
#include <conio.h>
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
	if (arr[i] > max)
	    max = arr[i];
    return max;
}
void countSort(int arr[], int n, int exp)
{
    int output[20];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
	count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
	count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
	output[count[(arr[i] / exp) % 10] - 1] = arr[i];
	count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
	arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    cout<<"Sorting...."<<endl;
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
      countSort(arr, n, exp);
      for(int i=0;i<n;i++)
       cout<<arr[i]<<"     ";
      cout<<endl;
    }
}
int main()
{
    clrscr();
    int arr[20],n;
    gotoxy(33,2);
    cout<<"RADIX SORT\n";
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the elements with spacing: ";
    for(int j = 0; j < n; j++)
     cin>>arr[j];
    cout<<"\Before sorting\n";
    for(j = 0; j < n; j++)
     cout << arr[j] << "     ";
    cout<<endl;
    radixsort(arr, n);
    cout<<"\nAfter Sorting\n";
    for (int i = 0; i < n; i++)
     cout << arr[i] << "      ";
    getch();
    return 0;
}