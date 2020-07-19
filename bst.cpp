#include <stdio.h>
struct node{
  struct node* left ;
  struct node* right ;
  int data ;
};
struct node* rootNode=NULL ;
void deleteRoot() {
  
}
void search(struct node* Node,int ele) {
    if(Node==NULL) {
      printf("Element is not present") ;
      return ;
    } 
    if(ele==Node->data) { 
    printf("found") ;
    return ;
    }
    else if(ele < Node->data) {
      search(Node->left , ele) ;
    }
    else if(ele > Node->data) {
      search(Node->right , ele) ;
    }
  }

void postorder(struct node *Node) {
  if(Node==NULL) 
  return ;
  postorder(Node->left) ;
 
  postorder(Node->right) ;
  printf("%d" ,Node->data) ;


}
void preorder(struct node *Node) {
  if(Node==NULL)
    return ;
  printf("%d" ,Node->data) ;
  preorder(Node->left) ;
  preorder(Node->right) ;
  
}
void inorder(struct node *Node) {
  if(Node==NULL)
    return ;
    inorder(Node->left) ;
    printf("%d" ,Node->data) ;
    inorder(Node->right) ;
  
  
}
struct node* newnode(int item) {
  struct node* newNode=(struct node*)malloc(sizeof(struct node)) ;
  newNode->data=item ;
  newNode->left = newNode->right =NULL ;
  return newNode ;
}
struct node* insert(struct node *Node,int x) {
  if (Node==NULL) {
    
    return newnode(x) ;

  }
  else {
    if(x < Node->data){
      Node->left=insert(Node->left,x) ;
    }
    else{
      Node->right=insert(Node->right,x) ;
    }
  }
  return Node ;
}
int main(){
  int i,choice,value,element ;
  choice=1 ;
  while(choice) {
    printf("Enter your choice") ;
    scanf("%d" ,&choice) ;
    switch(choice) {
      case 1:
      printf("enter the data") ;
      scanf("%d" ,&value) ;
      if(rootNode==NULL)
      rootNode=insert(rootNode,value) ;
      else{
        insert(rootNode,value) ;
      }
      break ;
      case 2 :
      inorder(rootNode) ;
      break ;

      case 3 :
      preorder(rootNode) ;
      break ;
      case 4 :
      postorder(rootNode) ;
      break ;

      case 5 :
      printf("Enter the element you want to search") ;
      scanf("%d" ,&element) ;
      search(rootNode,element) ;
      break ;
      
      case 6 :
      deleteRoot() ;
      

    }

  }
 
}
