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

// iteration
long long swap_iteration(long long num) {
    int digits[30];
    int n = number_to_digits(num, digits);

    for (int i = 0; i < n - 1; i++) {
        int minDigit = digits[i];
        int minPos = i;
        for (int j = n - 1; j > i; j--) {
            if (digits[j] < minDigit && !(i == 0 && digits[j] == 0)) {
                minDigit = digits[j];
                minPos = j;
            }
        }
        if (minPos != i) {
            int temp = digits[i];
            digits[i] = digits[minPos];
            digits[minPos] = temp;
            break;
        }
    }

    return digits_to_number(digits, n);
}


// recursion
bool recursive_swap(int digits[], int n, int i) {
    if (i >= n - 1) {
        return false;
    }

    int minDigit = digits[i];
    int minPos = i;
    for (int j = n - 1; j > i; j--) {
        if (digits[j] < minDigit && !(i == 0 && digits[j] == 0)) {
            minDigit = digits[j];
            minPos = j;
        }
    }
    if (minPos != i) {
        int temp = digits[i];
        digits[i] = digits[minPos];
        digits[minPos] = temp;
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
    long long num = 51029;

    //iteration
    long long smallest_iteration = swap_iteration(num);
    printf("smallest value using iteration is: %lld\n", smallest_iteration);

    //recursion
    long long smallest_recursion = swap_recursion(num);
    printf("smallest value using recursion is: %lld\n", smallest_recursion);

    return 0;
}

/*
Complexity:

- with iteration: We use two nested loops (i, j). In the worst case => the complexity is O(n^2).
- with recursion: we still have an inner loop to find the smallest digit on the right side, 
then plus the recursion stepping from i=0 to i+1 etc. In the worst case => complexity also reaches O(n^2).

*/
