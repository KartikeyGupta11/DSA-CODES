#include <stdio.h>  
#include <stdlib.h>  
  
// Struct to represent a node in the linked list 
typedef struct Node {     
	int data;     
	int priority;     
	struct Node* next;  
}Node;  
  
// Function to create a new node  
Node* newNode(int data, int priority){      
	Node* node = (Node*)malloc(sizeof(Node));  
    node->data = data;     
	node->priority = priority;     
	node->next = NULL;     
	return node;  
}  
  
// Function to insert a new element into the priority queue 
void insert(Node** head,int data,int priority){     
	Node* node = newNode(data, priority);     
	if(*head == NULL || priority < (*head)->priority) {         
		node->next = *head;  
        *head = node;  
    }     
	else{  
        Node* temp = *head;         
		while (temp->next != NULL && temp->next->priority <= priority){             
			temp = temp->next;  
        }  
        node->next = temp->next;         
		temp->next = node;  
    }  
}  
  
// Function to delete the element with the highest priority from the priority queue 
void del(Node** head){     
	if(*head == NULL){ 
		printf("Queue is empty\n");         
		return;  
    }  
    Node* temp = *head;     
	*head = (*head)->next;     
	free(temp);  
}  
  
// Function to print the elements of the priority queue 
void printQueue(Node* head){ 
	printf("Priority queue: ");     
	while(head != NULL){ 
		printf("(%d, %d) ",head->data, head->priority);         
		head = head->next;  
    } 
	printf("\n");  
}  
  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");  
    Node* head = NULL;  
    int i,n,data,priority;  
	printf("Enter the number of elements to insert: "); 
	scanf("%d",&n);  
	printf("Enter the elements and their priorities as well:\n");     
	for(i=0;i<n;i++){ 
		scanf("%d %d", &data,&priority); 
		insert(&head, data, priority);  
    }  
	printQueue(head); 
	printf("After Deleting element having highest priority...\n");     
	del(&head);  
  	printQueue(head);  
	return 0;  
}  

