#include <stdio.h>
#include <stdlib.h> 
#define max 100
struct stack{
  int top ;
  int arr[max] ;
};

struct node 
{ 
  int data; 
  struct node *next; 
}; 
void push(struct stack *s,int value){
  if(s->top==max-1) {
    printf("Overflow") ;
  }
  else {
    s->top=s->top + 1  ;
    s->arr[s->top]=value ;
    
  }
}
int stackempty(struct stack *s) {
  if(s->top==-1)
  return 1 ;
  else 
  return 0 ;
}
int pop(struct stack *s) {
  if(s->top==-1)
  printf("underflow") ;
  else {
  
  int temp=s->arr[s->top] ;
  s->top=s->top - 1 ;
  return s->arr[s->top];
}
}
void dfs(int *adj,int start,int visited[]) {
  int i,j,k ;
  struct node *head=NULL ;
  struct stack s ;
  s.top=-1 ;
  visited[start]=1 ;
  printf("%d " ,start) ;
  push(&s,start) ;
  while(!stackempty(&s)) {
      head=adj[start] ;
      // printf(" top - %d , element - %d\n",s.top,s.arr[s.top]);

      while(head!=NULL){
        if(visited[head->data]==0) {
      
        visited[head->data]=1 ;
        printf("%d" ,head->data) ;
        push(&s,head->data) ;
        start=head->data ;
        break ;
    }
    else {
      head=head->next ;
    }
    
    }
    if(head==NULL) {
      start=pop(&s) ;
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
  
  dfs(&adj_list_loc,start_vertex,visited_list) ;
}

