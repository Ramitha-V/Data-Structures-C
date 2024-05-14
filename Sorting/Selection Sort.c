#include <stdio.h>

void Selection_Sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }

        }
        int temp;
        if(min_index!=i){
            temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;

        }
        printf("\nThe array after %d passes is: ",i); // Printing the after each pass
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);

        }
    }
    printf("\nThe sorted array is:");
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

    Selection_Sort(arr,n);
}