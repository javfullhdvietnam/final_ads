#include <stdio.h>


void primeFactorization(int num, int factors[], int *size, int divisor) {
    if (num == 1) return; 
    if (num % divisor == 0) {
        factors[(*size)++] = divisor; 
        primeFactorization(num / divisor, factors, size, divisor); 
    } else {
        primeFactorization(num, factors, size, divisor + 1); 
    }
}

void countFrequencies(int factors[], int size, int unique[], int freq[], int *uniqueSize) {
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < *uniqueSize; j++) {
            if (factors[i] == unique[j]) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[*uniqueSize] = factors[i];
            freq[*uniqueSize] = 1;
            (*uniqueSize)++;
        }
    }
}


int calculateSquareRoot(int unique[], int freq[], int uniqueSize) {
    int squareRoot = 1;
    for (int i = 0; i < uniqueSize; i++) {
        if (freq[i] % 2 != 0) return -1; 
        squareRoot *= unique[i]; 
    }
    return squareRoot;
}

int main() {
    int numbers[] = {144, 900, 54}; 
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    for (int k = 0; k < arraySize; k++) {
        int num = numbers[k];
        
     
        int factors[100], size = 0;
        primeFactorization(num, factors, &size, 2);

       
        int unique[100], freq[100], uniqueSize = 0;
        countFrequencies(factors, size, unique, freq, &uniqueSize);

        int squareRoot = calculateSquareRoot(unique, freq, uniqueSize);
        if (squareRoot == -1) {
            printf("%d is not a perfect square.\n", num);
        } else {
            printf("%d is a perfect square. Square root = %d\n", num, squareRoot);
        }
    }

    return 0;
}
