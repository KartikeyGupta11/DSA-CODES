#include <stdio.h>  
#include <stdlib.h>  
  
// Structure for a node in the binary search tree 
struct Node{     
	int data;     
	struct Node* left;  
    struct Node* right;  
};  
  
// Function to create a new node with given data 
struct Node* newNode(int data){      
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));     
	temp->data = data;     
	temp->left = temp->right = NULL;  
    return temp;  
}  
  
// Function to insert a new node into the BST struct 
Node* insert(struct Node* root,int data){     
	if(root == NULL){  
    	return newNode(data);  
	}  
    if(data < root->data){  
        root->left = insert(root->left, data);  
    }  
    else if(data > root->data){          
		root->right = insert(root->right, data);  
    }      
	return root;  
}  
  
// Function to find the minimum node in the BST  
struct Node* findMin(struct Node* root){     
	while(root->left != NULL){          
	root = root->left;  
    }      
	return root;  
}  
  
// Function to delete a node from the BST 
struct Node* del(struct Node* root,int data){      
	if (root == NULL){          
		return root;  
    }  
    else if(data < root->data){  
        root->left = del(root->left, data);  
    }  
    else if(data > root->data){  
        root->right = del(root->right, data);  
    }      
	else{  
        // Case 1: node has no children          
		if(root->left == NULL && root->right == NULL){             
			free(root);  
            root = NULL;  
        }  
        // Case 2: node has one child         
		else if(root->left == NULL){             
			struct Node* temp = root;             
			root = root->right;  
        	free(temp);  
        }  
        else if(root->right == NULL){             
			struct Node* temp = root;             
			root = root->left;  
            free(temp);  
        }  
        // Case 3: node has two children         
		else{              
			struct Node* temp = findMin(root->right);             
			root->data = temp->data;              
			root->right = del(root->right, temp->data);  
        }      
	}  
    return root;  
}  
  
// Function to inorder traversal of BST 
void inorderTraversal(struct Node* root){  
    if(root != NULL){ 
		inorderTraversal(root->left); 
		printf("%d ",root->data);  
		inorderTraversal(root->right);  
    }  
}  
  
int main(){  
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");
    struct Node* root = NULL;  
    int i,n,data;  
	printf("Enter the number of nodes: "); 
	scanf("%d", &n);  
	printf("Enter the nodes: ");  
    for(i=0;i<n;i++){ 
		scanf("%d",&data);          
		root = insert(root, data);  
    }  
  	printf("Inorder traversal of the BST: "); 
	inorderTraversal(root);  
	printf("\n");  
	printf("Enter the node to delete: ");  
	scanf("%d", &data);      
	root = del(root, data);  
	printf("Inorder traversal of the BST after deletion: "); 
	inorderTraversal(root);  
	printf("\n");  
  	return 0;  
}  

