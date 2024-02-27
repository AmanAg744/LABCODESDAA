#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * left;
    struct node * right;

}Node;

Node * createnode(int val){
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
    }

Node * createtree(int val){
    if(val!=-1){
        int a,b;
        Node * temp = createnode(val);
        printf("Left child of %d",temp->data);
        scanf("%d",&a);
        temp->left = createtree(a);
        printf("Right child of %d",temp->data);
        scanf("%d",&b);
        temp->right = createtree(b);
        return temp;
    }
    else{
        return NULL;
    }
}
int count = 0;
void inorder(Node * head){
    
    if (head!=NULL){
        inorder(head->left);
        count++;
        inorder(head->right);
    }
}


void main(){

    Node * head = NULL;
    createtree(8);
    inorder(head);
    printf("No of nodes %d",count);
}