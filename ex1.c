#include <stdio.h>
//finding a digit and swap its position in the number to obtain the largest possible value
//51229 -> impossible largest value is 92251 aftet swap 
//propose an algorithm using interation and implement it in C to complete the task
//propose and implement an alternative algorithm using recursion for this task 
//calculate the complexity of the two approaches.justify your answer by making comment on the code
int pow(int n, int m){
    int result = 1;
    for(int i = 0; i < 5; i++){
        result *= 10;
    }
    return result;
}
int swap(int n){
    int max = n;
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
           int a = (n/pow(10, i))%10;
    }
    return max;
}
int main(){
    int n = 51229;
    printf("The largest possible value is %d", swap(n));
}