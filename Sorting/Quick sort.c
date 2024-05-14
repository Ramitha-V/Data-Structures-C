#include <stdio.h>

// Function to partition the array for Quick Sort
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];  // Choose the pivot as the first element
    int start = lb;       // Initialize the starting index
    int end = ub;         // Initialize the ending index
    int temp;             // Temporary variable for swapping

    while (start < end) {
        // Move the starting index to the right while elements are less than or equal to pivot
        while (arr[start] <= pivot) {
            start++;
        }
        
        // Move the ending index to the left while elements are greater than pivot
        while (arr[end] > pivot) {
            end--;
        }
        
        if (start < end) {
            // Swap elements at start and end indices
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    // Swap the pivot with the element at the final end index
    temp= arr[end];
    arr[end] = arr[lb];
    arr[lb] = temp;

    return end;  // Return the index of the pivot's final position
}

// Recursive function to perform Quick Sort
void quick_sort(int a[], int lb, int ub) {
    if (lb < ub) {
        int pivot = partition(a, lb, ub);
        // Recursively sort the left and right subarrays
        quick_sort(a, lb, pivot - 1);
        quick_sort(a, pivot + 1, ub);
    }
}

int main() {
    int n;
    //Inputing the size of array
    printf("Enter the size of the array:");
    scanf("%d", &n);
    
    int arr[n];
    // Inputing the elements of the array
    printf("Enter the elements of the array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    //Assigning values to lb and ub
    int lb = 0;
    int ub = n - 1;
    
    quick_sort(arr, lb, ub);  // Call the quicksort function to sort the array
    
    //Printing sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
