#include <stdio.h>  
#include <stdlib.h>  
#include <limits.h>  
#define MAX_NODES 100  
  
typedef struct{     
	int weight;     
	int parent;     
	int visited;  
}Node;  
  
int minKey(Node nodes[],int numNodes){     
	int minWeight = INT_MAX;      
	int minIndex = -1;  
    int i;  
    for(i=0;i<numNodes;i++){  
        if(!nodes[i].visited && nodes[i].weight <minWeight){  
			minWeight = nodes[i].weight; minIndex = i;  
        }  
    }  
    return minIndex;  
} 
 
void prim(int graph[MAX_NODES][MAX_NODES],int numNodes){     
	Node nodes[MAX_NODES];  
    int i,v;  
    for(i=0;i<numNodes;i++){         
		nodes[i].weight = INT_MAX;  
        nodes[i].visited = 0;  
    }  
	nodes[0].weight = 0;
	nodes[0].parent = -1;     
	for(i=0;i<numNodes-1;i++){         
		int u = minKey(nodes,numNodes);         
		nodes[u].visited = 1;         
		for(v=0;v<numNodes;v++){  
            if(graph[u][v] && !nodes[v].visited && graph[u][v] < nodes[v].weight){                 
				nodes[v].weight = graph[u][v];                 
				nodes[v].parent = u;  
            }  
        }  
    }      
	int mstWeight = 0;     
	for(i=1;i<numNodes;i++){  
		mstWeight += nodes[i].weight;  
    }  
	printf("Minimum cost spanning tree weight: %d\n",mstWeight);  
}  
  
// Main function 
int main(){ 
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");    
	int numNodes;  
    int i,j;  
 	printf("Enter the number of nodes: "); 
	scanf("%d",&numNodes);      
	int graph[MAX_NODES][MAX_NODES]; 
	printf("Enter the adjacency matrix (u,v):\n");     
	for(i=0;i<numNodes;i++){         
		for(j=0;j<numNodes;j++){ 
			scanf("%d",&graph[i][j]);  
        }  
    }  
	prim(graph,numNodes);     
	return 0;
}

