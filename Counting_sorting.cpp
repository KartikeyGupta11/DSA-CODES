#include<stdio.h> 
void countingSort(int arr[],int n,int range){     
	int count[range],output[n],i;     
	for(i=0;i<range;i++){
		count[i] = 0;      
	}      
	for(i=0;i<n;i++){
		count[arr[i]]++;  
    }      
	for(i=1;i<range;i++)
	{  
        count[i] += count[i-1];  
    }  
    for(i=n-1;i>=0;i--){         
		output[count[arr[i]]-1] = arr[i];         
		count[arr[i]]--;  
    }      
	for(i=0;i<n;i++){  
		arr[i] = output[i];  
    }  
}  
  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");     
	int n,i,max = 0; 
	printf("Enter the number of elements: "); 
	scanf("%d",&n);  
	int arr[n]; 
	printf("Enter the elements: ");     
	for(i=0;i<n;i++){ 
		scanf("%d",&arr[i]);          
		if(arr[i]>max){              
			max = arr[i];  
        }  
    }    
	countingSort(arr,n,max+1); 
	printf("Sorted Elements: ");     
	for (i=0;i<n;i++){  
		printf("%d ",arr[i]);
	}
	printf("\n");    
    return 0;  
}  

