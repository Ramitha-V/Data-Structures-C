#include <stdio.h>

int Linear_Search(int arr[],int n,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;


}
int main(){
    
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int val;
    printf("Enter the element to be searched:");
    scanf("%d",&val);
    int arr[n];
    
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp=Linear_Search(arr,n,val);
    if (temp==-1){
        printf("The element %d is not found",val);
    }
    else{
        printf("The element %d is found at index %d",val,temp);
    }
    return 0;
}