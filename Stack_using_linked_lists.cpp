#include<stdio.h> 
#include<stdlib.h>

struct node{   
	int data; 
	struct node *next;  
};
struct node *top=0; 

void push(){      
	int x;  
	printf("Enter an element: "); 
	scanf("%d",&x);     
	struct node *newnode;  
	newnode = (struct node *)malloc(sizeof(struct node)); 
	newnode->data=x; 
	newnode->next=top;     
	top=newnode;  
}  
  
void display(){     
	struct node *temp;     
	temp=top;     
	if(top==0){  
		printf("Stack is empty \n");  
    }  
	else{          
		while(temp!=0){ 
			printf("%d ",temp->data);             
			temp=temp->next;  
        } 
		printf("\n"); 
    } 
}
	  
void pop(){     
	struct node *temp;     
	temp=top;     
	if(top==0){  
		printf("Stack is empty \n");  
    }  
	else{ 
		printf("%d is popped \n",top->data);         
		top=top->next;         
		free(temp);  
    }  
}  

int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");  
  	int choice;  
	while(choice != 4){  
		printf("1.Push \n2.Pop \n3.Display \n4.Exit \n"); 
		printf("Enter your choice: "); 
		scanf("%d",&choice);  
        switch(choice){                                                
			case 1:        
				push();                                         
				break;                                                 
			case 2:        
				pop();                                         
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

