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
 int isempty();
 int isfull();
};
int queue::isempty()
{
 if(top==-1 && rear==-1)
 return 1;
}
int queue::isfull()
{
 if(rear==10)
 return 2;
}
void queue::enqueue()
{
 int r;
 do
 {
 int d;
 d=isfull();
 if(d==2)
 {
  cout<<"Queue is overflow"<<endl;
 }
 else if(top==-1 && rear==-1)
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
 cout<<"Enter 1 to continue or 2 to  go to menu\n";
 cin>>r;
 }while(r==1);
}
void queue::dequeue()
{
 int f;
 f=isempty();
 if(f==1)
 cout<<"Nothing to dequeue";
 else if(rear==top)
 {
  cout<<arr[top]<<" have been dequeued"<<endl;
  top=-1;
  rear=-1;
 }
 else
 {
  cout<<arr[top]<<" have been dequeued"<<endl;
  top++;
 }
}
void queue::display()
{
 if(rear>=top&&rear!=top!=-1)
 {
  cout<<"Your queue is"<<endl;
  for(int i=top;i<=rear;i++)
  cout<<arr[i]<<endl;
 }
 else
 cout<<"Nothing to Display"<<endl;
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