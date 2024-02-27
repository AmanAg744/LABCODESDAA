#include<stdio.h>
#include<stdlib.h>




int binarysearch(int *arr, int x, int l, int h){
    if (l>h){
        return -1;
    }
    else {
        int mid = (l+h)/2;
        if (x == arr[mid]){
            return mid;
        }
        else{
            if (x>arr[mid]){
                return binarysearch(arr,x,mid+1,h);

            }
            else{
                return binarysearch(arr,x,l,mid-1);
            }
        }
    }


}


void main(){
    int arr[] = {3,4,7,1,2,5};
    int size = (sizeof(arr)/sizeof(arr[0]));

    int key = 4;

    int s = binarysearch(arr,key,0,size-1);

    printf("%d",s);








}