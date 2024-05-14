#include <stdio.h>

int Binary_Search(int arr[],int n,int val,int lb,int ub){
   
    int mid=(lb+ub)/2;

    while(lb<=ub){
        if (val==arr[mid]){
            return mid;
        }
        else if(val>arr[mid]){
            return Binary_Search(arr,n,val,mid+1,ub);
        }
        else if(val<arr[mid]){
            return Binary_Search(arr,n,val,lb,mid-1);
        }
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

    int lb=0; 
    int ub=n-1;

    int temp=Binary_Search(arr,n,val,lb,ub);
    if (temp==-1){
        printf("The element %d is not found in the array",val);
    }
    else{
        printf("The element %d is found at index %d",val,temp);
    }
}