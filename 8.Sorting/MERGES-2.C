#include<stdio.h>
#include<conio.h>

void mergesort(int a[],int i,int j);
void merge(int a[],int list1,int j1,int list2,int j2);

int main()
{
    int a[30],n,i;
    clrscr();

    printf("Enter no of elements:");
    scanf("%d",&n);

    printf("Enter array elements:");

    for(i=0;i<n;i++)
	scanf("%d",&a[i]);

    mergesort(a,0,n);

    printf("\nSorted array is :");
    for(i=0;i<n;i++)
	printf("%d ",a[i]);

    getch();
    return 0;
}

void mergesort(int a[],int i,int j)
{
    int mid;

    if(i<j)
    {
	mid=(i+j)/2;
	mergesort(a,i,mid);        //left recursion
	mergesort(a,mid+1,j);    //right recursion
	merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}

void merge(int a[],int list1,int j1,int list2,int j2)
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=list1;    //beginning of the first list
    j=list2;    //beginning of the second list
    k=0;

    while(i<=j1 && j<=j2)    //while elements in both lists
    {
	if(a[i]<a[j])
	    temp[k++]=a[i++];
	else
	    temp[k++]=a[j++];
    }

    while(i<=list1)    //copy remaining elements of the first list
	temp[k++]=a[i++];

    while(j<=list2)    //copy remaining elements of the second list
	temp[k++]=a[j++];

    //Transfer elements from temp[] back to a[]

    for(i=list1,j=0;i<=j2;i++,j++)
	a[i]=temp[j];


}