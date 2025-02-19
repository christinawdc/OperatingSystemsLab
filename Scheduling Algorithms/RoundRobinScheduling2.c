#include <stdio.h>
struct RRscheduling
{
int pid,bt,remaining_bt,wt,tat,ct;
};
void main()
{
int n, i, time_slice;
printf("Enter the number of processes: ");
scanf("%d", &n);
struct RRscheduling a[n];
printf("Enter the burst time of each process:\n");
for (i = 0; i < n; i++) {
printf("BT of process %d: ", i + 1);
scanf("%d", &a[i].bt);
a[i].pid = i + 1;
a[i].remaining_bt = a[i].bt;
a[i].ct =0;
}
printf("Enter the time slice: ");
scanf("%d", &time_slice);
int total_time = 0;
int done = 0;
int gantt_chart[100];
int gantt_index = 0;
int gantt_timestamps[100];
while (1) {
done = 1;
for (i = 0; i < n; i++) {
if (a[i].remaining_bt > 0) {
done = 0;
int execution_time = (a[i].remaining_bt > time_slice) ? time_slice : a[i].remaining_bt;
total_time += execution_time;
a[i].remaining_bt -= execution_time;
gantt_chart[gantt_index] = a[i].pid;
gantt_timestamps[gantt_index++] = total_time;
if(a[i].remaining_bt==0)
{
a[i].ct =total_time;
}
}
}

if (done == 1)
break;
}
printf("\nGantt Chart\n");
int current_time = 0;
for (i = 0; i < gantt_index; i++) {
printf(" p%d\t|", gantt_chart[i]);
}
printf("\n0\t");
for (i = 0; i < gantt_index; i++){
printf("%d\t",gantt_timestamps[i]);
}
printf("\n");
printf("\nPID\tBT\tTAT\tWT\n");
int total_tat = 0, total_wt = 0;
for (i = 0; i < n; i++) {
a[i].tat=a[i].ct;
a[i].wt = a[i].tat - a[i].bt;
printf("p%d\t%d\t%d\t%d\n", a[i].pid, a[i].bt, a[i].tat, a[i].wt);
total_tat += a[i].tat;
total_wt += a[i].wt;
}
printf("\nTotal Turnaround Time: %d ms\n", total_tat);
printf("Total Waiting Time: %d ms\n", total_wt);
printf("Average Turnaround Time: %.2f ms\n", (float)total_tat / n);
printf("Average Waiting Time: %.2f ms\n", (float)total_wt / n);
}
