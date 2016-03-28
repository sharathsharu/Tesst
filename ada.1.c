#include<stdio.h>
#include<time.h>
int partition(int a[],int low,int high)
{
 int i,j,temp;
 i=low;
 j=high+1;
 while(i<j)
 {
  do
  {++i;}while(a[i]<a[low]);
  do
  {--j;}while(a[j]>a[low]);
  if(i<j)
  {temp=a[i]; a[i]=a[j]; a[j]=temp;}
 }
 temp=a[j];
 a[j]=a[low];
 a[low]=temp;
 return j;
}
void quicksort(int a[],int low,int high)
{
 int s;
 if(low<high)
 {
  s=partition(a,low,high);
  quicksort(a,low,s-1);
  quicksort(a,s+1,high);
 }
}

int main()
{
 int a[2500000],i,n;
 float start;
 float end;
 printf("Enter the no of elements:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  a[i]=rand();
 start=clock();
 quicksort(a,0,n-1);
 end=clock();
 printf("Time complexity:%f",(end-start)/CLOCKS_PER_SEC);
 return 0;}

Output:
