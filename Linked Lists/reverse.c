#include<stdio.h>
#include<stdlib.h>

// method declarations
void display();
void create(int);
void insertBeginning(int);
void insertLast(int);
void insert(int, int);
void removeBegin();
void removeLast();
void removeSpecific(int);
void reverse();

// declaring a doubly linked list

struct node{
  int data;
  struct node* prev;
  struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;


int main(){

  int option, data, index;

  printf("\nI'm happy to introduce you to my Linked List");

  while(1){
    printf("\n\n************************************************");
    printf("\nChoose your desired operation");
    printf("\nEnter -1 to terminate the program");
    printf("\n0 - Display the linked list");
    printf("\n1 - Create a new Linkedlist");
    printf("\n2 - insert at the beginning of the linked list");
    printf("\n3 - insert at the end of the linkedlist");
    printf("\n4 - Insert at specific index");
    printf("\n5 - Remove at the beginning");
    printf("\n6 - Remove at last");
    printf("\n7 - Remove at a specific position");


    printf("\nEnter your choice: ");
    scanf("%d", &option);

    if(option == -1){
      printf("\nThank you for using the linkedlist");
      return -1;
    }


    switch(option){
      case 0:
        display();
        break;
      case 1: 
        printf("Enter the data: ");
        scanf("%d", &data);
        create(data);
        break;
      case 2:
        printf("Enter the data: ");
        scanf("%d", &data);
        insertBeginning(data);
        break;
      case 3:
        printf("Enter the data: ");
        scanf("%d", &data);
        insertLast(data);
        break;
      case 4:
        printf("Enter the position: ");
        scanf("%d", &index);
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(index, data);
        break;
      case 5:
        removeBegin();
        break;
      case 6:
        removeLast();
        break;
      case 7:
        printf("Enter the position: ");
        scanf("%d", &index);
        removeSpecific(index);
        break;
      case 8:
      reverse();
      break;






    }


  }



  return 0;
}



void display(){
    struct node* temp;
    temp = head;

    if(head == NULL){
      printf("\nEmpty Linked List");
      return;
    }

    printf("\n\nLinked List: ");
    while(temp!= NULL){
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL");
}



void create(int data){
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  head = newNode;
  tail = newNode;
}

void insertBeginning(int data){
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insertLast(int data){
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}

void insert(int index, int data){
  struct node* newNode;
 
  newNode = (struct node*)malloc(sizeof(struct node));
  struct node* temp;
  temp = head;
  int count = 1;
  while(count < index){
    temp = temp->next;
    count += 1;
  }


  newNode->data = data;
  newNode->next = temp->next;
  temp->next->prev = newNode;
  temp->next = newNode;
  newNode->prev = temp;
  

}

void removeBegin(){
  if(head == NULL){
    printf("Cannot remove from an empty list!");
    return;
  }
  if(head->next == NULL){
    free(head);
    head = NULL;
    return;
  }

  struct node* temp;
  temp = head;
  head = head->next;
  head->prev = NULL;
  free(temp);
}

void removeLast(){
   if(head == NULL){
    printf("Cannot remove from an empty list!");
    return;
  }
  if(head->next == NULL){
    free(head);
    head = NULL;
    return;
  }

  struct node* temp;
  temp = tail;
  tail = tail->prev;
  tail->next = NULL;
  free(temp);
}

void removeSpecific(int index){

   if(head == NULL){
    printf("Cannot remove from an empty list!");
    return;
  }

  // removing first element
  if(index == 0){
    removeBegin();
    return;
  }


  int count = 1;
  struct node* temp;
  struct node* nextNode;
  struct node* finalNode;
  temp = head;
  while(count < index){
     if(temp -> next == NULL){
      printf("There's no such index!");
      return;
    }
    temp = temp->next;
    count += 1;
  }

  // removing last element
  if (temp->next == tail){
   removeLast();
   return;
  }
  finalNode = temp->next->next;
  nextNode = temp->next;
  temp->next = finalNode;
  finalNode->prev = temp;
  nextNode->next = NULL;
  nextNode->prev = NULL;
  free(nextNode);
  

}


void reverse(){
  struct node* start = head;
  struct node* end = tail;

  while(start != end){
     int temp = start->data;
     start->data = end->data;
     end->data = temp;
     start = start->next;
     end = end->prev;
  }

}