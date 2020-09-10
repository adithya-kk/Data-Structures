#include <iostream.h>
#include <conio.h>
void print_ar (int ar[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << ar[i] << "    ";
  }
  cout << endl;
}
void shell_sort (int ar[], int size)
{
  int j;
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
      int temp = ar[i];
      for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
      {
	ar[j] = ar[j - gap];
      }
      ar[j] = temp;
    }
    print_ar(ar,size);
  }
}
int main ()
{
  clrscr();
  int ar[20],n;
  gotoxy(33,2);
  cout<<"SHELL SORT\n";
  cout<<"Enter the number of elements :";
  cin>>n;
  cout<<"\nEnter the elements with spacing: ";
  for(int i = 0; i < n; i++)
   cin>>ar[i];
  cout << "Intial Array : ";
  print_ar (ar,n);
  cout <<"Sorting...."<<endl;
  shell_sort (ar,n);
  cout << "Sorted Array : ";
  print_ar (ar, n);
  getch();
  return 0;
}