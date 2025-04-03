#include <stdio.h>
int main() {
int i, j, n, a[50], frame[10], no, k, avail, count = 0;
int time[10];
int least_recent, least_recent_index;
printf("\n\tLRU PAGE REPLACEMENT SCHEME\n");
printf("\nEnter the number of pages: ");
scanf("%d", & n);
printf("Enter the page number: ");
for (i = 1; i <= n; i++) {
scanf("%d", & a[i]);
}
printf("\nEnter the number of frames: ");
scanf("%d", & no);
for (i = 0; i < no; i++) {
frame[i] = -1;
time[i] = 0;
}
printf("\n Ref_String\t Page_Frames\n");
for (i = 1; i <= n; i++) {
printf("%d\t\t", a[i]);
avail = 0;
for (k = 0; k < no; k++) {
if (frame[k] == a[i]) {
avail = 1;
time[k] = i;
break;
}}
if (avail == 0) {
if (i <= no) {
frame[i - 1] = a[i];
time[i - 1] = i;
} else {
least_recent = time[0];
least_recent_index = 0;
for (k = 1; k < no; k++) {
if (time[k] < least_recent) {
least_recent = time[k];
least_recent_index = k;
}}
frame[least_recent_index] = a[i];
time[least_recent_index] = i;
}

count++;
for (k = 0; k < no; k++) {
if (frame[k] != -1) {
printf("%d\t", frame[k]);
} else {
printf("-\t");
}}
} else {
printf("hit");
}
printf("\n");
}
printf("\nPage fault is %d\n", count);
return 0;
}
