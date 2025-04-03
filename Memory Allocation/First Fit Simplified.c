#include<stdio.h>
void main()
{
  int b,p;
  printf("Enter the no. of blocks:");
  scanf("%d",&b);
  printf("Enter the no. of processes:");
  scanf("%d",&p);
  int process[p],blocks[b];
  int visited[p],completed[b];
  for (int i=0;i<p;i++){
  visited[i]=0;
  }
  for (int i=0;i<b;i++){
  completed[i]=0;
  }
  for (int i=0;i<p;i++){
  printf("Enter the size of process p%d: ",i);
  scanf("%d",&process[i]);
  }
  for (int i=0;i<b;i++){
  printf("Enter the size of block %d: ",i);
  scanf("%d",&blocks[i]);
  }
  for (int i=0;i<p;i++){
  for (int j=0;j<b;j++){
  if (completed[j]==0){
  if ((process[i]<=blocks[j]) && (visited[i]==0)){
    printf("Process p%d of size %d allocated to block of size %d\n",i,process[i],blocks[j]);
    visited[i]=1;
    completed[j]=1;
    break;
  }
  }
  }
  if (visited[i]==0){
  printf("Process %d of size %d in waiting list.\n",i,process[i]);
  }
  }
}
