#include <stdio.h>  
#include <stdlib.h>  
  
// Definition of a node in the binary search tree 
typedef struct node{     
	int value;     
	struct node* left;     
	struct node* right;  
}node;  
  
// Function to create a new node 
node* new_node(int value){     
	node* new_node = (node*)malloc(sizeof(node)); 
	new_node->value = value; 
	new_node->left = NULL; 
	new_node->right = NULL;     
	return new_node;  
}
  
// Function to insert a node into the binary search tree 
node* insert(node* root,int value){     
	if(root == NULL){         
		return new_node(value);  
    }  
    if(value < root->value){  
        root->left = insert(root->left, value);     
	} 
	else if(value > root->value){         
		root->right = insert(root->right, value);  
    }  
    return root;  
}  
  
// Function to search for a value in the binary search tree 
node* search(node* root,int value){     
	if(root == NULL || root->value == value){         
		return root;  
    }      
	if(value < root->value){         
		return 
		search(root->left,value);  
    }  
    return search(root->right, value);  
}  
  
// Function to print the inorder traversal of the binary search tree 
void inorder_traversal(node* root){     
	if(root != NULL){ 
		inorder_traversal(root->left); 
		printf("%d ", root->value); 
		inorder_traversal(root->right);  
    }  
}  
  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n"); 	 
	node* root = NULL;     
	int i,n, value;  
	printf("Enter the number of elements to insert: ");  
	scanf("%d", &n);  
  	printf("Enter the elements: ");     
	for(i=0;i<n;i++){ 
		scanf("%d",&value);         
		root = insert(root, value);  
    }  
	printf("Inorder traversal of the binary search tree: "); 
	inorder_traversal(root); printf("\n");  
	printf("Enter a value to search for: "); 
	scanf("%d", &value);     
	node* result = search(root, value);    
 	if(result == NULL){  
		printf("Value not found\n");  
    }  
	else{  
		printf("Value found: %d\n", result->value);  
    }  
	return 0;
}  

