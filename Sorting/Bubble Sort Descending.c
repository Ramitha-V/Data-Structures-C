// Descending order
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int result;

    for (int i = 0; i < n-1; i++) {
        result=0;
        for (int j = 0; j < n- i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                result= 1;
            }
        }
        printf("\nThe array after %d passes is ",i); // Printing the array after each pass
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }

        // No swapping since the elements are already swapped
        if (result==0) {
            break;
        }
    }
    printf("\nSorted array: "); //Printing the sorted array
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the elements of the array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    
}


