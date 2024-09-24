// Implementation of a Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

// Node Structure declaration
struct node{
  int val;
  struct node* left;
  struct node* right;
};

// Function prototypes
void insert(int val);
void inOrder(struct node* temp);
int search(int val);
struct node* delete(struct node* currNode, int val);
int getRightMin(struct node* currNode);

// Global Declarations
struct node* root = NULL;

// Driver code
int main(){

  insert(8);
  insert(9);
  insert(1);
  insert(18);
  insert(79);
  insert(15);
  printf("\n");
  inOrder(root);

  int isPresent = search(8);

  if(isPresent){
    printf("\nhey, We found the element! :)");
  }else{
     printf("\nSorry, Couldn't find him :(");
  }

  delete(root, 8);
  printf("\n");
  inOrder(root);
  
  return 0;
}


// Insertion of a new node
void insert(int val){
  if(root == NULL){
    root = (struct node*)malloc(sizeof(struct node));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return;
  }

  struct node* parent = root;
  struct node* temp = root;

  while(parent != NULL){
    temp = parent;
    if(val < parent->val){
      parent = parent->left;
    }else if(val > parent->val){
      parent = parent->right;
    }else{
      printf("\nOh, Sorry! Duplicate elements are not allowed!");
      return;
    }
  }

  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;

  if(temp == NULL){
    root = newNode;
    return;
  }

  if(val < temp->val){
    temp->left = newNode;
  } else{
    temp->right = newNode;
  }

}

void inOrder(struct node* temp){
    if(temp == NULL){
      return;
    }
    inOrder(temp->left);
    printf("%d   ", temp->val);
    inOrder(temp->right);
}


int search(int val){
  struct node* temp = root;
  while(temp != NULL && val != temp->val){
    if(val < temp->val){
      temp = temp->left;
    }else if(val > temp->val){
      temp = temp->right;
    }
  }

  if(temp != NULL){
    return 1;
  }

  return 0;
}

struct node* delete(struct node* currNode, int val){
  if(currNode == NULL){
    return NULL;
  }

  if(val < currNode->val){
    currNode->left = delete(currNode->left, val);
  }else if(val > currNode->val){
    currNode->right = delete(currNode->right, val);
  }else{
    // Case 1: Leaf Node
    if(currNode->left == NULL && currNode->right == NULL){
      free(currNode);
      return NULL;
    }
    // Case 2: Node has only right child
    else if(currNode->left == NULL){
      struct node* temp = currNode->right;
      free(currNode);
      return temp;
    }
    // Case 3: Node has only left child
    else if(currNode->right == NULL){
      struct node* temp = currNode->left;
      free(currNode);
      return temp;
    }
    // Case 4: Node has both left and right child
    else{
      int rightMin = getRightMin(currNode->right);
      currNode->val = rightMin;
      currNode->right = delete(currNode->right, rightMin);
    }
  }
  return currNode;
}

int getRightMin(struct node* currNode){
  struct node* temp = currNode;
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp->val;
}