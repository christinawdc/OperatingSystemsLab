#include<stdio.h>
struct priorityscheduling
{
  int pid,bt,priority,wt,ct,tat,;
};
void main()
{
  int i,j,n,temp,totaltat,totalwt,count,t=0;
  printf("Enter the no. of processes:");
  scanf("%d",&n);
  struct priorityscheduling a[n];
  printf("Enter the process details (lower numbers imply higher priority):\n");
  for (i=0;i<n;i++)
  {
	printf("Enter the process id:");
	scanf("%d",&a[i].pid);
	printf("Enter the burst time:");
	scanf("%d",&a[i].bt);
	printf("Enter the priority:");
	scanf("%d",&a[i].priority);
  }
  //Sorting the processes by bt
  for (i=0;i<n;i++)
  {
	for (j=0;j<n-i-1;j++)
	{
  	if (a[j].priority>a[j+1].priority) //(lower numbers imply higher priority)
  	{
    	temp=a[j].priority;
    	a[j].priority=a[j+1].priority;
    	a[j+1].priority=temp;
   	 
    	temp=a[j].bt;
    	a[j].bt=a[j+1].bt;
    	a[j+1].bt=temp;
   	 
    	temp=a[j].pid;
    	a[j].pid=a[j+1].pid;
    	a[j+1].pid=temp;
  	}
	}
  }
 
  printf("\nGANTT CHART\n");
	for (int i = 0; i < n; i++) {
    	printf("|   P%d   ", i);
    	count++;
	}
	printf("|\n");
	for (int i = 0; i < count; i++) {
    	printf("----------");
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
    	printf("%d    	", t);
    	if (i==0) { t = t + a[0].bt; }
    	else {t = t + a[i].bt; }
    	a[i].tat = t;  //turnaround time
    	a[i].wt = a[i].tat - a[i].bt;  //waiting time= turnaround-burst time
    	totaltat += a[i].tat;
    	totalwt += a[i].wt;
	}
	printf("%d\n", t);  
    
 
  //Print
  printf("\nProcess  Prio\tBT\tTAT\tWT\n");
	for (i = 0; i < n; i++) {
    	printf("P%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].priority, a[i].bt, a[i].tat, a[i].wt);
	}

	printf("Total Turnaround Time: %d\n", totaltat);
	printf("Total Waiting Time: %d\n", totalwt);
	printf("Average Turnaround Time: %.2f\n", (float)totaltat / n);
	printf("Average Waiting Time: %.2f\n", (float)totalwt / n);
}
