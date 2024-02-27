#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}


void merge(int * arr, int beg,int mid, int end){
    int i,j,k;
    int n1 = mid-beg+1;
    int n2 = end-mid;
    int Left[n1],Right[n2];

    for(i =0;i<n1;i++){
        Left[i] = arr[beg+i];
    }
    for(j=0;j<n2;j++){
        Right[j] = arr[mid+1+j];
    }     

    i = 0;
    j = 0;
    k = beg;
    while(i<n1 && j<n2){
        if(Left[i]<Right[j]){
            arr[k] = Left[i];
            i++;
        }
        else{
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = Left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = Right[j];
        j++;
        k++;
    }





}

void mergesort(int *arr, int beg, int end){
    if(beg<end){

        int mid = beg + (end-beg)/2;

        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);

        merge(arr,beg,mid,end);
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
    mergesort(arr,0,size-1);
    printf("\nAFTER SORTED\n");
    printarr(arr,size);
}