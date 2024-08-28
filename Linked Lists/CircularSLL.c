// CIRCULAR SINGLY LINKED LIST


#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;


void create();
void add();
void display();
void removeNode();


int main(){

  int option;

  while(1){
    printf("\nChoose your preference!");
    printf("\n0 - Create\n1 - Add an Element\n2 - Remove a node\n4 - Display");
    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch(option){
      case 0:
        create();
        break;
      case 1:
        add();
      break;
      case 2:
        removeNode();
        break;
      case 3:
      case 4:
        display();
        break;
    }
  }
  
  




  return 0;
}

void create(){
  struct node* newNode;
  int data;
  newNode = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data: ");
  scanf("%d", &data);
  newNode->data = data;
  newNode->next = NULL;
  head = newNode;
  tail = newNode;
}

void add(){
  // creating a new node
  struct node* newNode;
  int data;
  newNode = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data: ");
  scanf("%d", &data);
  newNode->data = data;
  newNode->next = head;

  // linking the new node to the list
  tail->next = newNode;
  tail = newNode;

}

void display(){
  struct node* temp = head;

  while(temp->next != head){
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("%d -> ", temp->data);
  printf("NULL");
}

void removeNode(){
  int ind;
  printf("Enter the node to be removed: ");
  scanf("%d", &ind);
  int count = 0;

  struct node* temp = head;

  while(count < ind-1){
    if(temp->next == head){
      printf("Out of bound, Sorry!");
      return;
    }
    temp = temp->next;
    count++;
  }
  struct node* removed = temp->next;
  temp->next = removed->next;
  free(removed);

}