#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
char ch ;
int value ;
struct node {
	int data ;
	struct node *next ;
};
struct node *head ,*tail ;
struct node *new;
int main() {
do{
		new=(struct node*)malloc(sizeof(struct node)) ;
		scanf("%d" ,&value) ;
		new->data=value ;
		new->next=NULL ;
		if(head==NULL) {
			head=new ;
			tail=new ;
		}
		else{
			tail->next=new ;
			tail=new ;
		}
		printf("Y to continue and N to exit ") ;
		scanf("%c" ,&ch) ;
		
	}while(ch=='Y') ;
	struct node *temp ;
	temp=head ;
while(temp!=NULL) {
	printf("%d" ,temp->data) ;
	temp=temp->next ;
	}
}


