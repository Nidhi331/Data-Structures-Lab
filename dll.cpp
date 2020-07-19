#include <stdio.h>
#include <stdlib.h>
struct node {
    int data ;
    struct node *next ;
    struct node *prev ;
};
struct node *head=NULL ;
struct node *tail=NULL ;

void display(){
    struct node *temp ;
    temp=head ;
    while(temp){
        printf("%d" ,temp->data) ;
        temp=temp->next ;
    }
}
void insert_beg() {
    int item ;
    printf("enter the element you want to insert") ;
    scanf("%d" ,&item) ;
    struct node *ptr ;
    ptr=(struct node*)malloc(sizeof(struct node*)) ;
    ptr->data=item ;
    if(head==NULL){
        head=ptr ;
    }
    else{
        ptr->next=head ;
        head->prev=ptr ;
        head=ptr ;
    }
}
void insert_end() {
    int item ;
    printf("enter the element you want to insert") ;
    scanf("%d" ,&item) ;
    struct node *ptr ;
    ptr=(struct node*)malloc(sizeof(struct node)) ;
    ptr->data=item ;
    if(head==NULL){
        head=ptr ;
        ptr->prev=NULL ;
        ptr->next=NULL ;
        tail=ptr ;
    }
    else{
        tail->next=ptr ;
        ptr->prev=tail ;
        tail=ptr ;
        tail->next=NULL ;
    }
    return ;
}
void insert_pos() {
	struct node *ptr ;
	ptr=(struct node*)malloc(sizeof(struct node*)) ;
	struct node *temp=head,*q ;
	int pos,item,i ;
	printf("Enter the position where you want to insert") ;
	scanf("%d" ,&pos) ;
	printf("Enter the data to be inserted") ;
	scanf("%d" ,&item) ;
	for(i=0 ; i<pos-1 ; i++) {
		temp=temp->next ;		
	}
	ptr->data=item ;
	q=temp->next ;
	temp->next=ptr ;
	ptr->prev=temp ;
	ptr->next=q ;
	q->prev=ptr ;
}
void del_beg() {
	struct node *temp=head ;
	struct node *q=temp->next ;
	temp->next =NULL ;
	q->prev=NULL ;
	head=q ;
	
}
void del_end() {
	struct node *temp=head ,*q ;
	while(temp->next !=NULL) {
		q=temp ;
		temp=temp->next ;
	}
	q->next =NULL ;
	temp->prev=NULL ;
	free(temp) ;
	tail=q ;
}
void del_pos() {
	int pos,i ;
	struct node *temp=head ,*q ;
	printf("Enter the position which you want to delete") ;
	scanf("%d" ,&pos) ;
	for(i=0 ; i<pos-1 ; i++) {
		temp=temp->next ;
	}
	q=temp->next ;
	temp->next=q->next ;
	q->next->prev=temp ;
	q->next=NULL ;
	q->prev=NULL ;
	free(q) ;
}
int main() {
    int choice ;
    for(;;){
	
    printf("Enter your Choice :") ;
    scanf("%d" ,&choice) ;
    switch(choice) {
    	case 1 :
    		insert_end() ;
    		display() ;
    		break ;
    	case 2 :
			insert_beg() ;
			display() ;
			break ;
		case 3 :
		    insert_pos() ;
		    display() ;
		    break ;
	    case 4 :
	    	del_beg() ;
	    	display() ;
	    	break ;
	    case 5 :
		    del_end() ;
			display() ;
			break ;
		case 6:
			del_pos() ;
			display() ;
			break ;
	}
}
}









