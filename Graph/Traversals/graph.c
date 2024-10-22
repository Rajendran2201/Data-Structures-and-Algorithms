#include<stdio.h>
#include "queue-template.c"


#define len 7

void bfs(int graph[][len]);
void dfs(int graph[][len], int visited[], int node);

int main(){

   int graph[len][len] = {
    // 0  1  2  3  4  5  6
    { 0, 1, 1, 0, 0, 0, 0 },  
    { 1, 0, 0, 1, 1, 0, 0 },  
    { 1, 0, 0, 0, 0, 1, 0 },  
    { 0, 1, 0, 0, 0, 0, 0 },  
    { 0, 1, 0, 0, 0, 0, 1 },  
    { 0, 0, 1, 0, 0, 0, 1 },  
    { 0, 0, 0, 0, 1, 1, 0 }   
};  


  /*
        0
       / \
      1   2
     / \   \
    3   4   5
         \  /
          6

  
  */



  printf("BFS Traversal: ");
  bfs(graph);

  int visited[len] = {0}; 
  printf("\nDFS Traversal: ");
  dfs(graph, visited, 0);


  return 0;
}

void bfs(int graph[][len]){

   int visited[len] = {0};
   // start with the first element
   enqueue(0);
   visited[0] = 1;

   while(!isEmpty()){
      int current = queue[front++];
      printf("%d\t", current);

      // add the neighbors of current to the queue
      for(int i=0; i<len; i++){
        if(graph[current][i] == 1 && !visited[i]){
          enqueue(i);
          visited[i] = 1;
        }
      }
   }

}

void dfs(int graph[][len], int visited[], int node){
    visited[node] = 1; 
    printf("%d\t", node);  
    
    // Explore the neighbors of the current node
    for(int i = 0; i < len; i++) {
        if(graph[node][i] == 1 && !visited[i]) {
            dfs(graph, visited, i);  // Recursively visit unvisited neighbors
        }
    }
}