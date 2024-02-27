#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int vertex;
    struct node * next;
}Node;

typedef struct q{
    int front,rear,size;
    int items[100];
}Queue;

typedef struct g{
    int NumVertices;
    Node ** adjlist;
    int * inDegree;
}Graph;

Node * createnode(int val){
    Node * new = (Node *)malloc(sizeof(Node));
    new->vertex = val;
    new->next = NULL;
    return new;
}

Graph * creategraph(int numV){
    Graph * g = (Graph*)malloc(sizeof(Graph));
    g->NumVertices = numV;
    g->adjlist = malloc(numV * sizeof(Node *));
    g->inDegree = malloc(numV * sizeof(int));
    for (int i=0;i<numV;i++){
        g->adjlist[i] = NULL;
        g->inDegree[i] = 0;
    }
    return g;
}

void addEdge(Graph *g,int s, int d){
    Node * new = createnode(d);
    new->next = g->adjlist[s];
    g->adjlist[s] = new;
    g->inDegree[d]++;
}

void createqueue(Queue * q){
    q->size = 0;
    q->front = q->rear = -1;
}

void enque(Queue * q, int val){
    q->items[++q->rear] = val;
    q->size++;
}

int deque(Queue * q){
    int d = q->items[q->front++];
    q->size--;
    return d;
}

void Topologicalsort(Graph * g){
    Queue * q,*finalq;
    createqueue(q);
    createqueue(finalq);

    for(int i=0;i<g->NumVertices;i++){
        if(g->inDegree[i] == 0){
            enque(q,i);
        }
    }

    int count = 0;
    while(q->size!=0){
        int v = deque(q);
        enque(finalq,v);
        count ++;

        Node * current = g->adjlist[v];
        while(current!=NULL){
            g->inDegree[current->vertex]--;
            if(g->inDegree[current->vertex] == 0){
                enque(q,current->vertex);
            }
            current = current->next;
        }

    }
    if(count != g->NumVertices){
        printf("Cycle present");
    }
    else{
        while(finalq->size!=0){
            int t = deque(finalq);
            printf("%d ",t );
        }
    }
}

int main(){
    Graph * g = creategraph(5);
    addEdge(g,0,2);
    addEdge(g,1,2);
    addEdge(g,2,3);
    addEdge(g,3,4);
    Topologicalsort(g);
    return 0;
}