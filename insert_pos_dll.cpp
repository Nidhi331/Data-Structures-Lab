#include <stdio.h>
#include <stdlib.h>
struct node {
    int data ;
    struct node *next ;
    struct node *prev ;
};
struct node *head=NULL ;
struct node *tail=NULL ;
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
void display(){
    struct node *temp ;
    temp=head ;
    while(temp){
        printf("%d " ,temp->data) ;
        temp=temp->next ;
    }
}
void disp_back() {
  struct node *temp=tail ;
  while(temp) {
    printf("%d " ,temp->data) ;
    temp=temp->prev ;
  }
}
int main() {
    int choice=1 ;
    while(choice==1){
        insert_end() ;
        printf("Enter choice 0 or 1") ;
        scanf("%d" ,&choice) ;
    }
    
    insert_pos() ;
    display() ;
    disp_back() ;
}




