#include <stdio.h>
#include <stdlib.h>

// Linked List Node structure
typedef struct Node {
    int digit;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from the number
Node* createLinkedList(int N) {
    Node* head = NULL;
    Node* tail = NULL;

    while (N > 0) {
        Node* newNode = createNode(N % 10);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode; // Add at the beginning
        }
        N /= 10;
    }
    return head;
}

// Function to count odd and even digits in the linked list
void countOddAndEven(Node* head, int* oddCount, int* evenCount, int oddDigits[], int evenDigits[]) {
    int oddIndex = 0, evenIndex = 0;

    while (head != NULL) {
        if (head->digit % 2 == 0) { // Check if digit is even
            evenDigits[evenIndex++] = head->digit;
            (*evenCount)++;
        } else { // Digit is odd
            oddDigits[oddIndex++] = head->digit;
            (*oddCount)++;
        }
        head = head->next;
    }
}

int main() {
    int N = 3450;

    // Create a linked list from the number
    Node* head = createLinkedList(N);

    // Arrays to store odd and even digits
    int oddDigits[10], evenDigits[10];
    int oddCount = 0, evenCount = 0;

    // Count odd and even digits
    countOddAndEven(head, &oddCount, &evenCount, oddDigits, evenDigits);

    // Display results
    printf("The number of odd digits in %d is %d with odd digits = {", N, oddCount);
    for (int i = 0; i < oddCount; i++) {
        printf("%d", oddDigits[i]);
        if (i < oddCount - 1) printf(", ");
    }
    printf("}\n");

    printf("The number of even digits in %d is %d with even digits = {", N, evenCount);
    for (int i = 0; i < evenCount; i++) {
        printf("%d", evenDigits[i]);
        if (i < evenCount - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}
