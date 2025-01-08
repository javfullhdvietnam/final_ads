#include <stdio.h>

// Function for Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow

        if (arr[mid] == target) { // Target found
            return mid;
        } else if (arr[mid] < target) { // Target is in the right half
            left = mid + 1;
        } else { // Target is in the left half
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {2, 4, 7, 10, 23, 32, 50, 61, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
