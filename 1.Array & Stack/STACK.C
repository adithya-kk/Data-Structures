#include<stdio.h>
#include<conio.h>
int a[6];
int top=-1,ch,r,x;
void ask()
{
 printf("Which operation do you want to apply on the array?\n");
 printf("1.Push\n2.Pop\n3.Display\n");
 printf("4.Find smallest number\n5.Find largest number\n");
 scanf("%d",&ch);
}

void push()
{
 int c;
 do
 {
  full();
  if(x==1)
  {
   printf("The stack is full.");
  }
  else
  {
   top++;
   printf("Enter an array element.\n");
   scanf("%d",&a[top]);
  }
  printf("Enter 1 to continue.");
  scanf("%d",&c);
 }while(c==1);
}

void pop()
{
 empty();
 if(r==1)
 {
  printf("The stack is empty.");
 }
 else
 {
  int t;
  t=a[top];
  top--;
  printf("%d",t);
  printf(" has been deleted.\n");
 }
}

void disp()
{
 int i;
 if(top==-1)
 {
  printf("The stack is empty.");
 }
 else
 {
  printf("\nThe stack is: ");
  for(i=0;i<=top;i++)
  {
   printf("%d ",a[i]);
  }
 }
}

int empty()
{
 if(top==-1)
 {
  r=1;
 }
 return r;
}

int full()
{
 if(top==5)
 {
  x=1;
 }
 return x;
}

void max()
{
 int l,max=a[0];
 for(l=1;l<=top;l++)
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
 for(m=1;m<=top;m++)
 {
  if(min>a[m])
  {
   min=a[m];
  }
 }
 printf("The smallest number is: %d",min);
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
   case 1: push();
		   break;

   case 2: pop();
		   break;

   case 3: disp();
		   break;

   case 4: min();
		   break;

   case 5: max();
		   break;

   default: printf("The choice you entered is wrong. Please enter again.");
			scanf("%d",&ch);
  }
  printf("\nEnter 9 to perform another operation on the stack.\n");
  scanf("%d",&cho);
 }while(cho==9);
 getch();
}



