#include<stdio.h>
#include<conio.h>
int ch,i=0,j,pos;
int a[5];
void insert()
{
 int c;
 do
 {
  if(i==5)
  {
   printf("The array is full.");
  }
  else
  {
   printf("Enter an array element: ");
   scanf("%d",&a[i]);
   i++;
  }
  printf("Enter 1 to continue?");
  scanf("%d",&c);
 }while(c==1);
}

void ask()
{
 printf("Which operation do you want to apply on the array?\n");
 printf("1.Insert\n2.Display\n3.Largest number\n4.Smallest number\n5.Delete\n");
 scanf("%d",&ch);
}

void display()
{
 int j;
 if(i==0)
 {
  printf("The array is empty.");
 }
 else
 {
  printf("\nThe array is: ");
  for(j=0;j<i;j++)
  {
   printf("%d ",a[j]);
  }
 }
}


void max()
{
 int l,max=a[0];
 for(l=1;l<i;l++)
 {
  if(a[l]>max)
  {
   max=a[l];
  }
 }
 printf("The largest number is: %d",max);
}

void min()
{
 int m,min=a[0];
 for(m=1;m<i;m++)
 {
  if(min>a[m])
  {
   min=a[m];
  }
 }
 printf("The smallest number is: %d",min);
}

void del()
{
 if(i==0)
  printf("Nothing To delete.");
 else
 {
  printf("Enter position to delete that element:");
  scanf("%d",&pos);
  printf("%d",a[pos-1]);printf(" Has been deleted");
  for(j=pos-1;j<6;j++)
  {
   a[j]=a[j+1];
  }
  i--;
 }
}

void main()
{
 int cho;
 clrscr();

 do
 {
  ask();
  switch(ch)
  {
   case 1 :	insert();
			break;

   case 2 :	display();
			break;

   case 3 :	max();
			break;

   case 4 :     min();
			break;

   case 5:	del();
			break;

   default:	printf("The value you have entered is incorrect. Please enter again.");
			scanf("%d",&ch);
  }
  printf("\nEnter 5 to perform another operation on array.");
  scanf("%d",&cho);
 }while(cho==5);
 getch();
}
