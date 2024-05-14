//Binary Search
// first we compare the value with the middle element of the array and then if the element is same as the middle element we return the mid
// else if val greater than arr[mid] then we move to the right subarray
// else we move to the left subarray

#include <stdio.h>

int Binary_Search(int arr[],int n,int val){
    int lb=0; // index
    int ub=n-1; // index
    int mid=(lb+ub)/2; // floor of lb and ub. also index
    while(lb<=ub){
        if(val==arr[mid]){
            return mid;
        }
        else if(val<arr[mid]){
            ub=mid-1;
        }
        else if(val>arr[mid]){
            lb=mid+1;
        }
        mid=(lb+ub)/2;
    }
    return -1;
    
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

    int val;
    printf("Enter the value to be searched:");
    scanf("%d",&val);
    printf("\n");

    int temp=Binary_Search(arr,n,val);
    if (temp==-1){
        printf("The element %d is not found in the array",val);
    }
    else{
        printf("The element %d is found at index %d",val,temp);
    }
}