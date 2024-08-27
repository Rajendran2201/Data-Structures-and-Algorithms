#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


// Method Declarations
void push();
int pop();
void display();
int isEmpty();
int peek();


// Global Declarations
int stack[SIZE];
int top = -1;

int main(){


  int choice, element;

while(1){
  printf("\nChoose your desired operation!");
  printf("\n0 - quit\n1 - push()\n2 - pop()\n3 - top()\n4 - isEmpty()\n5 - display()");
  printf("\nEnter your choice: ");
  scanf("%d", &choice);

  if(choice == 0){
    printf("\nThank you!");
    break;
  }

  switch(choice){
    case 1:
      push();
      break;
    case 2:
      element = pop();
      if(element != -1){
        printf("%d was popped out!", element);
      }
      break;
    case 3:
      if(isEmpty()){
        printf("The stack is empty!");
      }else{
        printf("\nThe top element is %d", peek());
      }
      break;
    case 4:
      if(isEmpty()){
        printf("\nThe stack is empty!");
      }else{
        printf("\nThe stack has some elements!");
      }
      break;
    case 5:
      display();
      break;
  }
}
  
  return 0;
}



void push(){
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  stack[++top] = num;
}


int pop(){
  if(isEmpty()){
    printf("The stack is empty!");
    return -1;
  }
  return stack[top--];
}


int isEmpty(){
  if(top == -1){
    return 1;
  }
  return 0;
}

void display(){
  for(int i=top; i>=0; i--){
    printf("\n|  %d  |", stack[i]);
    printf("\n ------");
  }
}

int peek(){
  if(isEmpty()){
    return -1;
  }
  return stack[top];
}