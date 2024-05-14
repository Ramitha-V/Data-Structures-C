#include <stdio.h>

void Insertion_Sort(int arr[],int n){
    int key;
    int i,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
    
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;


        printf("The array after %d iteration:",i);
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");

    }

    printf("The sorted array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    printf("\n");

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        printf("Enter the element at index %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");

    Insertion_Sort(arr,n);
}