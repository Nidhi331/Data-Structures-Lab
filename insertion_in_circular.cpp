#include <stdio.h>
#include <stdlib.h>
struct node {
	int data ;
	struct node *next ;
};
int main() {
	struct node *start ,*temp,*p ;
	int i,n,element ;
	printf("enter the no. of nodes") ;
	scanf("%d" ,&n) ;
	printf("ENTER THE ELEMENT") ;
	scanf("%d" ,&element) ;
	start=(struct node*)malloc(sizeof(struct node*)) ;
	start->data=element ;
	start->next=NULL ;
	temp=start ;
	p=start ;
	for (i=2 ; i<=n ; i++) {
		printf("ENTER THE ELEMENT") ;
	    scanf("%d" ,&element) ;
		temp=(struct node*)malloc(sizeof(struct node*)) ;
		p->next=temp ;
		temp->data=element ;
		p=p->next ;
}
p->next=start ;
temp=(struct node*)malloc(sizeof(struct node*)) ;
p->next=temp ;
p=temp ;
p->next=start ;
}
