#include <stdio.h>  
void radixSort(int arr[],int n){     
	int max = arr[0],i,exp = 1;     
	int output[n],count[10] = {0};     
	for(i=1;i<n;i++){         
		if(arr[i]>max){  
            max = arr[i];  
        }  
    }  
    while(max/exp > 0){         
		for(i=0;i<10;i++){  
            count[i] = 0;  
        }  
        for(i=0;i<n;i++){
		    count[(arr[i]/exp) % 10]++;  
        }  
        for(i=1;i<10;i++){  
            count[i] += count[i-1];  
        }  
        for(i=n-1;i>=0;i--){
			output[count[(arr[i]/exp) % 10] - 1] = arr[i];             
        	count[(arr[i]/exp) % 10]--;  
        }          
		for(i=0;i<n;i++){ 
			arr[i] = output[i];  
        }  
        exp *= 10;  
    }  
}  
  
int main(){  
	printf("Name: Kartikey Gupta \n");
	printf("Roll No.: 2100320120087 \n");
    int n,i;  
	printf("Enter the number of elements: "); 
	scanf("%d",&n);  
    int arr[n];  
	printf("Enter the elements: ");     
	for(i=0;i<n;i++){  
		scanf("%d",&arr[i]);  
    }  
    radixSort(arr,n);  
	printf("Sorted elements of  array: ");     
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);  
    }
	printf("\n");  
    return 0;  
}  

