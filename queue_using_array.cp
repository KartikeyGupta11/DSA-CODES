#include<stdio.h>
#define n  

int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");  
    int queue[100],choice = 1,front = 0,rear = 0,i,x = 100;   
	printf("--------Queue primitive operations using Array---------\n"); 
	printf("Enter the size of queue: ");  
	scanf("%d",&x);  
	printf("1.Insertion \n2.Deletion \n3.Display \n4.Exit \n");     
	while(choice != 4){  
		printf("Enter the Choice: ");  
		scanf("%d",&choice);         
		switch(choice){          
			case 1:              
				if(rear==x){
					printf("Queue is Full\n");
				}             
				else{  
					printf("Enter any number: ");  
					scanf("%d",&queue[rear++]);  
            	}             
				break;         
			case 2:             
				if(front==rear){  
					printf("Queue is empty\n");  
            	}             
				else{  
					printf("Deleted Element is %d\n",queue[front++]);                  
					x++;
				}             		
				break;         
			case 3:            
				if(front==rear){
					printf("Queue is Empty \n"); 
				}            
				else{
					printf("Queue Elements are: ");  
					for(i=front;i<rear;i++){   
						printf("%d ",queue[i]);    
                }  
				printf("\n");               
				break;             
			case 4:  
				printf("THANKYOU \n");
				break;             
			default:  
				printf("Please Enter a valid choice");  
				break;
        	}  
    	}      
	}      
	return 0;  
}  

