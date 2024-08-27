#include<stdio.h>
#include "buildStack.h"
#include<string.h>

#define SIZE 100


int precedence(char);


/*



# Reverse the infix expression
# While Reversing, change ( as ) and vice versa
# Same as postfix expression but while popping 
  instead of check higher or equal precedence, just pop only higher precedence
# Reverse the postfix expression




*/

  char postfix[SIZE];
  int ind = -1;


int main(){

  char expression1[] = "((5+((3*2)/1))+4)";
  //((5+((3*2)/1))+4)

  int n = strlen(expression1)-1;
  int j = 0;
 
 char expression[n+1];
 for(int i=n; i>=0; i--){
  if(expression1[i] == '('){
     expression[j++] = ')';
  }else if(expression1[i] == ')'){
     expression[j++] = '(';
  }else{
    expression[j++] = expression1[i];
  }
 }



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
            postfix[++ind] = x;
          }
        }
    }else if( element == '+' || element == '-' || element == '*' || element == '/'){

        if(precedence(element) > precedence(peek())){
          push(element);
        }else{
          while(precedence(element) < precedence(peek())){
            postfix[++ind] = pop();
          }
        }

    }else{
      postfix[++ind] = element;
    }

  }

  int start = 0, end = ind;

  while(start<end){
    char c = postfix[start];
    postfix[start] = postfix[end];
    postfix[end] = c;
    start++;
    end--;
  }

  while(!isEmpty()){
    postfix[++ind] = pop();
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


