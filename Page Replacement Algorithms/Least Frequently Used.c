#include <stdio.h>
int main() {
int i, j, n, a[50], frame[10], no, k, avail, count = 0;
int frequency[10];
printf("\n\tLFU PAGE REPLACEMENT SCHEME\n");
printf("\nEnter the number of pages: ");
scanf("%d", &n);
printf("Enter the page number: ");
for (i = 1; i <= n; i++) {
scanf("%d", &a[i]);
}
printf("\nEnter the number of frames: ");
scanf("%d", &no);
for (i = 0; i < no; i++)
{
frame[i] = -1;
frequency[i] = 0;
}
printf("\n Ref_String\t Page_Frames\n");
for (i = 1; i <= n; i++)
{
printf("%d\t\t", a[i]);
avail = 0;
for (k = 0; k < no; k++)
{
if (frame[k] == a[i])
{
avail = 1;
frequency[k]++;
break;
}}
if (avail == 0)
{
int min_frequency = frequency[0];
int min_index = 0;
for (k = 1; k < no; k++) {
if (frequency[k] < min_frequency) {
min_frequency = frequency[k];
min_index = k;
}}
frame[min_index] = a[i];
frequency[min_index] = 1;
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
