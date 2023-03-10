#include<stdio.h> 
void swap(int a,int b,int arr[]){  
    int t = arr[a]; 
	arr[a] = arr[b]; 
	arr[b] = t;  
}
  
int partition(int arr[],int low,int high){     
	int pivot = arr[high];
	int i = (low-1);      
	int j;  
    for(j=low;j<=high-1;j++){         
		if(arr[j]<pivot){  
			i++;  
			swap(i,j,arr);  
        }  
    }  
	swap(i+1,high,arr);     
	return(i+1);  
}  

void quickSort(int arr[],int low,int high){
    if(low<high){  
        int pi = partition(arr,low,high);  
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);  
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
    quickSort(arr,0,n-1);
	printf("Sorted elements: ");     
	for(i=0;i<n;i++){  
		printf("%d ",arr[i]);  
    }  
	printf("\n");  
 	return 0;  
}  

