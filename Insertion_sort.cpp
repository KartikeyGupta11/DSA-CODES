#include <stdio.h>  
  
void insertionSort(int arr[],int n){
    int i,j,key;     
	for(i=1;i<n;i++){
		key = arr[i];  
        j = i - 1;  
        while(j>=0 && arr[j]>key){
			arr[j + 1] = arr[j];  
    		j--;  
    	}  
	arr[j+1] = key;  
    }  
} 
 
int main(){  
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");
    int n,i;  
	printf("Enter the number of elements: ");
	scanf("%d",&n);  
    int arr[n];  
	printf("Enter the elements: ");     
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);  
	}  
    insertionSort(arr,n); 
	printf("Sorted array: ");     
	for(i=0;i<n;i++){
		printf("%d ", arr[i]);  
    }  
	printf("\n");  
    return 0;  
}  

