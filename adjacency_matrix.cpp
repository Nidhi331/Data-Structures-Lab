#include <stdio.h>
#include <stdlib.h>
struct Graph{
	int v ;
	int e;
	int **adj ;
};
struct Graph* adjMatrixOfGraph() {
	int u,v,i ;
	struct Graph *G=(struct Graph*)malloc(sizeof(struct node)) ;
	if(G) {
		printf("Memory loss") ;
		return ;
		
	}
	printf("Enter number of edges and nodes") ;
	scanf("%d %d" ,&G->u,&G->v) ;
	for (u=0 ; u<G->v ; u++){
		for(v=0 ; v<G->v ; v++) {
			G->adj[u][v]=0 ;
		}
	}
	printf("enter the pairs which is connected") ;
	scanf("%d %d" ,&u,&v) ;
	for (i=0 ; i<G->e ; i++ ){
		G->adj[u][v]=1 ;
		G->adj[v][u]=1 ;
	}
	return G ;
	
}
