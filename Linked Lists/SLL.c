#include<stdio.h>
#include<stdlib.h>


// Defining the structure for the linked list

struct node{
  int data;
  struct node* next;
};

// method declarations
void display();
void create(int);
void InsertAtFront(int);
void InsertAtRear(int);
void Insert(int, int);
void deleteFirst();
void deleteLast();
void delete(int);


// variable / structure declarations

struct node* head = NULL;
struct node* tail = NULL;

int main(){

  int option, data, index;

  printf("\nI'm happy to introduce you to my Linked List");

  while(1){
    printf("\n\n************************************************");
    printf("\nChoose your desired operation");
    printf("\nEnter -1 to terminate the program");
    printf("\n0 - display the linkedlist");
    printf("\n1 - Create a new Linkedlist");
    printf("\n2 - Insert at front");
    printf("\n3 - Insert at rear end");
    printf("\n4 - Insert at specified position");
    printf("\n5 - Delete at first");
    printf("\n6 - Delete at last");
    printf("\n7 - Delete at specified position");
    printf("\nEnter your choice: ");
    scanf("%d", &option);

    if(option == -1){
      return -1;
    }


    switch(option){
      case 0:
        display();
        break;
      case 1: 
        printf("\nEnter the data: ");
        scanf("%d",&data);
        create(data);
        break;
      case 2:
        printf("\nEnter the data: ");
        scanf("%d",&data);
        InsertAtFront(data);
        break;

      case 3: 
        printf("\nEnter the data: ");
        scanf("%d",&data);
        InsertAtRear(data);
        break;
      case 4: 
        printf("\nEnter the position: ");
        scanf("%d", &index);
        printf("\nEnter the data: ");
        scanf("%d",&data);
        Insert(index, data);
        break;
      case 5:
        deleteFirst();
        break;
      case 6:
        deleteLast();
        break;
      case 7:
        printf("\nEnter the position: ");
        scanf("%d", &index);
        delete(index);
        break;
      default:
        printf("Invalid choice!");
    }
  }
  return 0;
}

/*

  #Displaying the linkedlist

EDGE CASE: if head is NULL, print that the linkedlist is empty

1. create a temporary pointer to traverse the linkedlist
2. assign the temporary pointer to the ehad of the linkedlist
3. traverse the pointer until it points to NUll (until it traverses to the end)
4. as the pointer moves ahead, prints each node's respective data

*/

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

/* 

  #creating a new linkedlist 

1. create a new node to store the values
2. add data to the new node
3. point the newnode to null
4. assign the newnode as the head of the linked (as this is the first element in the linkedlist)

*/
void create(int data){

  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  head = newNode;
  tail = head;
  

}


/*

  #Insert at the beginning of the LinkedList

EDGE CASE: if the list is empty, call create(data)

1. create a new node
2. Assign its data value
3. point newly created node to the head 
4. assign the newly created node as the head (as it will the firstmost element in the LL fn)

*/


void InsertAtFront(int data){

  if(head == NULL){
    create(data);
    return;
  }

  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;

}



/*

  #Insert at the rear end of the linkedlist

EDGE CASE: if the list is empty, call create(data)


1. create a new node
2. Insert the data into the new node and point it to NULL (as it is the last element in the linkedlist)
3. Since I have a pointer named "tail" pointing to the last element in the linkedlist, 
   now link the newly create dnode to the last node of the linkedlist (which tail is pointing to!)
4. Now, the newly created node has become the last element, therefore assign the new node as tail!


*/

void InsertAtRear(int data){
  if (head == NULL){
    create(data);
    return;
  }
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

/*

  #Insert at a specified index of the linkedlist

1. Create a new node and store its respective value in it
2. Create a temporary pointer and point it to the node after which a new node has to added
3. Now, point the temp's next as newNode's next (as new node is to inserted between temp and temp's next)
4. then assign newnode as temp's next (as newnode is placed affter temp and before temp's next)

*/



void  Insert(int index, int data){
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  struct node* temp;
  temp = head;
  int count = 1;
  while(count<index){
     if(temp -> next == NULL){
      printf("There's no such index!");
      return;
    }
    temp = temp->next;
    count += 1;
  }
  newNode->data = data;
  newNode->next = temp->next;
  temp->next = newNode;


}


/*
  #Delete the beginning most element of the linkedlist 

1. create a temporary pointer and point it ot head
2. assign head to head's next (As the previous head is going ot be removed)
3. free the memory allocated to the first element of the linkedlist (temp)

*/

void deleteFirst(){
  if(head == NULL){
    printf("Empty Linked List");
    return;
  }
  struct node* temp;
  temp = head;
  head = head->next;
  free(temp);
}


/*

Hope's the code is self-explanatory!

*/

void deleteLast(){
  struct node* temp;
  temp = tail;
  tail = head;

  // if we try to delete from an empty list
  if(head == NULL){
    printf("Empty Linked List");
    return;
  }

  // delete if there's only a single element
 if(head->next == NULL){
    free(head);
    head = NULL;
    return;
 }
 
 // delete from a long linked list
  while(tail->next->next != NULL){
    tail = tail->next;
  }
  tail->next = NULL;
  free(temp);
}


/*

  #Delete from a specific index

1. Create a two new nodes for better understanding
2. traverse the linkedlist and point temp to the node previous to the node which is to be removed
3. now assign nextNode as temp's next's next (i.e the node the is to be next to the temp asfter deleted the node at the specified index)
4. Now, delete temp's next 
5. then assign temp's next as the nextNode


*/

void delete(int index){
  struct node* temp;
  struct node* nextNode;
  temp = head;
  int count = 1;
  while(count < index){
    if(temp -> next == NULL){
      printf("There's no such index!");
      return;
    }
    temp = temp->next;
    count += 1;
  }
  nextNode = temp->next->next;
  free(temp->next);
  temp->next = nextNode;
}