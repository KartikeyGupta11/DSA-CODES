#include<stdio.h> 
int stack[100],choice,n,top,x,i; 

void push(){     
	if(top >= n-1){  
    	printf("STACK is over-flow \n");  
    }     
	else{  
		printf("Enter a value to be pushed: ");  
		scanf("%d",&x);         
		top++;         
		stack[top]=x;
		printf("%d is pushed in stack \n",x);     
	}  
}  

void pop(){     
	if(top <= -1){  
		printf("Stack is under-flow \n");  
    }     
	else{  
		printf("%d is popped from the stack \n",stack[top]);          
		top--;  
    }  
}  

void display(){     
	if(top >= 0){  
		printf("The elements in STACK: ");  
		for(i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}   
		printf("\n");  
    }     
	else{  
		printf("The STACK is empty \n");  
    }  
} 

int peek(){  
    return stack[top];  
}  

int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");     
	top	=-	1;  
 	printf("Enter the size of STACK: "); 
	scanf("%d",&n);  
	printf("-------Stack primitive operations using array--------\n");  
	printf("1.PUSH \n2.POP \n3.DISPLAY \n4.PEEK \n5.EXIT \n");     
	do{  
		printf("Enter any Choice: "); 
		scanf("%d",&choice);          
		switch(choice){             
			case 1:{  
				push();  
                break;             
			}             
			case 2:{  
				pop();  
                break;             
			}             
			case 3:{  
				display();  
                break;             
			}              
			case 4:{  
				peek(); 
				printf("Element at the top of stack: %d \n",peek());  
                break;             
			}             
			case 5:{
				printf("THANKYOU \n");                  
				break;             
			}             
			default:{  
				printf("Please Enter a Valid Choice \n");  
            }  
        }  
    }  
    while(choice!=5);     
	return 0;  
}   


  

