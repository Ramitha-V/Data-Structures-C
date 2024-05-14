//Smallest positive integer missing from an unsorted array of integers

#include <stdio.h>

int FindMissingInteger(int arr[],int n){
    //Sorting an array
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
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
    printf("Enter the list of numbers:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    FindMissingInteger(arr,n);
}