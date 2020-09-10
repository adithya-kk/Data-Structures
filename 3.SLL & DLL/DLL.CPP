#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
struct node*q,*temp,*s,*t;
int pos,ch;
struct node
{
 int data;
 struct node *lp,*rp;
};

void display()
{
 printf("The Linked List is:\n");
 t=s;
 while(t!=NULL)
 {
  printf("%d",t->data);
  t=t->rp;
  printf("\n");
 }
}
struct node *getnode()
{
 struct node*temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter Data for this node");
 scanf("%d",&temp->data);
 temp->rp=temp->lp=NULL;
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
  printf("Enter the position where you want to insert\n");
  scanf("%d",&pos);
  if(pos==1)
  {
   temp->rp=s;
   s->lp=temp;
   s=temp;
  }
  else
  {
   int i;
   for(q=s,i=1;i<pos&&q!=NULL;q=q->rp,i++)
   {
    if(i==pos-1)
    {
     temp->lp=q;
     temp->rp=q->rp;
     (q->rp)->lp=temp;
     q->rp=temp;
    }
   }
  }
 }
 display();
}
struct node*del()
{
 if(s==NULL)
 {
  printf("Nothing to delete\n");
 }
 else
 {
  printf("Enter the position to delete that node:\n");
  scanf("%d",&pos);
  if(pos==1)
  {
   temp=s;
   (s->rp)->lp=NULL;
   s=s->rp;
   free(temp);
  }
  else
  {
   int j;
   for(q=s,j=1;j<pos&&q!=NULL;q=q->rp,j++)
   {
    if(q->rp==NULL)
    {
     (q->lp)->rp=NULL;
     q->lp=NULL;
     free(q);
    }
    else if(j==pos-1)
    {
     temp=q->rp;
     (temp->rp)->lp=q;
     q->rp=temp->rp;
     temp->lp=temp->rp=NULL;
     free(temp);
    }
   }
  }
 }
 display();
 return 0;
}
void main()
{
 int cho;
 clrscr();
 do
 {
  printf("1.Insert 2.Delete 3.Display 4.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:	insert();
		break;
   case 2:	del();
		break;
   case 3:	display();
		break;
   case 4:	exit(0);
   default:	printf("Invalid Choice,Enter Again");
		scanf("%d",&ch);
  }
  printf("\Enter 0 to perform another operation");
  scanf("%d",&cho);
 }
 while(cho==0);
 getch();
}

