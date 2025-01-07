#include <stdio.h>
// FUNCTION isPentagonal(x, n = 1)
//     IF x < 1 THEN
//         RETURN false
//     END IF
    
//     pentagonal = (3 * n * n - n) / 2
    
//     IF pentagonal equals x THEN
//         RETURN true
//     END IF
    
//     IF pentagonal > x THEN
//         RETURN false
//     END IF
    
//     RETURN isPentagonal(x, n + 1)
// END FUNCTION

// FUNCTION checkPentagonalArray(array)
//     FOR EACH number IN array
//         IF isPentagonal(number) THEN
//             PRINT number + " is a pentagonal number"
//         ELSE
//             PRINT number + " is not a pentagonal number"
//         END IF
//     END FOR
// END FUNCTION

// MAIN PROGRAM
//     array = [1, 5, 12, 22, 35, 8, 20]
//     checkPentagonalArray(array)
// END PROGRAM
int isPentagonal(int x,int n){
    
    if(x<1){
        return 0;
    }
    int petagonal =(3*n*n -n)/2;
    if(petagonal ==x){
        return 1;
    }
    if(petagonal >x){
        return 0;
    }
    return isPentagonal(x,n+1);
}

void checkPentagonalArray(int num[],int size){
    for(int i; i<size;i++){
        if(isPentagonal(num[i],1)){
            printf("%d is a petagonal.\n ",num[i]);
        }
        else{
            printf("it is not petagonal.\n ",num[i]);
        }
    }
}

int main(){
    int num[] = {1,5,12,22,35,8,20};
    int size = sizeof(num)/sizeof(num[0]);
    checkPentagonalArray(num, size);

}