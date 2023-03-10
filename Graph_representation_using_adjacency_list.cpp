#include <stdio.h>  
#include <stdlib.h>  
  
// structure to represent a node in adjacency list 
struct Node{     
	int vertex;     
	struct Node* next;  
};  
  
// structure to represent the graph using adjacency list 
struct Graph{  
    int V;              // number of vertices in graph     
	struct Node** adj;  // array of adjacency lists  
};  
  
// function to create a new node for adjacency list 
struct Node* createNode(int v){     
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->vertex = v; 
	newNode->next = NULL;     
	return newNode;  
}  
  
// function to create a graph with V vertices 
struct Graph* createGraph(int V){  
  	int i;  
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));     
	graph->V = V;      
	graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));     
	for(i=0;i<V;i++){
		graph->adj[i] = NULL;  
	}   
	return graph;  
}
  
  
// function to add an edge to the graph 
void addEdge(struct Graph* graph,int src,int dest){     
	struct Node* newNode = createNode(dest); 
	newNode->next = graph->adj[src];     
	graph->adj[src] = newNode;  
  
    // for undirected graph, add edge in other direction as well 
	newNode = createNode(src); 
	newNode->next = graph->adj[dest];     
	graph->adj[dest] = newNode;  
}  
  
// function to print the adjacency list representation of the graph 
	void printGraph(struct Graph* graph) {  
  	int i;  
    for(i=0;i<graph->V;i++){ 
		printf("Adjacency list of vertex %d -> ",i);         
		struct Node* temp = graph->adj[i];         
		while(temp){ 
			printf("%d -> ",temp->vertex);             
			temp = temp->next;  
        }  
		printf("NULL\n");  
    }  
}  
  
// function to take user input for edges and create the graph 
void createGraphFromInput(struct Graph* graph){     
	int src,dest,n,i;  
	printf("Enter the number of edges: "); 
	scanf("%d",&n);  
  	printf("Enter the edges (Source,Destination):\n");     
	for(i=0;i<n;i++){  
		scanf("%d %d",&src,&dest); 
		addEdge(graph,src,dest);  
    }  
}  
  
int main(){
	printf("Name: Kartikey Gupta \n");
	printf("Roll no.: 2100320120087 \n");     
	int V;   
	printf("Enter the number of vertices: "); 
	scanf("%d", &V);  
  	struct Graph* graph = createGraph(V); 
	createGraphFromInput(graph); 
	printGraph(graph);  
  	return 0;  
}  

