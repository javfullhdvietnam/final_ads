Iterative Algorithm in C
#include <stdio.h>
#include <string.h>

void findLargestIterative(char* num) {
    int n = strlen(num);
    for (int i = 0; i < n - 1; i++) {
        char max_digit = num[i];
        int max_index = i;

        for (int j = n - 1; j > i; j--) {
            if (num[j] > max_digit) {
                max_digit = num[j];
                max_index = j;
            }
        }

        if (max_index != i) {
            char temp = num[i];
            num[i] = num[max_index];
            num[max_index] = temp;
            break;
        }
    }
}

int main() {
    char number[1000];
    scanf("%s", number);
    findLargestIterative(number);
    printf("Largest possible value: %s\n", number);
    return 0;
}
Recursive Algorithm in C
#include <stdio.h>
#include <string.h>

void findLargestRecursive(char* num, int start, int n, int* swapped) {
    if (start >= n - 1 || *swapped) return;

    char max_digit = num[start];
    int max_index = start;

    for (int j = n - 1; j > start; j--) {
        if (num[j] > max_digit) {
            max_digit = num[j];
            max_index = j;
        }
    }

    if (max_index != start) {
        char temp = num[start];
        num[start] = num[max_index];
        num[max_index] = temp;
        *swapped = 1;
    } else {
        findLargestRecursive(num, start + 1, n, swapped);
    }
}

int main() {
    char number[1000];
    scanf("%s", number);
    int swapped = 0;
    findLargestRecursive(number, 0, strlen(number), &swapped);
    printf("Largest possible value: %s\n", number);
    return 0;
}
Complexity Analysis:

Iterative Algorithm:

Time Complexity: O(n^2). The algorithm involves a nested loop where the outer loop runs n times (in the worst case), and the inner loop compares each digit from the current index to the end.
Space Complexity: O(1). The algorithm works in-place and uses constant extra memory.
Recursive Algorithm:

Time Complexity: O(n^2). Similar to the iterative approach, the recursion involves nested comparisons for n digits in the worst case.
Space Complexity: O(n). The recursive approach uses additional memory for the recursive call stack, proportional to the number of recursive calls.
Both approaches ultimately have the same time complexity, but the recursive method has slightly higher space complexity due to the call stack.

