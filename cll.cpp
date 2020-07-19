#include <stdio.h>
#include <stdlib.h>
struct node {
    int data ;
    struct node* next ;
};
struct node* start=NULL ;
struct node* tail=NULL ;
void insert_beg()  {
    struct node *ptr ;
    ptr=(struct node*)malloc(sizeof(struct node*));
    int item ;
    printf("enter data which you want to insert") ;
    scanf("%d" ,&item) ;
    ptr->data=item ;
    if(start==NULL) {
        tail=ptr ;
    }
    ptr->next=start ;
    start=ptr ;
    return ;
}
void display() {
    struct node* temp ;
    tail->next=start ;
    temp=start ;
    while(temp->next != start) {
        printf("%d" ,temp->data) ;
        temp=temp->next ;
    }
    printf("%d" ,tail->data) ;
    return ;
    
}
void insert_end() {
    struct node* ptr ;
    ptr=(struct node*)malloc(sizeof(struct node)) ;
    int item ;
    printf("enter the item which u want to insert") ;
    scanf("%d" ,&item) ;
    if(start==NULL) {
      start=ptr ;
      tail=ptr ;
    }
    ptr->data=item ;
    ptr->next=NULL ;
    if(tail !=NULL)
      tail->next=ptr ;
    tail=ptr ;
    tail->next=start ;
}
void insert_pos() {
    int pos,item,i ;
    struct node *temp=start ,*q ;
    printf("enter the position where you want to insert") ;
    scanf("%d" ,&pos) ;
    printf("enter the data") ;
    scanf("%d" ,&item) ;
    for(i=0 ; i<pos-1 ; i++){
        temp=temp->next ;
    }
    struct node *ptr ;
    ptr=(struct node*)malloc(sizeof(struct node)) ;
    ptr->data=item ;
    q=temp->next ;
    temp->next=ptr ;
    ptr->next=q ;
}
void del_beg() {
	struct node *temp=start ;
	if(!start) {
		return ;
	}
	else if(!(start->next)){
		free(start) ;
	}
	else {
		start=start->next ;
		tail->next=start ;
		temp->next=NULL ;
		free(temp) ;
	}
}
void del_end() {
	struct node *temp=start,*q ;
	if(!start) {
		return ;
	}
	else if(!(start->next)){
		free(start) ;
	}
	else {
		while(temp->next!=start) {
			q=temp ;
			temp=temp->next ;
		}
		temp->next=NULL ;
		q->next=start ;
		free(temp) ;
	}
}
void del_pos() {
	int pos,i;
	printf("enter the position which you want to delete") ;
	scanf("%d" ,&pos) ;
	struct node *temp=start,*q ;
	for(i=0 ; i<pos-1 ; i++) {
		temp=temp->next ;
	}
	q=temp->next ;
	temp->next=q->next ;
	q->next=NULL ;
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
