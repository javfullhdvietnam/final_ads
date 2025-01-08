#include <stdio.h>

// Function prototypes
int gcd(int a, int b); 
void findCoprimePairsRecursive(int arr[], int size, int i, int j);

int main() {
    int arr[10] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int size = 10;

    printf("Co-prime pairs in the array are:\n");
    findCoprimePairsRecursive(arr, size, 0, 1);

    return 0;
}

// Function to calculate GCD using recursion
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Recursive function to find co-prime pairs
void findCoprimePairsRecursive(int arr[], int size, int i, int j) {
    if (i >= size - 1) return;         // Base case: end of array
    if (j >= size) {                   // End of inner loop, move to the next element
        findCoprimePairsRecursive(arr, size, i + 1, i + 2);
        return;
    }
    if (gcd(arr[i], arr[j]) == 1) {    // Check if pair is co-prime
        printf("(%d, %d)\n", arr[i], arr[j]);
    }
    findCoprimePairsRecursive(arr, size, i, j + 1); // Move to the next pair
}
