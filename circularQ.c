#include <stdio.h>
int front= -1,rear= -1;
int max;
void display(int cqueue[]){
  if(front== -1){
    printf("queue is empty\n");
  }
  else if (front <= rear){
    for(int i = front; i<= rear;i++){
      printf("%d ",cqueue[i]);
    }
  }
  else{
    for (int i = front; i<=max-1;i++){
      printf("%d ",cqueue[i]);
    }
    for(int i = 0;i<=rear;i++){
      printf("%d ",cqueue[i]);
    }
  }
}
int enqueue(int cqueue[],int item){
  if((rear+1)%max==front){
    printf("queue is full\n");
  }
  else{
  if(rear== -1){
    front=rear=0;
    cqueue[rear]=item;
    printf("insert %d into the queue.\n",item);
  }
  else{
    rear=(rear+1)%max;
    cqueue[rear]=item;
    printf("insert %d into the queue.\n",item);
  }
  printf("queue:");
  display(cqueue);
  printf("\n");
 }
}
int dequeue(int cqueue[]){
  if(front == -1){
    printf("queue is empty.\n");
  }
  else{
    printf("dqueue item is %d\n",cqueue[front]);
      if(front==rear){
        front=rear=-1;
      }
      else{
        front=(front+1)%max;
      }
      printf("queue:");
      display(cqueue);
      printf("\n");
    }
  }
int main(){
  int choice,item;
  printf("enter the size of the queue:");
  scanf("%d",&max);
  int cqueue[max];
  while(1){
    printf("\n--- Circular Queue Menu ---\n");
    printf("enter operation:\n 1.Enqueue\n 2.Dequeue\n 3.End:");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("enter item:");
        scanf("%d",&item);
        enqueue(cqueue,item);
        break;
      case 2:
        dequeue(cqueue);
        break;
      case 3:
        printf("exited\n");
        return 0;
      default:
        printf("invalid\n");
      }
    }
    return 0;
  }

