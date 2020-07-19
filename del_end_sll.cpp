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
}
void del_end() {
	struct node *q ;
    if(!start) {
        return ;
    }
    else if(start->next==NULL){
        free(start) ;
        start=NULL ;
    }
    else {
        struct node *temp=start;
        while(temp->next !=NULL){
        	q=temp ;
        	temp=temp->next ;
		}
        q->next=NULL ;
        free(temp) ;
    }
}


void display() {
    struct node* temp ;
    temp=start ;
    while(temp !=NULL) {
        printf("%d " ,temp->data) ;
        temp=temp->next ;
    }   
}
int main() {
	int choice = 1;
    while(choice) {
        insert_end() ;
        printf("enter choice: ") ;
        scanf("%d" ,&choice) ;
    }
    del_end() ;
    display() ;
}

