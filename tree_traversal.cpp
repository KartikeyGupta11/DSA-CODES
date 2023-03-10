#include<stdio.h> 
#include<stdlib.h> 

struct node{     
int data;     
struct node *left;     
struct node *right;  
};int idx=-1; 

struct node* insert(int A[]){ 
	idx++;     
	if(A[idx] == -1){         
		return 
        NULL;  
    }  
    struct node *temp;     
	temp = (struct node*)malloc(sizeof(struct node));     
	temp->data = A[idx];     
	temp->left=insert(A);     
	temp->right=insert(A);  
}
  
void inorder(struct node* root){      
	if(root==NULL){         
		return;  
    }  
	inorder(root->left); 
	printf("%d ",root->data); 
	inorder(root->right);  
}
  
void preorder(struct node* root){     
	if(root==NULL){         
		return;  
    }  
	printf("%d ",root->data); 
	preorder(root->left); 
	preorder(root->right);  
} 
 
void postorder(struct node* root){     
	if(root==NULL){         
		return;  
    }  
	postorder(root->left); 
	postorder(root->right); printf("%d ",root->data);  
}  

int main(){ 
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");    
	int nodes[]= {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};     
	struct node* root = insert(nodes); 
	printf("Inorder traversal: "); 
	inorder(root); 
	printf("\n");  
	printf("Preorder traversal: "); 
	preorder(root); 
	printf("\n"); 
	printf("Postorder traversal: "); 
	postorder(root);  
}  

