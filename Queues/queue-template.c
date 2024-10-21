#include<stdio.h>
#define SIZE 100

void enqueue(int x);
int dequeue();
int isEmpty();
int isFull();
void display();
int viewFront();


int queue[SIZE];

int front = 0, rear = -1;


void enqueue(int x){
    if(isFull()){
      printf("\nSorry, The queue is full, we can't add more numbers");
    }else{
      rear++;
      queue[rear] = x;
    }
}


int dequeue(){
  if(isEmpty()){
    printf("\nThe queue is empty, we can't remove any element");
    return -1;
  }
  return queue[front++];
}



int isEmpty(){

  if (front > rear){
    return 1;
  }
  return 0;

}
int isFull(){
  if (rear == SIZE -1){
    return 1;
  }
  return 0;
}


void display(){

  if(isEmpty()){
    printf("\nThe queue is empty");
  }else{
    for (int i = front; i<= rear; i++){
      printf("%d  ", queue[i]);
    }
  }
}

int viewFront(){
  if(isEmpty()){
    printf("Oops, the queue is empty!");
    return -1;
    
  }

  return queue[front];
}
