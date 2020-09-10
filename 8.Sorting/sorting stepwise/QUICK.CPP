#include<iostream.h>
#include<conio.h>
int part(int low,int high,int *a)
{
 int i,h=high,l=low,p,t;
 p=a[low];
 while(low<high)
 {
  while(a[l]<p)
  {
   l++;
  }
  while(a[h]>p)
  {
   h--;
  }
  if(l<h)
  {
   t=a[l];
   a[l]=a[h];
   a[h]=t;
  }
  else
  {
   t=p;
   p=a[l];
   a[l]=t;
   break;
  }
 }
 return h;
}

void quick(int l,int h,int *a)
{
 int index,i;
 if(l<h)
 {
  index=part(l,h,a);
  for(int j=l;j<=h;j++)
   cout<<a[j]<<"     ";
  cout<<endl;
  quick(l,index-1,a);
  quick(index+1,h,a);
 }
}

int main()
{
 clrscr();
 int a[100],n,l,h,i;
 gotoxy(33,2);
 cout<<"QUICK SORT\n";
 cout<<"Enter number of elements:";
 cin>>n;
 cout<<"Enter the elements (Use Space As A Separator):";
 for(i=0;i<n;i++)
  cin>>a[i];
 cout<<"\nInitial Array:\n";
 for(i=0;i<n;i++)
 {
  cout<<a[i]<<"\t";
 }
 h=n-1;
 l=0;
 cout<<"\nSorting...."<<endl;
 quick(l,h,a);
 cout<<"\nAfter Sorting:\n";
 for(i=0;i<n;i++)
 {
  cout<<a[i]<<"\t";
 }
 getch();
 return 0;
}