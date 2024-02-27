#include<stdio.h>
#include<stdbool.h>

void addEdge(int v, int (*adj)[v], int s, int d){
    adj[s][d] = 1;
    adj[d][s] = 1;

}

bool DFS(int v, int (*adj)[v], int s, int *visited, int parent){
    visited[s]  = 1;
    for(int i=0;i<v;i++){
        if(adj[s][i] == 1){
            if(visited[i] == 0){
                if(DFS(v,adj,i,visited,s)){
                    return true;
                }
            }
            else if(parent!=i){
                return true;
            }
        }
    }
    return false;

}

bool ISCYCLE(int v, int (*adj)[v]){
    int visited[v];
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j] == 1 && visited[j] == 0){
                if(DFS(v,adj,j,visited,-1)){
                    return true;
                }
            }
        }
    }
    return false;

}


void main(){
     int v=6;
    int adj[v][v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    addEdge(v, adj, 0, 1);
    addEdge(v, adj, 1, 2);
    addEdge(v, adj, 1, 3);
    addEdge(v, adj, 2, 3);
    addEdge(v, adj, 2, 4);
    addEdge(v, adj, 4, 5);

    if(ISCYCLE(v,adj)){
        printf("CYCLES PRESENT");
    }
}