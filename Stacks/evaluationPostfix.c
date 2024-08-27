#include<stdio.h>
#include "IntegerStack.h"


int perform(int x, char o, int y);

/*


# Start parsing the expression
# If the element is,

  # Operand -> push 
  # operator -> pop two numbers, perform operation and push the result
Eg: 
  y  = pop
  x = pop
  z = x oper y
  push(z)


# At last return the top of the stack



*/

int main(){

  char expression[] = "532*1/+4+";
  //((5+((3*2)/1))+4)

  int x, y, z;

  for(int i=0; expression[i] != '\0'; i++){
    char element = expression[i];

    if(element == '+' || element == '-' || element == '*' || element == '/' ){
      y = pop();
      x = pop();
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