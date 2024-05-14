#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub) { // Merging the arrays
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int a[n1], b[n2]; // Initialising the temporary arrays

    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++)
        a[i] = arr[lb + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = lb;

    // Merge the two arrays back into the original array in sorted order
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of a[]
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements of b[]
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int lb, int ub) {  // splitting the array
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid); // Recursively calling the merge sort function
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub); // Calling the merge function
    }
}

int main() {
    int arr[100];
    int n;

    // Inputing the number of elements of array
    printf("Enter the number of elements of the array:");
    scanf("%d", &n);

    // Inputing the elements of the array
    printf("Enter the elements of the array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int lb = 0;
    int ub = n - 1;
    merge_sort(arr, lb, ub); // Calling the merge_sort function

    // Printing the sorted array
    printf("\nThe sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
