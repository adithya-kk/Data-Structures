#include<iostream.h>
#include<conio.h>
#include<malloc.h>

struct btt
{
 int data;
 struct btt *lp,*rp;
}*root=NULL;

class bintre
{
 public:
 struct btt*crtre()
 {
  struct btt*n=(struct btt*)malloc(sizeof(struct btt));
  cout<<"Enter the data:/n";
  cin>>n->data;
  n->lp=n->rp=NULL;
  return n;
 }
 void insert(struct btt*x,struct btt*y)
 {
  int pos;
  cout<<"Press 1 for left insertion and 2 for right insertion ";
  cin>>pos;
  if(pos==1)
  {
   if(x->lp==NULL)
   {
    x->lp=y;
   }
   else
   {
    insert(x->lp,y);
   }
  }
  else if(pos==2)
  {
   if(x->rp==NULL)
   {
    x->rp=y;
   }
   else
    insert(x->rp,y);
  }
 }
void preorder(struct btt*x)
{
 if(x!=NULL)
 {
  cout<<x->data<<endl;
  preorder(x->lp);
  preorder(x->rp);
 }
}
void inorder(struct btt*x)
{
 if(x!=NULL)
 {
  inorder(x->lp);
  cout<<x->data<<endl;
  inorder(x->rp);
 }
}
void postorder(struct btt*x)
{
 if(x!=NULL)
 {
  postorder(x->lp);
  postorder(x->rp);
  cout<<x->data<<endl;
 }
}
};
void main()
{
 clrscr();
 int ch,ch1;
 struct btt*temp;
 do
 {
  cout<<"Press 1 for left insertion and 2 for right insertion: ";
  cin>>ch;
  bintre a;
  switch(ch)
  {
   case 1:	temp=a.crtre();
			if(root==NULL)
			 root =temp;
			else
		     a.insert(root,temp);
			break;
   case 2:	cout<<"PREORDER : ";
			a.preorder(root);
			cout<<"INORDER : ";
			a.inorder(root);
			cout<<"POSTORDER : ";
			a.postorder(root);
			break;
   }
   cout<<"Enter 0 to continue: ";
   cin>>ch1;
  }
  while(ch1==0);
 getch();
};
