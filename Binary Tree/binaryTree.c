#include <stdio.h>
#include <stdlib.h>

// node structure
struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
};

// setting the root node
struct tree* root;

// function prototype
void getElement();
void inOrder(struct tree* root);
void preOrder(struct tree* root);
void postOrder(struct tree* root);
void addLeft(struct tree*);
void addRight(struct tree*);
void add();

// main method
int main()
{
  int option;

  while(option != -1){
      printf("\nChoose your desired option!");
      printf("\n1 - Insert into the tree");
      printf("\n2 - Inorder Traversal");
      printf("\n3 - Preorder Traversal");
      printf("\n4 - Postorder Traversal");
      printf("\nEnter your option: ");
      scanf("%d", &option);

      switch (option)
      {
      case 1:
        getElement();
        break;
      case 2: 
        inOrder(root);
        break;
      case 3: 
        preOrder(root);
        break;
      case 4: 
        postOrder(root);
        break;

      default:
        break;
      }
    }

  }
 
 // getting elements as input (basically creating a tree)
void getElement()
{
  // create the root node and set its children as NULL
  struct tree* node;
  node = (struct tree*)malloc(sizeof(struct tree));
  printf("\nEnter the value of root node: ");
  scanf("%d", &node->data);
  node->left = NULL;
  node->right = NULL;
  root = node;

  // get other elements
    // get the directions 
    // check if there is a node
      // if so, put that element 
    // If not, create a new node
    add();
    
}

// adding the elements for the tree
void add(){
  struct tree* temp = root;
  int direction;
  int option;
  
  while(1){
    
      printf("\ncurrent node value: %d", temp->data);
      printf("\nWhere do you want to go?");
      printf("\n1 - Left and 2 - Right");
      printf("\nEnter your choice (-1 to stop): ");
      scanf("%d", &direction);
      if(direction == -1){
        return;
      }
      
      if( direction == 1){
            if(temp->left != NULL){
              temp = temp->left;
            }else{
              addLeft(temp);
              temp = root;
            }
      }else if (direction == 2){
          if(temp->right != NULL){
              temp = temp->right;
            }else{
              addRight(temp);
              temp = root;
            }
      }
  }
 
}

// adding a new node to the left of current node
void addLeft(struct tree* temp){

      struct tree* newNode;
      newNode = (struct tree*)malloc(sizeof(struct tree));
      printf("\nEnter your data: ");
      scanf("%d", &newNode->data);
      temp->left = newNode;
      newNode->left = NULL;
      newNode->right = NULL;
      printf("\nElement was added successfully!");
 
}

// adding a new node to the right of current node
void addRight(struct tree* temp){

      struct tree* newNode;
      newNode = (struct tree*)malloc(sizeof(struct tree));
      printf("\nEnter your data:  ");
      scanf("%d", &newNode->data);
      temp->right = newNode;
      newNode->left = NULL;
      newNode->right = NULL;
      printf("\nElement was added successfully!");
    
}

// inorder tree traversal
void inOrder(struct tree* root){
  if(root == 0){
    return;
  }
  inOrder(root->left);
  printf("%d \t", root->data);
  inOrder(root->right);
}

// preorder tree traversal
void preOrder(struct tree* root){
  if(root == 0){
    return;
  }
  printf("%d \t", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

// postorder tree traversal
void postOrder(struct tree* root){
  if(root == 0){
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  printf("%d \t", root->data);
}
