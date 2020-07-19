#include <stdio.h>
#include <stdlib.h>
struct node {
	int data ;
	struct node *next ;
};
int main() {
	struct node *start ,*temp,*t,*u,*p ;
	int i,n,element ,pos;
	printf("enter the no. of nodes") ;
	scanf("%d" ,&n) ;
	printf("ENTER THE ELEMENT") ;
	scanf("%d" ,&element) ;
	start=(struct node*)malloc(sizeof(struct node*)) ;
	start->data=element ;
	start->next=NULL ;
	temp=start ;
	p=start ;
	t=start ;
	
	for (i=2 ; i<=n ; i++) {
		printf("ENTER THE ELEMENT") ;
	    scanf("%d" ,&element) ;
		temp=(struct node*)malloc(sizeof(struct node*)) ;
		p->next=temp ;
		p->data=element ;
		p=p->next ;
		
}
printf("enter the position where u want to delete") ;
scanf("%d" ,&pos) ;
for(i=0 ; i<pos-1 ; i++) {
	t=t->next ;
	
}
u=t->next ;
t->next=u->next ;
u->next=NULL ;
free(u) ;
}












