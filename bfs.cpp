#include <stdio.h>
#include <stdlib.h> 
#define max 10

struct node 
{ 
  int data; 
  struct node *next; 
}; 
struct queue{
  int front ;
  int rear ;
  int arr[max] ;
};
int qempty(struct queue *q) {
  if(q->front > q->rear) 
  return 1 ;
  else 
  return 0 ;
}
void enqueue(struct queue *q,int start_v) {
  if(q->rear==max-1) {
    printf("Overflow") ;
  }
  else {
    q->arr[++q->rear]=start_v ;
  }

}
int dequeue(struct queue *q) {
  
  if(q->rear==-1 || q->front>q->rear) {
    printf("Underflow") ;
    

  }
  else {
    int p=q->arr[q->front] ;
    q->front++ ;
    return p ;
  }
} 
void bfs(int *adj,int start, int visited[]) {
  struct node *head=NULL ;
  struct  queue q ;
  int v ;
  q.front=0 ;
  q.rear=-1 ;
  visited[start]=1 ;
  printf("%d" ,start) ;
  enqueue(&q,start) ;
  while(!qempty(&q)) {
    v=dequeue(&q) ;
    head=adj[v] ;
    while(head != NULL) {
      if(visited[head->data]==0) {
        visited[head->data]=1 ;
        printf("%d" ,head->data) ;
        enqueue(&q,head->data);
      }
      head=head->next ;
    }
  }  
}


void append(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    struct node *last = *head_ref; 
  
    new_node->data  = new_data; 
  

    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 

    while (last->next != NULL) 
        last = last->next; 

    last->next = new_node; 
    return; 
} 


void printList(struct node *Node) 
{ 
  while (Node != NULL) 
  { 
     printf(" %d ", Node->data); 
     Node = Node->next; 
  } 
} 


int main(void) {
  
  /* Creating Graph using Adjacency list method */

  int i,n,j;
  printf("Enter Number of Vertices of GRAPH: ");
  scanf("%d",&n);

  /* To stored Adjacency list location of Vertices */
  int adj_list_loc[n]; 
  int visited_list[n] ;
  printf("\n\n");

  int con_count,con;
  for( i=0 ; i<n ; i++ ){

    printf("Enter number of connections of vertex %d : ",i);
    scanf("%d",&con_count);
    
    printf("Enter the connections of vertex %d : ",i);

    struct node* head = NULL; /* creating an empty head reference for new linked list */

    for( j=0 ; j<con_count ; j++ ){
      scanf("%d",&con); /* Connected vertex data to push into Linked list */

      append(&head, con);
    }

    adj_list_loc[i] = head; /* storing the linked list head reference of vertex i to array */
    
    printf("\n");
    
  }


  for( i=0 ; i<n ; i++ ){
    printf("Adjacency List of Vertex %d ----> ",i);
    printList(adj_list_loc[i]); /* Accesing the array index i will give linked list reference of vertex i */
    printf("\n");
  }
  for(i=0 ; i<n ; i++) {
    visited_list[i]=0 ;
  }
  int start_vertex ;
  printf("enter the starting vertex ") ;
  scanf("%d" ,&start_vertex) ;
  
  bfs(&adj_list_loc,start_vertex,visited_list) ;

}

