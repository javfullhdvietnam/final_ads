
#include <stdio.h>
// Function isPrime(number, divisor):

//     if number < 2: 
//         return false    
//     if divisor == 1:
//         return true    
        
//     if number mod divisor == 0:
//         return false   
        
//     return isPrime(number, divisor-1)   

// Function isPrimeNumber(number):

//     return isPrime(number, number/2)  


// Function findTwinPrimes(array, size):
   
//     for i from 0 to size-1:
//         for j from i+1 to size-1:
//             if isPrimeNumber(array[i]) AND 
//                isPrimeNumber(array[j]) AND
//                (array[j] - array[i] == 2 OR array[i] - array[j] == 2):
//                    print (array[i], array[j])


// Function main():
//     array = [3,101,96,47,41,7,65,9,13,5,79,45,30,11,43]
//     size = length of array
//     findTwinPrimes(array, size)
int isPrime(int num,int divisor){ 
    if(num<2)return 0; //O(1)
    if(divisor==1)return 1; //(O(1))
    if(num%divisor==0)return 0;//O(1)
    return isPrime(num,divisor-1);//O(n)
}
int isPrimeNumber(int num){
    return isPrime(num,num/2);//O(n)
}

void findtwinprimes(int num[], int size){
    for(int i=0;i<size;i++){  //O(n^2)
       for(int j=i+1;j<size;j++){
           if(isPrimeNumber(num[i]) && isPrimeNumber(num[j]) && (num[j]-num[i]==2||num[i]-num[j]==2)){//O(n^2)
               printf("(%d,%d)\n",num[i],num[j]); //O(1)
           }
       }
    }
}

int main(){
    int num[] = {3,101,96,47,41,7,65,9,13,5,79,45,30,11,43};//O(1)
    int size = sizeof(num)/sizeof(num[0]);//  O(1)
    findtwinprimes(num, size);//O(n^2)
    return 0;
}
//Time complexity of the code is O(n^2) as there are two nested loops in the findtwinprimes function.