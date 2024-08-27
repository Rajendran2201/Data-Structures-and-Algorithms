#include<stdio.h>
#include "buildStack.h"


#define SIZE 100


int precedence(char);

/*

# Start parsing the expression
# If the symbol is an operand, append it to the postfix expression
# If the symbol is '(' push it to the stack
# if the symbol is ')' pop the contents from stack till 
  matching left paranthesis and append all the popped contents
# if the symbol is an operator,
  1. If the operator has higher precendance than top, push it
  2. If the operator has lower precedence than top, 
     pop elements until the elements are higher or equal precendence of the stack

*/


  char postfix[SIZE];
  int ind = 0;


int main(){

  char expression[] = "((5+((3*2)/1))+4)";


  for(int i=0; expression[i] != '\0'; i++){
    char element = expression[i];

    if(element == '('){
      push(element);
    }else if(element == ')'){
        while(1){
          char x = pop();
          if(x == '('){
            break;
          }else{
            postfix[ind++] = x;
          }
        }
    }else if( element == '+' || element == '-' || element == '*' || element == '/'){
      /*
      1. If the operator has higher precendance than top, push it
      2. If the operator has lower precedence than top, 
     pop elements until the elements are higher or equal precendence of the stack*/

        if(precedence(element) > precedence(peek())){
          push(element);
        }else{
          while(precedence(element) <= precedence(peek())){
            postfix[ind++] = pop();
          }
        }

    }else{
      postfix[ind++] = element;
    }

  }

 for(int i=0; i<=ind; i++){
      printf("%c  ", postfix[i]);
    }

  return 0;
}

int precedence(char c){
  switch(c){
    case '+':
    case '-':
      return 0;
    case '*':
    case '/':
      return 1;
  }
  return -1;
}