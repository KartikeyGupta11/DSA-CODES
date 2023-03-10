#include <stdio.h>  
#define MAX_VERTICES 100  
  
int adj_matrix[MAX_VERTICES][MAX_VERTICES]; 
int num_vertices = 0;  
  
void add_edge(int u,int v){ 
	adj_matrix[u][v] = 1; 
	adj_matrix[v][u] = 1;  
}  
  
void user_input(){      
	int u,v;      
	char c;  
  	printf("Enter edges for the graph: ");     
	while(scanf("%d%c%d",&u,&c,&v) == 3){          
		if(u<0 || v<0 || u >= MAX_VERTICES || v >= MAX_VERTICES){ 
			printf("Invalid vertex\n");  
            continue;  
        }  
		add_edge(u, v);  
        if (c == '\n') break;  
    }  
 	num_vertices = u >v ? u + 1 : v + 1;  
}  
  
void print_graph(){ 
	printf("Adjacency matrix:\n");
	int i,j;     
	for(i=0;i<num_vertices;i++){         
		for(j=0;j<num_vertices;j++){ 
			printf("%d ",adj_matrix[i][j]);  
    	} 
	printf("\n");  
    }  
}  
  
int main(){ 
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");     
	user_input(); 
	print_graph();  
    return 0;  
}   

