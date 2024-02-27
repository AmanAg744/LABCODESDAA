#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stringmatch(char * str,char * snip ){

    int n = strlen(str);
    int m = strlen(snip);
    for (int i=0;i<=n-m;i++){
        int j = 0;
        while(j<m && str[i+j] == snip[j]){
            j++;
        }
        if(j==m){
            return i;
        }
        
    }
    return -1;
}

void main(){
    char str[] = "Hello how are you";
    char snip[] = "how";

    int s = stringmatch(str,snip);// RETURNS THE INDEX OF THE MATCHED STRING
    
    printf("%d",s);

}