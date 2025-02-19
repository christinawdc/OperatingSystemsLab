//Program to implement the shortest job first (sjf) scheduling algorithm.
#include<stdio.h>
struct process
{ int p,tat,wt,ct,bt;
};
void main()
{
int i,j,n,cct=0,totalTAT=0,totalWT=0;
printf("Enter the no. of processes:");
scanf("%d",&n);
struct process p[n];
for (i=0;i<n;i++)
{
printf("Enter burst time of p%d:",i);
scanf("%d",&p[i].bt);
p[i].p=i;
}
for (i=0;i<n;i++)
{
for (j=0;j<n-1-i;j++)
{
if (p[j].bt>p[j+1].bt)
{
struct process temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
printf("GANTT CHART");
printf("\n--------------------------------\n");
for (i=0;i<n;i++)
{
printf("|P%d\t",p[i].p);
cct+=p[i].bt;
p[i].ct=cct;
p[i].tat=p[i].ct;
p[i].wt=p[i].tat-p[i].bt;
totalTAT+=p[i].tat;
totalWT+=p[i].wt;
}
printf("\nProcess\tBT\tTAT\tWT\n");
for (i = 0; i < n; i++)
{

printf("P%d\t%d\t%d\t%d\n", p[i].p, p[i].bt, p[i].tat, p[i].wt);
}
printf("Total Turnaround Time: %d\n", totalTAT);
printf("Total Waiting Time: %d\n",totalWT);
printf("Average Turnaround Time: %.2f\n", (float)totalTAT / n);
printf("Average Waiting Time: %.2f\n", (float)totalWT / n);
}
