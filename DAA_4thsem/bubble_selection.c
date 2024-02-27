#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

void bubblesort(int *arr, int n){
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void insertionsort(int * arr,int n){
    int key;
    for(int i=1;i<n;i++){
        key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        } 
        arr[j+1] = key;
    }

}

void selectionsort(int * arr, int n){
    int min,idx;
    for(int i=0;i<n-1;i++){
        min = arr[i];
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min = arr[j];
                idx = j;
            }
            
        }
        swap(&arr[i],&arr[idx]);
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
    insertionsort(arr,size);
    printf("\nAFTER SORTED\n");
    printarr(arr,size);






}


