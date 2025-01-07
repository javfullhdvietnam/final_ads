#include <stdio.h>
//
int isoctahedral(int x, int n){
    if(x<1){
        return 0;
    }
   int octahedral = ((2*n*n+1)*n)/3;
   if(octahedral ==x){
    return 1;
   }
   if(octahedral >x){
    return 0;
   }
   return isoctahedral(x,n+1);
}
void checkoctahedreal(int num[], int size){
    for(int i = 0;i<size;i++){
        if(isoctahedral(num[i],1)){
            printf("%d is octahedral\n",num[i]);
        }
        else{
            printf("%d is not octahedral\n",num[i]);
        }
    }
}

int main(){
    int num[] = {1,6,9,19,31,45,77};
    int size = sizeof(num)/sizeof(num[0]);
    checkoctahedreal(num,size);
}