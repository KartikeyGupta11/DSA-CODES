#include<stdio.h> 
int front = -1,rear = -1; 
int max; int A[3]; 

void enqueue(){ 
	if(front == (rear+1)%max){ 
		printf("Circular queue overflow \n"); 
		return;  
	}  
	else{ 
		if(front==-1){ 
			front++;  
		}  
		printf("Enter an element: "); 
		rear = (rear+1)%max; scanf("%d",&A[rear]);  
	}  
}
  
void dequeue(){ 
	if(rear == front == -1){  
		printf("Circular queue underflow \n");  
	}  
	else{ 
		printf("Dequeued element is %d \n",A[front]); 
		front = (front+1)%max;  
	}  
}  

void display(){
	int i; 
	if(rear >= front){ 
		for(i=front;i<=rear;i++){ 
			printf("%d ",A[i]);  
		}
		printf("\n");  
	}  
	else{ 
		for(i=front;i<max;i++){
			printf("%d ",A[i]);
		}  
		for(i=0;i<=rear;i++){
			printf("%d ",A[i]); 
		}
		printf("\n");  
	}  
}

void circularqueue(){ 
	int n; 
	printf("1.Enqueue \n2.Dequeue \n3.Display \n");
	printf("Enter your choice: "); 
	scanf("%d",&n); 
	switch(n){    
		case 1: 
			enqueue();     
			break;    
		case 2: 
			dequeue();     
			break;    
		case 3: 
			display();     
			break;
	} 
	char m;
	fflush(stdin); 
	printf("Do You want to continue? \n");
	printf("Type 'y' to continue and press any key to exit: "); 
	scanf("%c",&m); 
	if(m == 'y' || m == 'Y'){ 
		circularqueue();  
	}  
	else{
		return;
	}  
}  

int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");
	printf("Enter the maximum size of circular queue: ");
	scanf("%d",&max);  
	circularqueue();  
	return 0;
}  
  

