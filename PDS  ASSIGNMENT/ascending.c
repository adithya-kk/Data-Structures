#include<stdio.h>
#include<conio.h>
struct list
{
int data;
struct list *link;
}*start;
void create(int m)
{
struct list *tmp,*q;
tmp=(struct list *)malloc(sizeof(struct list));
tmp->data=m;
tmp->link=NULL;
if(start==NULL)
start=tmp;
else
q=start;
while(q->link!=NULL)
{
q=q->link;
}
q->link=tmp;
}
void disp()
{
struct list *q;
if(start==NULL)
printf(“\n\n LIST IS EMPTY”);
else
{
q=start;
while(q!=NULL)
{
printf(“%d->”,q->data);
q=q->link;
}
}
}
void sort()
{
struct list *q,*p;
int data;
q=start;
while(q!=NULL)
{
p=q->link;
while(p!=NULL)
{
if(q->data>p->data)
{
data=q->data;
q->data=p->data;
p->data=data;
}
p=p->link;
}
q=q->link;
}
}
void main()
{
int ch,m,i,n;
clrscr();
do
{
printf(“\n\n1.create \n\n2.display \n\n3.sort \n\n4.Exit\n\n”);
printf(“\n\nENTER UR CHOICE”);
scanf(“%d”,&ch);
switch(ch)
{
case 1:
printf(“\n\nHOW MANY NODES”);
scanf(“%d”,&n);
for(i=0;i<n;i++)
{
printf(“\n\nENTER THE DATA”);
scanf(“%d”,&m);
create(m);
}
break;
case 2:
disp();
break;
case 3:
sort();
break;
case 4:
exit(0);
}
}
while(ch!=4);
getch();
}