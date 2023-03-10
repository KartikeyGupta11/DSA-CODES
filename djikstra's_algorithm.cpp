#include <stdio.h>  
#include <stdlib.h>  
#include <limits.h>  
#define MAX_VERTICES 1000  
  
typedef struct{      
	int v;     
	int weight;  
}Edge;  
  
int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix 
int dist[MAX_VERTICES]; // distance from source vertex 
int visited[MAX_VERTICES]; // visited flag  
int num_vertices, num_edges; // number of vertices and edges  
  
// function to get user input 
void get_user_input(){  
    int i, j, v, w;  
	printf("Enter the number of vertices: ");
	scanf("%d", &num_vertices); 
	printf("Enter the number of edges: "); 
	scanf("%d", &num_edges);  
  
    // initialize graph with 0 weights     
	for(i=0;i<num_vertices;i++){         
		for(j=0;j<num_vertices;j++){             
			graph[i][j] = 0;  
        }  
    }  
  
    // get edges from user input     
	for(i=0;i<num_edges;i++){ 
		printf("Enter edge %d (v,w): ", i+1); 
		scanf("%d %d", &v, &w); 
		printf("Enter weight: "); 
		scanf("%d",&graph[v][w]);  
    }  
}  
  
// function to find the unvisited vertex with minimum distance 
int min_distance(){     
	int min = INT_MAX,min_index;      
	int i;  
    for(i=0;i<num_vertices;i++){         
		if(!visited[i] && dist[i] < min){             
			min = dist[i]; min_index = i;  
        }  
    }  
    return min_index;  
}  
  
// dijkstra's algorithm to find shortest path from source vertex 
void dijkstra(int source){     
	int i, j, u;  
  
    // initialize distances and visited flags     
	for(i=0;i<num_vertices;i++){ 
		dist[i] = INT_MAX;  
        visited[i] = 0;  
    }  
  
	dist[source] = 0;  
	for(i=0;i<num_vertices-1;i++){         	
		u = min_distance();         
		visited[u] = 1;  
        for(j=0;j<num_vertices;j++){             
			if(!visited[j] && graph[u][j] &&dist[u] != INT_MAX  &&dist[u]+graph[u][j] <dist[j]){ 
				dist[j] = dist[u] + graph[u][j];  
            }  
        }  
    }  
}  
  
// function to print the shortest path 
void print_shortest_path(int source){     
	int i;  
	printf("Vertex Distance from Source\n");     
	for(i=0;i<num_vertices;i++){ 
		printf("%d ->-> %d\n",i,dist[i]);  
    }  
}  
  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");     
	int source;  
    get_user_input();  
   	printf("Enter the source vertex: "); 
	scanf("%d", &source); 
	dijkstra(source); 
	print_shortest_path(source);  
  	return 0;  
} 

