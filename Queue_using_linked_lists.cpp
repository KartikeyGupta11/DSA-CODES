#include<stdio.h> 
#include<stdlib.h>  
struct node{    
	int data;  
	struct node *next;  
};  
struct node *front=0,*rear=0;
  
void enqueue(){  
    int x;  
	printf("Enter an element: "); 
	scanf("%d",&x);     
	struct node *newnode; 
	newnode=(struct node *)malloc(sizeof(struct node));  
	newnode->data=x; 
	newnode->next=NULL; 
	if(front == NULL && rear == NULL)  
    front = rear = newnode;  
    else{  
        rear->next=newnode;          
		rear=newnode;  
    }  
}
  
void display(){     
	struct node *temp;     
	temp=front;     
	if(front == 0){  
		printf("Queue is empty\n");  
    }  
	else{         
		while(temp!=NULL){ 
			printf("%d ",temp->data);  
            temp=temp->next;  
        } 
		printf("\n");	 
    }  
}
  
void dequeue(){     
	struct node *temp;     
	temp=front;     
	if(front==0){  
		printf("Queue is empty\n");  
    }  
	else{  
		printf("%d is deleted \n",front->data);  
        front=front->next;          
		free(temp);  
    }  
}  

int main(){ 
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n"); 
  	int choice; 
	while(choice != 4){  
		printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");  
		printf("Enter your choice: "); 
		scanf("%d",&choice);  
    	switch(choice){                                                
			case 1:        
				enqueue();                                         
				break;                                                 
			case 2:        
				dequeue();                                         
				break;                                                 
			case 3:        
				display();                                         
				break;                                                 
			case 4:        
				printf("THANKYOU \n");                                         
				break;                       
        	default:       
				printf("Please enter a suitable choice \n");                                         
				break;  
        }          
	}          
	return 0;  
}  
  

