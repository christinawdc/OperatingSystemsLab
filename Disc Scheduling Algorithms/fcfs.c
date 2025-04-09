#include<stdio.h>
void main()
{
  int n,distance=0,totalseektime=0,temp;
  printf("Enter the number of disk requests: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter the head: ");
  scanf("%d",&a[0]);
  printf("Enter the disk requests: ");
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  //disc scheduling
  printf("\nFCFS DISC SCHEDULING:\n");
  for (int i=0;i<n;i++)
  {
    distance= ((a[i]>a[i+1])? (a[i]-a[i+1]) : (a[i+1]-a[i]));
    totalseektime+=distance;
    printf("\nHead movement from %d to %d is %d",a[i],a[i+1],distance);
  }
  printf("\nTotal Seek Time is : %d",totalseektime);
  
}
