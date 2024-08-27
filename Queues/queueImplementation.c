#include<stdio.h>
#define SIZE 100

void enqueue(int x);
int dequeue();
int isEmpty();x 
int isFull();
void display();
int viewFront();


int queue[SIZE];

int front = 0, rear = -1;

int main(){

  int option, x, removed, frontElement;

  while(1){
    printf("\n\n******************************************************************");
    printf("\nPlease choose your option: ");
    printf("\n1.Add an element\n2.Remove an element\n3.Is the queue empty?\n4.Is the queue full?\n5.Display the queue\n6.View the frontmost element\n7.Terminate the program");
    printf("\nEnter your choice: ");
    scanf("%d", &option);

    if(option == 7){
      printf("Thank you for using my queue!");
      return -1;
    }
    switch(option){
      case 1: 
        printf("\nEnter the element to be added: ");
        scanf("%d", &x);
        enqueue(x);
        printf("\n%d is inserted", x);
        break;
      case 2: 
          removed = dequeue();
          if(removed != -1){
            printf("\n%d was removed", removed);
          }
          
        break;
      case 3: 
        if(isEmpty()){
          printf("\nYesss, The queue is empty");
        }else{
          printf("\nNo, The queue is not empty");
        }
        break;
      case 4: 
        if(isFull()){
          printf("\nYesss, The queue is full");
        }else{
          printf("\nNo, The queue is not full");
        }
        break;
      case 5: 
        display();
        break;
      case 6:
        frontElement = viewFront();
        if(frontElement != -1){
          printf("\n%d is the first element",frontElement);
        }
        break;
      default:
        printf("\nIvalid input, please try again!");
    }
  }


}


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


/*

OUTPUT: 


*******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 1

Enter the element to be added: 13

13 is inserted
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 1

Enter the element to be added: 15

15 is inserted
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 1

Enter the element to be added: 78

78 is inserted
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 5
13  15  78  
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 2

13 was removed
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 2

15 was removed
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 5
78  
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 1

Enter the element to be added: 98

98 is inserted
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 5
78  98  
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 6

78 is the first element
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 3

No, The queue is not empty
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 4

No, The queue is not full
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 2

78 was removed
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 2

98 was removed
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 2

The queue is empty, we can't remove any element

******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 4

No, The queue is not full
******************************************************************
Please choose your option: 
1.Add an element
2.Remove an element
3.Is the queue empty?
4.Is the queue full?
5.Display the queue
6.View the frontmost element
7.Terminate the program
Enter your choice: 7
*/
