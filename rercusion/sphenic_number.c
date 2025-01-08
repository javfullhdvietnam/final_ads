#include <stdio.h>

int isPrime(int n);
void findSphenicNumbers(int current, int limit);
int isSphenic(int num);

int main() {
    int n = 100;//O(1)

    findSphenicNumbers(1, n);

    return 0;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void findSphenicNumbers(int current, int limit) {
    if (current > limit) return;
    if (isSphenic(current)) {
        printf("%d ", current);
    }
    findSphenicNumbers(current + 1, limit);
}

int isSphenic(int num) {
    int count = 0;
    int product = 1;
    for (int i = 2; i <= num && count < 3; i++) {
        if (isPrime(i) && num % i == 0) {
            count++;
            product *= i;
        }
    }
    if (count == 3 && product == num) return 1;
    return 0;
}
    // Time Complexity Analysis:
    // - Outer loop runs from i=2 to sqrt(num): O(√n)
    // - Inner while loop divides num by i until not divisible: O(log n)
    // - Overall time complexity: O(√n * log n)
    // where n is the input number