#include <stdio.h>
// countOdd(N):
//     If N == 0:
//         Return 0
//     If last digit of N (N % 10) is odd:
//         Return 1 + countOdd(N / 10)
//     Else:
//         Return countOdd(N / 10)

// countEven(N):
//     If N == 0:
//         Return 0
//     If last digit of N (N % 10) is even:
//         Return 1 + countEven(N / 10)
//     Else:
//         Return countEven(N / 10)




int countOdd(int N, int oddDigits[], int *indexOdd) {
    if (N == 0) return 0; 
    if ((N % 10) % 2 != 0) {
        oddDigits[(*indexOdd)++] = N % 10; 
        return 1 + countOdd(N / 10, oddDigits, indexOdd); 
    }
    return countOdd(N / 10, oddDigits, indexOdd);
}

int countEven(int N, int evenDigits[], int *indexEven) {
    if (N == 0) return 0; 
    if ((N % 10) % 2 == 0) {
        evenDigits[(*indexEven)++] = N % 10; 
        return 1 + countEven(N / 10, evenDigits, indexEven); 
    }
    return countEven(N / 10, evenDigits, indexEven); 
}

int main() {
    int N = 3450;

    
    int oddDigits[10], evenDigits[10];
    int indexOdd = 0, indexEven = 0;


    int oddCount = countOdd(N, oddDigits, &indexOdd);
    int evenCount = countEven(N, evenDigits, &indexEven);

    printf("The number of odd digits in %d is %d with odd digits = {", N, oddCount);
    for (int i = 0; i < indexOdd; i++) {
        printf("%d", oddDigits[i]);
        if (i < indexOdd - 1) printf(", ");
    }
    printf("}\n");

    printf("The number of even digits in %d is %d with even digits = {", N, evenCount);
    for (int i = 0; i < indexEven; i++) {
        printf("%d", evenDigits[i]);
        if (i < indexEven - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}
