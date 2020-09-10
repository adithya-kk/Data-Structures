#include<iostream.h>
#include<conio.h>
#include<process.h>

int i,j,temp,n,ch,pos,swap,a[100];

class sort
{
 public:
	void insert();
	void bubble();
	void selection();
	void insertion();
	void display();
	void ask();
};

void sort::insert()
{
 cout<<"\nEnter The Number Of Elements: ";
 cin>>n;
 cout<<"\nEnter the numbers:\n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<"\nBefore Sorting:\n";
 for(i=0;i<n;i++)
 {
  cout<<a[i]<<"\t";
 }
}

void sort::bubble()
{
 insert();
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
	   if(a[j]>a[j+1])
   {
    swap=a[j];
    a[j]=a[j+1];
    a[j+1]=swap;
   }
  }
 }
 cout<<"\nAfter Bubble Sort\n:";
 display();
}

void sort::selection()
{
 insert();
 for(i=0;i<n-1;i++)
 {
  pos=i;
  for(j=i+1;j<n;j++)
  {
   if(a[pos]>a[j])
   {
    pos=j;
   }
  }
  if(pos!=i)
  {
   swap=a[i];
   a[i]=a[pos];
   a[pos]=swap;
  }
 }
 cout<<"\nAfter Selection Sort:\n";
 display();
}

void sort::insertion()
{
 insert();
 for(i=1;i<n;i++)
 {
  temp=a[i];	//Select Unsorted Element
  j=i-1;
  while((j>=0)&&(a[j]>temp)) //Move elements to the right position and create positon for the unsorted positon
  {
   a[j+1]=a[j];
   j=j-1;
  }
  a[j+1]=temp; //Inserts unsorted element to its proper position
 }
 cout<<"\nAfter Insertion Sort:\n";
 display();
}

void sort::display()
{
 for(i=0;i<n;i++)
 {
  cout<<a[i]<<"\t";
 }
}

void sort::ask()
{
 cout<<"\n1.Bubble Sort || 2.Selection Sort || 3.Insertion Sort || 4.Exit\n";
 cin>>ch;
}

void main()
{
 sort s;
 clrscr();
 cout<<"\t\t\t\tSorting\n\n";
 do
 {
  s.ask();
  switch(ch)
  {
   case 1:	s.bubble();
		break;
   case 2:	s.selection();
		break;
   case 3:	s.insertion();
		break;
   case 4:	exit(0);
		break;
   default:	cout<<"\nEnter a valid choice";
  }
  cout<<"\nEnter 0 to continue:";
  cin>>ch;
 }
 while(ch==0);
 getch();
}
