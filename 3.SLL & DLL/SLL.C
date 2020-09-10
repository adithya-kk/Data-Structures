#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node *q,*temp,*s;
int pos,ch;
struct node
{
 int data;
 struct node *lp;
};

void display()
{
 printf("The linked list is:\n");
 temp=s ;
 while(temp!=NULL)
 {
  printf("%d", temp->data);
  temp=temp->lp;
  printf("\n");
 }
}

struct node *getnode()
{
 temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter Data for this node");
 scanf("%d",&temp->data);
 temp->lp=NULL;
 return temp;
}

void insert()
{
 temp=getnode();
 if(s==NULL)
 {
  s=temp;
 }
 else
 {
  printf("Enter the position where you want to insert the new node: ");
  scanf("%d",&pos);
  if(pos==1)
  {
   temp->lp=s;
   s=temp;
  }
  else
  {
   int i;
   for(q=s,i=1;(i<pos)&&(q!=NULL);q=q->lp,i++)
   {
	if(i==(pos-1))
	{
	 temp->lp=q->lp;
	 q->lp=temp;
	}
   }
  }
 }
 display();
}

struct node *del()
{
 if(s==NULL)
 {
  printf("Nothing to delete in the list.\n");
 }
 else
 {
  printf("Enter the position of the node which you want to delete: ");
  scanf("%d",&pos);
  if(pos==1)
  {
   temp=s;
   s=s->lp;
   temp->lp=NULL;
   free(temp);
  }
  else
  {
   int j;
   for(q=s,j=1;(j<pos)&&(q!=NULL);q=q->lp,j++)
   {
	if(j==(pos-1))
	{
	 temp=q->lp;
	 q->lp=temp->lp;
	 temp->lp=NULL;
	 free(temp);
	}
   }
  }
 }
 display();
 return 0;
}



void ask()
{
 printf("Which operation do you want to apply on the linked list?\n");
 printf("1.Insert node\n2.Delete node\n3.Display List\n4.Exit\n");
 scanf("%d",&ch);
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

   case 2 :	del();
			break;

   case 3 : display();
			break;

   case 4 : exit(0);

   default:	printf("The value you have entered is incorrect. Please enter again.");
			scanf("%d",&ch);
  }
  printf("\nEnter 5 to perform another operation on linked list.");
  scanf("%d",&cho);
 }while(cho==5);
 getch();
}
