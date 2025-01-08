#include <stdio.h>

// Function prototypes
int gcd(int a, int b);
void findCoprimePairs(int arr[], int size);

int main() {
    int arr[10] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int size = 10;

    printf("Co-prime pairs in the array are:\n");
    findCoprimePairs(arr, size);

    return 0;
}

// Function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find all co-prime pairs in the array
void findCoprimePairs(int arr[], int size) {
    for (int i = 0; i < size; i++) {             // O(n)
        for (int j = i + 1; j < size; j++) {     // O(n)
            if (gcd(arr[i], arr[j]) == 1) {      // O(log(min(a, b)))
                printf("(%d, %d)\n", arr[i], arr[j]); // O(1)
            }
        }
    }
}
