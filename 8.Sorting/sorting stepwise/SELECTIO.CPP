#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int arr[20],n,i,min,temp,loc,j;
 gotoxy(33,2);
 cout<<"SELECTION SORT\n";
 cout<<"Input the number of elements in the list: ";
 cin>>n;
 cout<<"\nInput the elements of the list\n";
 for(i=0;i<n;i++)
  cin>>arr[i];
 cout<<"Sorting...."<<endl;
 for(i=0;i<n-2;i++)
 {
  min=arr[i];
  loc=i;
  for(j=i+1;j<n;j++)
  {
   if(min>arr[j])
   {
    min=arr[j];
    loc=j;
    for(int l=0;l<n;l++)
     cout<<arr[l]<<"     ";
    cout<<endl;
   }
  }
  temp=arr[i];
  arr[i]=arr[loc];
  arr[loc]=temp;
 }
cout<<"Entered list is as follow:\n";
for(i=0;i<n;i++)
 cout<<arr[i]<<"     ";
getch();
}

