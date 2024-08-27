
#include <stdio.h>
#define SIZE 100



void insertFront(int x);
void insertRear(int x);
int deleteFront();
int deleteRear();
int isEmpty();
int isFull();
void display();
int viewFront();
int viewRear();

int deque[SIZE];

int front = 0, rear = -1;

int main()
{

  int option, x, removed, element;

  while (1)
  {
    printf("\n\n******************************************************************");
    printf("\nPlease choose your option: ");
    printf("\n1.Add at Front\n2.Add at Last\n3.Remove at Front\n4.Remove at Last\n5.Is the queue empty?\n6.Is the queue full?\n7.Display the queue\n8.View the frontmost element\n9.View the last element\n10.Terminate the program");
    printf("\nEnter your choice: ");
    scanf("%d", &option);

    if (option == 10)
    {
      printf("Thank you for using my queue!");
      return -1;
    }
    switch (option)
    {
    case 1:
      printf("\nEnter the element to be added: ");
      scanf("%d", &x);
      insertFront(x);
      printf("\n%d is inserted at front", x);
      break;
    case 2:
      printf("\nEnter the element to be added: ");
      scanf("%d", &x);
      insertRear(x);
      printf("\n%d is inserted at last", x);

      break;
    case 3:

      removed = deleteFront();
      if (removed != -1)
      {
        printf("\n%d was removed at front", removed);
      }

      break;
    case 4:
      removed = deleteRear();
      if (removed != -1)
      {
        printf("\n%d was removed at last", removed);
      }

      break;
    case 5:
      if (isEmpty())
      {
        printf("\nYesss, The deque is empty");
      }
      else
      {
        printf("\nNo, The deque is not empty");
      }

      break;
    case 6:
      if (isFull())
      {
        printf("\nYesss, The deque is full");
      }
      else
      {
        printf("\nNo, The deque is not full");
      }

      break;

    case 7:
      display();
      break;
    case 8:
      element = viewFront();
      if (element != -1){
        printf("%d is the frontmost element",element);
      }
      
      break;
    case 9:
      element = viewRear();
      if (element != -1){
        printf("%d is the lastmost element",element);
      }
      
      break;
    default:
      printf("\nIvalid input, please try again!");
    }
  }

  return 0;
}


void insertFront(int x){
  if(isFull()){
    printf("Sorry, the deque is full...");
  }else if(front == 0 && rear == -1){
    deque[front] = x;
    rear++;
  }else{
    for(int i=rear; i>=front; i--){
      deque[i+1] = deque[i];
    }
    deque[front] = x;
    rear++;
  }
}

void insertRear(int x){
 if(isFull()){
    printf("Sorry, the deque is full...");
  }else if(front == 0 && rear == -1){
    rear++;
    deque[rear] = x;
  }else{
    rear++;
    deque[rear] = x;
  }
}


void display(){

  if(isEmpty()){
    printf("\nThe deque is empty");
  }else{
    for (int i = front; i<= rear; i++){
      printf("%d  ", deque[i]);
    }
  }
}

int deleteFront(){
  if(isEmpty()){
    printf("The deque is empty, we can't remove element!");
  }
  return deque[front++];
}


int deleteRear(){
if(isEmpty()){
    printf("The deque is empty, we can't remove element!");
  }
  return deque[rear--];
}


int viewFront(){
  if(isEmpty()){
    printf("The deque is empty!");
    return -1;
  }
    return deque[front];
}
int viewRear(){
   if(isEmpty()){
    printf("The deque is empty!");
    return -1;
  }
    return deque[rear];
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

/*


******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 1

Enter the element to be added: 13

13 is inserted at front

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 1

Enter the element to be added: 43

43 is inserted at front

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 8
43 is the frontmost element

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 9
13 is the lastmost element

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 2

Enter the element to be added: 435

435 is inserted at last

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 9
435 is the lastmost element

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 2

Enter the element to be added: 34

34 is inserted at last

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 4

34 was removed at last

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 7
43  13  435  

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 3

43 was removed at front

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 7
13  435  

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 4

435 was removed at last

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 7
13  

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 1

Enter the element to be added: 14

14 is inserted at front

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 8
14 is the frontmost element

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 9
13 is the lastmost element

******************************************************************
Please choose your option: 
1.Add at Front
2.Add at Last
3.Remove at Front
4.Remove at Last
5.Is the queue empty?
6.Is the queue full?
7.Display the queue
8.View the frontmost element
9.View the last element
10.Terminate the program
Enter your choice: 10
Thank you for using my queue!


*/