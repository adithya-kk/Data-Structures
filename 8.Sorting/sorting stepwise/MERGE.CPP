#include<iostream.h>
#include<conio.h>
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
 int mid;
 if (low < high)
 {
  for(int i=low;i<high;i++)
   cout<<a[i]<<"     ";
  cout<<endl;
  mid=(low+high)/2;
  mergesort(a,low,mid);
  mergesort(a,mid+1,high);
  merge(a,low,high,mid);
 }
 return;
}
void merge(int *a, int low, int high, int mid)
{
 int i, j, k, c[50];
 i = low;
 k = low;
 j = mid + 1;
 while (i <= mid && j <= high)
 {
  if (a[i] < a[j])
  {
   c[k] = a[i];
   k++;
   i++;
  }
  else
  {
   c[k] = a[j];
   k++;
   j++;
  }
 }
 while (i <= mid)
 {
  c[k] = a[i];
  k++;
  i++;
 }
 while (j <= high)
 {
  c[k] = a[j];
  k++;
  j++;
 }
 for (i = low; i < k; i++)
 {
  a[i] = c[i];
 }
}
int main()
{
 clrscr();
 int a[20], i, b[20],n;
 gotoxy(33,2);
 cout<<"MERGE SORT\n";
 cout<<"Enter  the number of elements: ";
 cin>>n;
 cout<<"Enter the elements with sapcing: ";
 for (i = 0; i < n; i++)
  cin>>a[i];
 cout<<"\nElements before sorting:\n ";
 for (i = 0; i < n; i++)
  cout<<a[i]<<"     ";
 cout<<"\nSorting...."<<endl;
 mergesort(a, 0, n);
 cout<<"\nSorted array:\n";
 for (i = 0; i < n; i++)
 {
  cout<<a[i]<<"     ";
 }
 getch();
 return(0);
}