#include<stdio.h>
#include<string.h>
#include "IntegerStack.h"


int perform(int x, char o, int y);

/*


# Start parsing the expression from the right side
# If the element is,
  # Operand -> push 
  # operator -> pop two numbers, perform operation and push the result
Eg: 
  x  = pop
  y = pop
  z = x oper y
  push(z)


# At last return the top of the stack



*/

int main(){

  char expression[] = "++5/*3214";
  //((5+((3*2)/1))+4)

  int x, y, z;
  int n = strlen(expression);
  for(int i=n-1; i>=0; i--){
    char element = expression[i];

    if(element == '+' || element == '-' || element == '*' || element == '/' ){
      x = pop();
      y = pop();
      z = perform(x, element, y);
      push(z);
    }else{
      push(element - '0');
    }
  }

  printf("\nThe answer is %d", pop());




  return 0;
}

int perform(int x, char o, int y){
  switch(o){
    case '+':
      return (x+y);
    case '-':
      return (x-y);
    case '*':
      return (x*y);
    case '/':
      return (x/y);
    default:
      return 0;
  }
  return 0;
}