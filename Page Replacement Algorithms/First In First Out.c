#include <stdio.h>
int main() {
int n, frames, faults = 0, pos = 0;
printf("FIFO PAGE REPLACEMENT SCHEME\n");
printf("Enter the number of pages: ");
scanf("%d", &n);
int pages[n];
printf("Enter the page numbers: ");
for (int i = 0; i < n; i++) {
scanf("%d", &pages[i]);
}
printf("Enter the number of frames: ");
scanf("%d", &frames);
int frame[frames];
for (int i = 0; i < frames; i++) {
frame[i] = -1;
}
printf("\nRef_String\tPage_Frames\n");
for (int i = 0; i < n; i++) {
int page = pages[i];
printf("%d\t\t", page);
int hit = 0;
for (int j = 0; j < frames; j++) {
if (frame[j] == page) {
hit = 1;
break;
}
}
if (hit) {
printf("hit\n");
} else {
faults++;
if (frame[pos] == -1) {
frame[pos] = page;
} else {
frame[pos] = page;
}
pos = (pos + 1) % frames;
for (int k = 0; k < frames; k++) {
if (frame[k] == -1)
printf("-\t");

else
printf("%d\t", frame[k]);
}
printf("\n");
}
}
printf("\nTotal Page Faults: %d\n", faults);
return 0;
}
