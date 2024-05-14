#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates a random array of specified size
void Generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Generating random numbers between 0 and 9999
    }
}

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
    temp = arr[end];
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

// Merges two sorted subarrays
void merge(int arr1[], int lb, int mid, int ub) {
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int a[n1], b[n2]; // Temporary arrays to hold subarray data

    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++)
        a[i] = arr1[lb + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr1[mid + 1 + j];

    int i = 0, j = 0, k = lb;

    // Merge the two arrays back into the original array in sorted order
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr1[k] = a[i];
            i++;
        } else {
            arr1[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of a[]
    while (i < n1) {
        arr1[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements of b[]
    while (j < n2) {
        arr1[k] = b[j];
        j++;
        k++;
    }
}

// Merge Sort algorithm
void merge_sort(int arr1[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(arr1, lb, mid); // Recursively calling the merge sort function
        merge_sort(arr1, mid + 1, ub);
        merge(arr1, lb, mid, ub); // Calling the merge function
    }
}

int main() {
    int size = 10000;
    int arr[size], arr1[size], arr2[size], arr3[size];

    // Generate a random array
    Generate_random_array(arr, size);

    // Copying arrays
    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int lb = 0;
    int ub = n - 1;

    // Merge sort
    clock_t start = clock();
    merge_sort(arr1, lb, ub);
    clock_t end = clock();
    double time_taken_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort %f seconds\n", time_taken_merge);

    // Quick sort
    clock_t start1 = clock();
    quick_sort(arr2, lb, ub);
    clock_t end1 = clock();
    double time_taken_quick = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("Quick Sort %f seconds\n", time_taken_quick);

    return 0;
}
