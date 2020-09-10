#include<iostream.h>
#include<conio.h>

void insertion_sort(int n,int arr[])
{
 int temp,i,j;
 cout<<"Sorting.....\n";
 for(i=1;i<=n-1;i++)
 {
  temp=arr[i];
  j=i-1;
  while(temp<arr[j]&&j>=0)
  {
   arr[j+1]=arr[j];
   j=j-1;
  }
  arr[j+1]=temp;
  for(int k=0;k<n;k++)
   cout<<arr[k]<<"     ";
  cout<<endl;
 }
 cout<<"\nEntered list is as follow:\n";
 for(i=0;i<n;i++)
  cout<<arr[i]<<"     ";
}
void main()
{
 clrscr();
 int n,list[20],i;
 gotoxy(32,2);
 cout<<"INSERTION SORT\n";
 cout<<"Input the number of elements in the list: ";
 cin>>n;
 cout<<"\nInput the elements of the list\n";
 for(i=0;i<n;i++)
  cin>>list[i];
 insertion_sort(n,list);
 getch();
}