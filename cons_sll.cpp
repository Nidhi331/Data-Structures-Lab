#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node *next ;
};
int main() {
struct node *start ,*temp,*t,*p ;
int i,n,temp1,element;
printf("enter the no. of nodes") ;
scanf("%d" ,&n) ;
printf("ENTER THE ELEMENT") ;
scanf("%d" ,&element) ;
start=(struct node*)malloc(sizeof(struct node*)) ;
start->data=element ;
start->next=NULL ;
p=start;
t=start ;

for (i=2 ; i<=n ; i++) {
printf("ENTER THE ELEMENT") ;
   scanf("%d" ,&element) ;
temp=(struct node*)malloc(sizeof(struct node*)) ;
p->next=temp;
temp->data=element ;
p=p->next ;
}
for(i=1 ;i<=(n/2) ;i++ ) {
    struct node *u=t->next ;
    temp1=u->data ;
    u->data=t->data ;
    t->data=temp1 ;
    t=t->next->next ;
}
for(i=1 ; i<=n ; i++){
    printf("%d" ,start->data) ;
    start=start->next ;
}
}

