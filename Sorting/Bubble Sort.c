#include <stdio.h>

void Bubble_Sort(int arr[],int n){
    int temp;
    int result=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                result=1;
            }
        }
        if(result==0){
            printf("The entered array is already sorted\n");
        }
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

int main()
{
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

    Bubble_Sort(arr,n);
}