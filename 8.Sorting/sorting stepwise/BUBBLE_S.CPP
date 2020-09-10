#include<iostream.h>
#include<conio.h>
void bubble_sort(int n,int arr[])
{
 int temp,i,j;
 cout<<"Sorting.....\n";
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(arr[j]>arr[j+1])
   {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
    for(int k=0;k<n;k++)
     cout<<arr[k]<<"     ";
    cout<<endl;
   }
  }
 }
 cout<<"\nEntered list is as follow:\n";
 for(i=0;i<n;i++)
  cout<<arr[i]<<"     ";
}

void main()
{
 clrscr();
 int n,list[20],i;
 gotoxy(33,2);
 cout<<"BUBBLE SORT"<<endl;
 cout<<"Input the number of elements in the list: ";
 cin>>n;
 cout<<"\nInput the elements of the list\n";
 for(i=0;i<n;i++)
  cin>>list[i];
 bubble_sort(n,list);
 getch();
}