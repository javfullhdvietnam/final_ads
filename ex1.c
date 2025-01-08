#include <stdio.h>
//finding a digit and swap its position in the number to obtain the largest possible value
//51229 -> impossible largest value is 92251 aftet swap 
//propose an algorithm using interation and implement it in C to complete the task
//propose and implement an alternative algorithm using recursion for this task 
//calculate the complexity of the two approaches.justify your answer by making comment on the code
int swap(int n);
int main(){
    int n = 51229;
    printf("The largest possible value is %d", swap(n));
}

int swap(int n){
    int max = n;
    int i = 0;
    while(i<5){
        int j = i+1;
        while(j<5){
            int m = swapDigit(n,i,j);
            if(m>max){
                max = m;
            }
            j++;
        }
        i++;
    }
    return max;
}
