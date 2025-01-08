#include <stdio.h>
#include <stdbool.h>

int number_to_digits(long long num, int digits[]) {
    if (num == 0) {
        digits[0] = 0;
        return 1;
    }

    int temp[30];
    int count = 0;
    while (num > 0) {
        temp[count++] = (int)(num % 10);
        num /= 10;
    }

    for (int i = 0; i < count; i++) {
        digits[i] = temp[count - 1 - i];
    }
    return count;
}

long long digits_to_number(int digits[], int length) {
    long long result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 10 + digits[i];
    }
    return result;
}

//iteration
long long swap_iteration(long long num) {
    int digits[30];
    int n = number_to_digits(num, digits);

    for (int i = 0; i < n - 1; i++) {
        int maxDigit = digits[i];
        int maxPos = i;
        for (int j = n - 1; j > i; j--) {
            if (digits[j] > maxDigit && !(i == 0 && digits[j] == 0)) {
                maxDigit = digits[j];
                maxPos = j;
            }
        }
        if (maxPos != i) {
            int temp = digits[i];
            digits[i] = digits[maxPos];
            digits[maxPos] = temp;
            break;
        }
    }

    return digits_to_number(digits, n);
}

//recursion
bool recursive_swap(int digits[], int n, int i) {
    if (i >= n - 1) {
        return false;
    }

    int maxDigit = digits[i];
    int maxPos = i;
    for (int j = n - 1; j > i; j--) {
        if (digits[j] > maxDigit && !(i == 0 && digits[j] == 0)) {
            maxDigit = digits[j];
            maxPos = j;
        }
    }
    if (maxPos != i) {
        int temp = digits[i];
        digits[i] = digits[maxPos];
        digits[maxPos] = temp;
        return true;
    } else {
        return recursive_swap(digits, n, i + 1);
    }
}

long long swap_recursion(long long num) {
    int digits[30];
    int n = number_to_digits(num, digits);

    recursive_swap(digits, n, 0);

    return digits_to_number(digits, n);
}

//main func
int main(void) {
    long long num = 51229;

    long long largest_iteration = swap_iteration(num);
    printf("largest value using iteration: %lld\n", largest_iteration);

    long long largest_recursion = swap_recursion(num);
    printf("largest value using recursion: %lld\n", largest_recursion);

    return 0;
}

/*
Time Complexity:

- with iteration: We use two nested loops (i and j). In the worst case => O(n^2).
- with recursion: We still have an inner loop to find the largest digit on the right side,
  plus the recursion stepping from i=0 to i+1. In the worst case => also O(n^2).
*/
