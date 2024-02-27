#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}


int partition(int * arr, int l, int r){

    int pivot = arr[l];
    int i = l;
    int j = r+1;
    while(i<j){

        do{
            i++;

        }while(arr[i]<pivot && i<=r);
        do{
            j--;
        }while(arr[j]>pivot && j>=l);

        if(i<j){
            swap(&arr[i],&arr[j]);
        }}
        swap(&arr[l],&arr[j]);
        return j;
    }


void quicksort(int * arr, int l, int r){
    if(l<r){
        int s = partition(arr,l,r);
        quicksort(arr,l,s-1);
        quicksort(arr,s+1,r);
    }
}  




void printarr(int * arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[] = {3,4,7,1,2,5};
    int size = (sizeof(arr)/sizeof(arr[0]));

    printf("\nBEFORE SORTED\n");
    printarr(arr,size);
    quicksort(arr,0,size-1);
    printf("\nAFTER SORTED\n");
    printarr(arr,size);






}