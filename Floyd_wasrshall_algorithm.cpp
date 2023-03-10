#include <stdio.h>  
#include <stdlib.h>  
#include <limits.h>  
#define MAX_VERTICES 1000  
  
int graph[MAX_VERTICES][MAX_VERTICES];  
int dist[MAX_VERTICES][MAX_VERTICES];   
int num_vertices,num_edges;
   
void get_user_input(){  
    int i,j,v,w;  
	printf("Enter the number of vertices: ");  
	scanf("%d", &num_vertices);  
  	printf("Enter the number of edges: ");  
	scanf("%d", &num_edges);  
    for(i=0;i<num_vertices;i++){         
		for(j=0;j<num_vertices;j++){  
            graph[i][j] = INT_MAX;  
        }  
    }  
    for(i=0;i<num_edges;i++){ 
		printf("Enter edge %d (v,w): ",i+1); 
		scanf("%d %d",&v,&w); 
		printf("Enter weight: ");  
		scanf("%d",&graph[v][w]);  
    }  
}  
  
// function to run Floyd-Warshall algorithm for all-pairs shortest path 
void floyd_warshall(){      
	int i,j,k;    
    // initialize distances with graph values     
	for(i=0;i<num_vertices;i++){         
		for(j=0;j<num_vertices; j++){  
			dist[i][j] = graph[i][j];  
        }  
    }  
    for(k=0;k<num_vertices;k++){         
		for(i=0;i<num_vertices;i++){             
			for(j=0;j<num_vertices;j++){  
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k]+dist[k][j] <dist[i][j]){ 
					dist[i][j] = dist[i][k] + dist[k][j];  
                }  
            }  
        }  
    }  
}
  
void print_shortest_path() {  
    int i,j;  
	printf("Shortest distance between all vertices:\n");     
	for(i=0;i<num_vertices;i++){         
		for(j=0;j<num_vertices;j++){             
			if(dist[i][j] == INT_MAX){ 
				printf("INF\t");             
			} 
			else{ 
				printf("%d\t", dist[i][j]);  
            }  
        }printf("\n");  
    }  
} 

int main(){ 
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n"); 
  	get_user_input(); floyd_warshall(); 
	print_shortest_path();
	printf("NOTE: Here 'INF' means Infinite\n");  
	return 0;
}  
  

