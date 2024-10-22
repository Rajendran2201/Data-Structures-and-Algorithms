#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


// Method Declarations
void push(char);
char pop();
void display();
int isEmpty();
char peek();


// Global Declarations
char stack[SIZE];
int top = -1;




void push(char num){
  stack[++top] = num;
}


char pop(){
  if(isEmpty()){
    printf("The stack is empty!");
    return '_';
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

char peek(){
  if(isEmpty()){
    return -1;
  }
  return stack[top];
}