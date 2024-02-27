#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int vertex;
    struct node * next;
}Node;

typedef struct g{
    int NumVertices;
    Node ** adjlist;

}Graph;

Node * createnode(int val){
    Node * new = (Node *)malloc(sizeof(Node ));
    new->vertex = val;
    new->next = NULL;
    return new;
}

Graph * creategraph(int numV){
    Graph * g = (Graph*)malloc(sizeof(Graph));
    g->NumVertices = numV;
    g->adjlist = malloc(numV * sizeof(Node));

    for(int i=0;i<numV;i++){
        g->adjlist[i] = NULL;

    }
    return g;

}

void addEdge(Graph *g, int s,int d){
    Node * new = createnode(d);
    new->next = g->adjlist[s];
    g->adjlist[s] = new;

}

void Topoutil(Graph *g,int v,bool visited[], Node ** stack){
    visited[v] = true;
    Node * current = g->adjlist[v];
    while(current!=NULL){
        if(!visited[current->vertex]){
            Topoutil(g,current->vertex,visited,stack);
        }
        current = current->next;
    }
    Node* newnode = createnode(v);
    newnode->next = *stack;
    *stack = newnode;
    
}

void Topologicalsort(Graph * g){
    Node * stack = NULL;
    bool * visited = (bool * )malloc(g->NumVertices * sizeof(bool));
    for (int i=0;i<g->NumVertices;i++){
        visited[i] = false;
    }
    for (int i=0;i<g->NumVertices;i++){
        if(!visited[i]){        

            Topoutil(g,i,visited,&stack);
        }
    }

    while(stack!=NULL){
        printf("%d ",stack->vertex);
        stack = stack ->next;
    }
}


void main(){

    Graph * g = creategraph(5);
    addEdge(g, 1, 0);
    addEdge(g, 2, 0);
    addEdge(g, 3, 0);
    Topologicalsort(g);

}