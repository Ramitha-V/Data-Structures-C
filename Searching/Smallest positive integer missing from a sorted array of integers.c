//Write a C program to find the smallest missing positive integer from a sorted array of integers. 
// The array may contain duplicates and negative numbers, but it is guaranteed to be sorted in ascending order.

#include <stdio.h>

int FindMissingInteger(int arr[],int n){


    //To find missing integers
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            int val=arr[i]+1;
            if(arr[i+1]==val){
                continue;
        }
            else{
                printf("%d is the smallest missing integer",val);
                break;
        }
        }
        else{
            continue;
        }
    }
    return 0;
        

}   
    

int main(){
    int n;
    printf("Enter the length of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the list of numbers in asecending order and even duplicates:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    FindMissingInteger(arr,n);
}