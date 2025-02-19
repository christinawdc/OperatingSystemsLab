//Program to implement the first come first served (fcfs) scheduling algorithm.
#include<stdio.h>
void main() {
int n, count = 0, avgtt = 0, avgwt = 0, t = 0;
printf("Enter the number of processes: ");
scanf("%d", &n);
int a[n], b[n][4];
for (int i = 0; i < n; i++) {
printf("Enter the burst time for P%d: ", i);
scanf("%d", &a[i]);
b[i][0] = i; //process no.
b[i][1] = a[i]; //burst time
}
printf("\nGANTT CHART\n");
for (int i = 0; i < n; i++) {
printf("| P%d ", i);
count++;
}
printf("|\n");
for (int i = 0; i < count; i++) {
printf("----------");
}
printf("\n");
for (int i = 0; i < n; i++) {
printf("%d ", t);
t = t + a[i];
b[i][2] = t; //turnaround time
b[i][3] = b[i][2] - b[i][1]; //waiting time= turnaround-burst time
avgtt += b[i][2];
avgwt += b[i][3];
}
printf("%d\n", t);
printf("\nProcess\tBT\tTAT\tWT\n");
for (int i = 0; i < n; i++) {
printf("P%d\t%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2], b[i][3]);
}
printf("Total Turnaround Time: %d\n", avgtt);
printf("Total Waiting Time: %d\n",avgwt);
printf("Average Turnaround Time: %.2f\n", (float)avgtt / n);
printf("Average Waiting Time: %.2f\n", (float)avgwt / n);
}
