Iterative Version (C)
#include <stdio.h>
#include <string.h>

int main() {
    char number[1000];
    scanf("%s", number);

    int length = strlen(number);

    for (int i = 0; i < length - 1; i++) {
        char min_digit = number[i];
        int min_index = i;

        // Find the smallest digit to swap with
        for (int j = length - 1; j > i; j--) {
            if ((number[j] < min_digit && (i > 0 || number[j] != '0')) || 
                (number[j] == min_digit && j > min_index)) {
                min_digit = number[j];
                min_index = j;
            }
        }

        // Swap if a better digit is found
        if (min_index != i) {
            char temp = number[i];
            number[i] = number[min_index];
            number[min_index] = temp;
            break;
        }
    }

    printf("%s\n", number);
    return 0;
}
Recursive Version (C)
#include <stdio.h>
#include <string.h>

void findSmallestNumber(char *number, int current_index, int length, int *swapped) {
    if (current_index >= length - 1 || *swapped) return;

    char min_digit = number[current_index];
    int min_index = current_index;

    // Find the smallest digit to swap with
    for (int j = length - 1; j > current_index; j--) {
        if ((number[j] < min_digit && (current_index > 0 || number[j] != '0')) || 
            (number[j] == min_digit && j > min_index)) {
            min_digit = number[j];
            min_index = j;
        }
    }

    // Swap if a better digit is found
    if (min_index != current_index) {
        char temp = number[current_index];
        number[current_index] = number[min_index];
        number[min_index] = temp;
        *swapped = 1;
    } else {
        findSmallestNumber(number, current_index + 1, length, swapped);
    }
}

int main() {
    char number[1000];
    scanf("%s", number);

    int length = strlen(number);
    int swapped = 0;

    findSmallestNumber(number, 0, length, &swapped);

    printf("%s\n", number);
    return 0;
}
Complexity Analysis
The time complexity of both the iterative and recursive solutions is O(n^2)
in the worst-case scenario. This is because they involve a nested search to identify the optimal digit for swapping. As for space complexity, it is 
𝑂(n), attributed to the storage of digits in an auxiliary array.
