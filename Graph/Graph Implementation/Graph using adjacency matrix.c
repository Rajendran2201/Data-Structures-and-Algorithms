#include<stdio.h>
#include<stdbool.h>
#define MAX_VERTICES 100

  // Directional Graph Implementation using Adjacency Matrix

struct Graph{
  int num_of_vertices;
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};


void initializeGraph(struct Graph* graph, int num_of_vertices){

  for(int i=0; i<num_of_vertices; i++){
    for(int j=0; j<num_of_vertices; j++){
      graph->adjMatrix[i][j] = 0;
    }
  }
}

void addEdge(struct Graph* graph, int v1, int v2){
  if((v1 >=0 && v1 < graph->num_of_vertices) && (v2 >=0 && v2 < graph->num_of_vertices)){
    graph->adjMatrix[v1][v2] = 1;
    printf("\nAddition successful");
  }else{
    printf("\nthe values are out of bound!");
  }
}

void removeEdge(struct Graph* graph, int v1, int v2){
  if((v1 >=0 && v1 < graph->num_of_vertices) && (v2 >=0 && v2 < graph->num_of_vertices)){
    if(graph->adjMatrix[v1][v2] == 1){
      graph->adjMatrix[v1][v2] = 0;
      printf("\nDeletion successful");
    }else{
      printf("\nno such edge exists!");
    }
  }else{
    printf("\nthe values are out of bound!");
  }
}

bool hasEdge(struct Graph* graph, int v1, int v2){
   if((v1 >=0 && v1 < graph->num_of_vertices) && (v2 >=0 && v2 < graph->num_of_vertices)){
    return graph->adjMatrix[v1][v2] == 1;
   }
   return false;
}

int main(){
  
  struct Graph graph;

  printf("\nEnter the number of vertices: ");
  scanf("%d", &graph.num_of_vertices);

  initializeGraph(&graph, graph.num_of_vertices);

  addEdge(&graph, 1, 3);

  bool ans = hasEdge(&graph, 1, 3);

  if(ans){
    printf("\nThe edge exists!");
  }else{
    printf("\nThe edge doesn't exists");
  }

  removeEdge(&graph, 1, 3);

  return 0;
}
