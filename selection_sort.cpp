#include <stdio.h> 
void selectionSort(int arr[],int n){     
	int i,j,minIndex,temp;     
	for(i=0;i<n-1;i++){ 
		minIndex = i;
		for(j=i+1;j<n;j++){
		    if(arr[j]<arr[minIndex]){ 
				minIndex = j;  
            }  
        }  
        temp = arr[i]; 
		arr[i] = arr[minIndex]; arr[minIndex] = temp;  
    }
}  
int main(){  
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");
    int n,i;  
	printf("Enter the number of elements: ");
	scanf("%d",&n);  
    int arr[n];
	printf("Enter the Elements: ");     
	for(i=0;i<n;i++){  
		scanf("%d",&arr[i]);  
    }  
	selectionSort(arr,n);  
	printf("Sorted Elements: ");  
    for(i=0;i<n;i++){  
		printf("%d ",arr[i]);  
    }  
	printf("\n");  
    return 0;  
}  

