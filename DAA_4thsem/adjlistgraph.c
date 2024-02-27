#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int vertex;
    struct node * next;
}Node;

typedef struct graph{
    int numV;
    Node ** adjlist;
}Graph;

Node * createnode(int val){
    Node * new = (Node*)malloc(sizeof(Node));
    new->vertex = val;
    new->next = NULL;
    return new;
}

Graph * creategraph(int numvertices){
    Graph * graph = (Graph*)malloc(sizeof(Graph));
    graph->numV = numvertices;
    graph->adjlist = malloc(numvertices *sizeof(Node *));
    for (int i=0;i<numvertices;i++){
        graph->adjlist[i] = NULL;

    }
    return graph;


}

void addEdge(Graph * graph, int s, int d){

    Node * new = createnode(d);
    new->next  = graph->adjlist[s];
    graph->adjlist[s] = new;
}

void printgraph(Graph * graph){
    for(int i =0;i<graph->numV;i++){
        Node * temp = graph->adjlist[i];
        printf("Vertex %d :\t",i);
        while(temp){
            printf("%d->",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
Graph* graph = creategraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);

  printgraph(graph);
}
