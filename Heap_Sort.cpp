#include <stdio.h>

void heapify(int arr[],int n,int i){     
	int largest = i;// Initialize largest as root     
	int l = 2 * i + 1; // left child = 2*i + 1     
	int r = 2 * i + 2; // right child = 2*i + 2     
	// If left child is larger than root     
	if(l<n && arr[l]>arr[largest]){
		largest = l;  
	}
    // If right child is larger than largest so far     
	if(r<n && arr[r]>arr[largest]){
		largest = r;  // If largest is not root   
	}      
	if(largest != i){         
		int temp = arr[i]; 
		arr[i] = arr[largest]; 
		arr[largest] = temp;  // Recursively heapify the affected sub-tree 
		heapify(arr,n,largest);  
    }
}
  
void heapSort(int arr[],int n) {     // Build heap (rearrange array)     
	for(int i=n/2-1;i>=0;i--){
		heapify(arr, n, i);	
	}   
    // One by one extract an element from heap     
	for(int i=n-1;i>=0;i--){         // Move current root to end         
		int temp = arr[0]; 
		arr[0] = arr[i]; 
		arr[i] = temp;  // call max heapify on the reduced heap  
		heapify(arr,i,0);  
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
 	 
	heapSort(arr, n);  
  	printf("Sorted elements: ");     
	for(i=0;i<n;i++){  
		printf("%d ",arr[i]);  
    }  
	printf("\n");
	return 0;
}

