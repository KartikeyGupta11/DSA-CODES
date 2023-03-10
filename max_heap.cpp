#include <stdio.h>  
#include <stdlib.h>  
#define MAX_SIZE 100  
  
// Function to swap two elements 
void swap(int* x,int* y){     
	int temp = *x;     
	*x = *y;  
    *y = temp;  
}  
  
// Function to insert an element into the max heap 
void insert(int heap[],int* heapSize,int data){  
    // Check if heap is full     
	if(*heapSize == MAX_SIZE){ 
		printf("Heap is full\n");         
		return;      
	}  
    // Insert new element at the end of the heap     
	heap[*heapSize] = data;  
    (*heapSize)++;  
    // Bubble up the new element until the heap property is restored     
	int i = *heapSize - 1;     
	while(i>0 && heap[i] > heap[(i-1)/2]){         
		swap(&heap[i],&heap[(i-1)/2]); 
		i = (i-1)/2;  
    }  
}  
  
// Function to delete the root element from the max heap 
void deleteRoot(int heap[],int* heapSize){  
    // Check if heap is empty     
	if(*heapSize == 0){ 
		printf("Heap is empty\n");         
		return;  
    }  
    // Replace the root element with the last element in the heap 
	heap[0] = heap[*heapSize - 1];  
    (*heapSize)--;  
    // Bubble down the root element until the heap property is restored     
	int i = 0;     
	while(2*i+1 < *heapSize){         
		int j = 2*i+1;          
		if(j+1 < *heapSize&&heap[j+1] > heap[j]){ 
			j++;  
        }          
		if(heap[i] >= heap[j]){             
			break;  
        }  
        swap(&heap[i],&heap[j]);  
		i = j;     
	}  
}  
  
// Function to print the elements of the max heap 
void printHeap(int heap[],int heapSize){ 
	printf("Max heap: ");  
	int i;  
    for(i=0;i<heapSize;i++){ 
		printf("%d ", heap[i]);  
    }printf("\n");  
}  
  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");     
	int heap[MAX_SIZE];     
	int heapSize = 0;      
	int n,data;  
 	printf("Enter the number of elements to insert: "); 
	scanf("%d",&n);  
	int i;  
	printf("Enter the elements: ");     
	for(i=0;i<n;i++){ 
		scanf("%d",&data);  
		insert(heap,&heapSize, data);  
    }  
  	printHeap(heap,heapSize);  
  	printf("After Deleting root element...\n"); 
	deleteRoot(heap,&heapSize);  
  	printHeap(heap, heapSize);  
	return 0;
}
