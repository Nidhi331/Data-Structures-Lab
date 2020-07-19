#include <stdio.h>
#define size 10 
struct queue{
  int front ;
  int rear ;
  int qarr[size] ;
};
struct node {
  int data ;
  struct node *next ;
};
void enqueue(struct queue *q,int element,int total) {
  if((q->rear+1)%size == q->front) {
    printf("queue is full") ;
  }
  else {
  q->qarr[q->rear]=element ;
  q->rear=(q->rear + 1)%size;
  total+=1 ; 
  }

  
}
void dequeue(struct queue *q,int total) {
  if(q->front > q->rear) {
    printf("Queue is empty") ;
  }
  else {
  int temp ;
  temp=q->qarr[q->front] ;
  q->front=(q->front+1) % size ;
  total=total-1 ;
  }
}
void display(struct queue *q) {
  for(int i=q->front ; i<=q->rear ; i++) {
    printf("%d" ,q->qarr[i]) ;
  }
}
int main() {
  int choice,value ;
  choice=1 ;
  int count=0 ;
  struct queue q ;
  q.front=0 ;
  q.rear=0;
  while(choice) {
    printf("Enter Your Choice") ;
    scanf("%d" ,&choice) ;
    switch(choice) {
      case 1 :
      printf("Enter the element to be pushed") ;
      scanf("%d" ,&value) ;

      
      enqueue(&q,value,count) ;
      break ;
      case 2 :
      dequeue(&q,count) ;
      break ;
      case 3 :
      display(&q) ;
      break ;
    


    }
  }
}


