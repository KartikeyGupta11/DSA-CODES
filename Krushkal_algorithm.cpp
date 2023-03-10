#include <stdio.h>  
#include <stdlib.h>  
#define MAX_EDGES 100  
  
typedef struct{      
	int u, v, weight;  
}Edge;  
  
int parent[MAX_EDGES];  
// Find the parent of a node in a disjoint-set 

int findParent(int node){     
	if(parent[node] == node){  
        return node;  
    }  
    return findParent(parent[node]);  
}  
// Merge two disjoint-sets 
void merge(int node1,int node2){  
    parent[findParent(node1)] = findParent(node2);  
}  
// Comparator function for sorting edges by weight 
int compareEdges(const void *a,const void *b){  
    Edge *edge1 = (Edge*)a;     
	Edge *edge2 = (Edge*)b;      
	return edge1->weight - edge2->weight;  
}  
// Kruskal's algorithm for finding the minimum cost spanning tree 
void kruskal(Edge edges[],int numEdges,int numNodes){  
    int mstWeight = 0,i;  
	qsort(edges,numEdges,sizeof(Edge),compareEdges); // Sort edges by weight     
	for(i=0;i<numNodes;i++){  
        parent[i] = i; // Initialize each node as a separate disjoint-set  
    }  
    for(i=0;i<numEdges;i++){          
		int u = edges[i].u;         
		int v = edges[i].v;  
        if(findParent(u) != findParent(v)){ // Check if adding this edge will create a cycle 
			merge(u, v);  
			mstWeight += edges[i].weight;  
        }  
    }  
	printf("Minimum cost spanning tree weight: %d\n", mstWeight);  
}  
// Main function  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");  
	int numNodes,numEdges;  
	printf("Enter the number of nodes: "); 
	scanf("%d", &numNodes); 
	printf("Enter the number of edges: "); 
	scanf("%d", &numEdges);     
	Edge edges[MAX_EDGES];     
	int i;  
	printf("Enter the edges (u,v):\n");     
	for(i=0;i<numEdges;i++){  
		scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].weight);  
    }  
	kruskal(edges,numEdges,numNodes);
	return 0;
}
