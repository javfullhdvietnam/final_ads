#include <stdio.h>

int isceteredcube(int x, int n ){
    if(x<1){
        return 0;
    }
    int ceteredcube = n*n +(n+1)*(n+1)*(n+1);
    if(ceteredcube ==x){
        return 1;
    }
    if(ceteredcube >x){
        return 0;
    }
    return isceteredcube(x,n+1);
}

void checkisceterdcude(int num[],int size){
    for(int i=0; i<size;i++){
        if(isceteredcube(num[i],1)){
            printf("%d is cetered cube\n",num[i]);
        }
        else{
            printf("%d is not ceterd cube \n",num[i]);
        }
    }
}

int main(){
    int num[] = {9,35,91,124,189,213,555,559};
    int size = sizeof(num)/sizeof(num[0]);
    checkisceterdcude(num,size);
}