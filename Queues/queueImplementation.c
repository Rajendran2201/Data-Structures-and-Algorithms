
// Basic Implementation has been done, Need to brush up some features!

#include<stdio.h>
#define SIZE 100


// Method Declarations
void push();
int pop();
void display();
int isEmpty();

// Global Declarations
int queue[SIZE];
int start = -1, end = -1;


int main(){

  int choice, num;

  while(1){
      printf("\nChoose your operation!");
      printf("\n0 - quit\n1 - push()\n2 - pop()\n3 - isEmpty()\n4 - display()");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      if(choice == 0){
        break;
      }

      switch(choice){
        case 1:
          push();
          break;
        case 2:
          num = pop();
          if(num != -1){
            printf("%d was popped out!", num);
          }
          break;
        case 4:
          display();
          break;
      }


  }
  return 0;
}

void push(){
  int num;
  if(isEmpty()){
    start++;
  }
  printf("\nEnter an element: ");
  scanf("%d", &num);
  queue[++end] = num;
}

int pop(){
  if(isEmpty()){
    printf("The queue is empty!");
    return -1;
  }
  return queue[start++];
}

void display(){
  for(int i = start; i<=end; i++){
    printf("%d  ->", queue[i]);
  }
  printf("END");
}

int isEmpty(){
  if(start == -1 || end == -1){
    return 1;
  }
  return 0;
}