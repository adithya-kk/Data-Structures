#include<iostream.h>
#include<conio.h>
#include<process.h>
class queue
{
 public:
 int arr[10],top,rear;
 queue()
 {
  top=-1;
  rear=-1;
 }
 void enqueue();
 void dequeue();
 void display();
};
void queue::enqueue()
{
 int r;
 do
 {
  if((top == 0 && rear == 9) || (top == rear+1))
  {
   cout<<"\nCircular Queue is Full! Insertion not possible!!!\n";
  }
  else
  {
   if(rear == 9 && top!= 0)
   {
    rear = -1;
    cout<<"Enter the value:";
    cin>>arr[++rear];
   }
   else if(top == -1 && rear==-1)
   { 
    top=rear=0;
    cout<<"Enter the value"<<endl;
    cin>>arr[rear];
   }
   else
   {
    rear++;
    cout<<"Enter the value"<<endl;
    cin>>arr[rear];
   }
  }
  cout<<"enter 1 to continue or 2 to go to main menu\n";
  cin>>r;
 }while(r==1);
}
void queue::dequeue()
{
 if(top == -1 && rear == -1)
 {
  cout<<"\nCircular Queue is Empty! Deletion is not possible!!!\n";
 }
 else
 {
  if(top == 9)
  {
   cout<<arr[top]<<" have been dequeue";
   top = 0;
  }
  else if(top == rear)
  {
   top = rear = -1;
  }
  else
  {
   cout<<arr[top]<<" have been dequeue"<<endl;
   top++;
  }
 }
}
void queue::display()
{
 if(top == -1)
 {
  cout<<"\nCircular Queue is Empty!!!\n";
 }
 else
 {
  int i = top;
  cout<<"\nCircular Queue Elements are : \n";
  if(top<= rear)
  {
   while(i <= rear)
   {          
    cout<<arr[i++]<<"\t";
   }
  }
  else
  {
   while(i <= 9)
   {
    cout<<arr[i++]<<"\t";
   }
   i = 0;
   while(i <= rear)
   {
    cout<<arr[i++]<<"\t";
   }
  }
 }
}
void main()
{
 queue obj;
 int a;
 gotoxy(33,1);
 cout<<"QUEUE"<<endl;
 while(1)
 {
  clrscr();
  cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.End"<<endl;
  cout<<"Enter Your Choice"<<endl;
  cin>>a;
  switch(a)
  {
   case 1:
   obj.enqueue();
   break;
   case 2:
   obj.dequeue();
   break;
   case 3:
   obj.display();
   break;
   case 4:
   cout<<"\3Thank You\3";
   exit(0);
   default:
   cout<<"Wrong choice"<<endl;
  }
  getch();
 }
}