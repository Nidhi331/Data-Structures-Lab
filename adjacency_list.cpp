#include <stdio.h>
struct listNode{
	int vertextNo ;
	struct listNode *next ;
};
struct Graph{
	int v ;
	int e ;
	struct listNode *adj ;
};
struct Graph adjlist() {
	int i,x,y ;
	struct Graph *G ;
	struct listNode *t,*temp ;
	G=(struct Graph*)malloc(sizeof(struct Graph)) ;
	printf("enter  the number of nodes and edges") ;
	scanf("%d %d" ,&G->v ,&G->e) ;
	G->adj=(struct listNode*)malloc(sizeof(G->v * sizeof(struct listNode))) ;
	for(i=0 ; i<G->v ; i++) {
		G->adj[i]->vertexNo=i ;
		G->adj[i]->next=G->adj+1 ;
	}
	for(i=0 ; i<G->e ; i++) {
		printf("enter nodes which are connected") ;
		scanf("%d %d" ,&x,&y) ;
		temp=(struct listNode)malloc(sizeof(struct listNode)) ;
		temp->vertexNo=y ;
		temp->next=G->adj[x] ;
		t=G->adj[x] ;
		while(t->next!=G->adj[x]){
			t=t->next ;
		}
		t->next=temp ;
	}
	return(G) ;	
}


