#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int a ,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void Generate_random_array(int arr[],int size){
    for (int i = 0; i <size; i++) {
        arr[i] = rand() % 10000; // Generating random numbers between 0 and 999
    }
}

void bubble_Sort(int arr1[], int size) { //Bubble sort 
    int i, j;
    for (i = 0; i < size- 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                swap(arr1[j], arr1[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr2[],int size){ //Insertion sort
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr2[i];
        j = i - 1;

        while (j >= 0 && arr2[j] > key) {
            arr2[j + 1] = arr2[j];
            j = j - 1;
        }
        arr2[j + 1] = key;
    }
}
void selection_sort(int arr3[],int size){ //Selection sort
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr3[j] < arr3[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr3[i], arr3[min_idx]);
    }
}
int main(){
    
    int size=10000;
    int arr[size],arr1[size],arr2[size],arr3[size];
    
    //Generate a random array
    Generate_random_array(arr,size);

    // Copying arrays
    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    // Bubble Sort-time
    clock_t start = clock();
    bubble_Sort(arr1, size);
    clock_t end = clock();
    double time_taken_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds:\n", time_taken_bubble);

    //Insertion sort-time
    clock_t start1=clock();
    insertion_sort(arr2,size);
    clock_t end1=clock();
    double time_taken_insertion = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds:\n", time_taken_insertion);

    //Selection sort-time
    clock_t start2=clock();
    insertion_sort(arr3,size);
    clock_t end2=clock();
    double time_taken_selection = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    printf("Selection took %f seconds:\n", time_taken_selection);

    return 0;

}


