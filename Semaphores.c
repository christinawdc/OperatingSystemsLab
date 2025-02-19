#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,i=0,empty;
int wait(int s){
   while(s<=0);
   return (--s);
}
int signal(int s){
  return (++s);
}
void produce(){
   empty=wait(empty);
   mutex=wait(mutex);
   full=signal(full);
   i++;
   printf("Producer produces item %d",i);
   mutex=signal(mutex) ;  
}
void consume(){
   full=wait(full);
   mutex=wait(mutex);
   printf("Consumer consumes item %d",i);
   i--;
   mutex=signal(mutex);
   empty=signal(empty);
}
void main(){
  printf("Enter the no.of empty slots in the buffer:");
  scanf("%d",&empty);
  while(1){
	int choice;
	printf("\nEnter your choice:\n1-Producer\t2-Consumer\t3-Exit\n");
	scanf("%d",&choice);
	switch(choice){
  	case 1:
    	if((mutex==1)&&(empty!=0))
       	produce();
    	else
    	printf("Buffer is full.");
    	break;
 	case 2:
    	if((mutex==1)&&(full!=0))
    	consume();
    	else
    	printf("Buffer is empty.");
    	break;
 	case 3:
   	exit(0);
   	break;
   	}
  }
}

