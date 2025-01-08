#include <stdio.h>

void countOddEven(int N, int oddDigits[], int evenDigits[], int *oddCount, int *evenCount) {
    *oddCount = 0;  
    *evenCount = 0; 

    while (N > 0) {
        int digit = N % 10; 
        if (digit % 2 == 0) { 
            evenDigits[*evenCount] = digit;
            (*evenCount)++;
        } else { 
            oddDigits[*oddCount] = digit;
            (*oddCount)++;
        }
        N /= 10; 
    }
}

int main() {
    int N = 3450;

    int oddDigits[10], evenDigits[10];
    int oddCount = 0, evenCount = 0;

    countOddEven(N, oddDigits, evenDigits, &oddCount, &evenCount);

  
    printf("The number of odd digits in %d is %d with odd digits = {", N, oddCount);
    for (int i = 0; i < oddCount; i++) {
        printf("%d", oddDigits[i]);
        if (i < oddCount - 1) printf(", ");
    }
    printf("}\n");

    printf("The number of even digits in %d is %d with even digits = {", N, evenCount);
    for (int i = 0; i < evenCount; i++) {
        printf("%d", evenDigits[i]);
        if (i < evenCount - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}
