#include <stdio.h>

#include <stdlib.h>
struct node{
    int data ;
    struct node* next ;
};
struct node *start=NULL ;
struct node *tail=NULL ;
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


void display() {
    struct node* temp ;
    temp=start ;
    while(temp->next !=start) {
        printf("%d " ,temp->data) ;
        temp=temp->next ;
    }  
    printf("%d" ,temp->data) ;
}
int main() {
	int choice = 1;
    while(choice==1) {
        insert_end() ;
        printf("enter choice: ") ;
        scanf("%d" ,&choice) ;
    }
    del_pos() ;
    display() ;
}


