#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int reverse_number(int number) {
    int reversed = 0;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}


bool is_palindrome(int number) {
    char str[20];
    sprintf(str, "%d", number);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}


bool is_product_palindromic_recursive(int n) {
    int reverse_n = reverse_number(n);
    int product = n * reverse_n;
    return is_palindrome(product);
}

int main() {

    int numbers[] = {12, 102, 1101};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Number | Reverse | Product  | Palindromic\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < size; i++) {
        int number = numbers[i];
        int reverse_n = reverse_number(number);
        int product = number * reverse_n;
        bool is_palindromic = is_product_palindromic_recursive(number);
        printf("%6d | %7d | %8d | %s\n", number, reverse_n, product, is_palindromic ? "Yes" : "No");
    }

    return 0;
}
