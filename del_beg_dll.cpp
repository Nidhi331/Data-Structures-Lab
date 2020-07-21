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
}
void display(){
    struct node *temp ;
    temp=head ;
    while(temp!= NULL){
        printf("%d" ,temp->data) ;
        temp=temp->next ;
    }
}
void del_beg() {
	struct node *temp=head ;
	struct node *q=temp->next ;
	temp->next =NULL ;
	q->prev=NULL ;
	head=q ;
	
}
/*void disp_back() {
  struct node *temp=tail ;
  while(temp) {
    printf("%d" ,temp->data) ;
    temp=temp->prev ;
  }
}*/
int main() {
    int choice=1 ;
    while(choice==1){
        insert_end() ;
        printf("Enter choice 0 or 1") ;
        scanf("%d" ,&choice) ;
    }
    del_beg() ;
    display() ;
    
}



