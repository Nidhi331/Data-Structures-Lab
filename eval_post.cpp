#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 # define maxsize 100

int stack[maxsize] ;
int top=-1 ;
void push(int item)
 {

	 if(top >=maxsize -1)
	 {
		 printf("stack over flow");
		 return;
	 }
	 else
	 {
		 top = top + 1 ;
		 stack[top]= item;
	 }
 }

 int pop()
 {
	 int item;
	 if(top <0)
	 {
		printf("stack under flow");
	 }
	 else
	 {
		 item = stack[top];
		 top = top - 1;
		 return item;
	 }
 }

void eval_post(char expr[]){
	int i ;
	char ch ;
	int val ;
	int A,B ;
	for (i = 0 ; expr[i] != ')'; i++)
	{
		ch = expr[i];
		if (isdigit(ch))
		{
		 push(ch- '0') ;
			
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			A=pop() ;
			B=pop() ;
			switch(ch)
			
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}

	
			push(val);
		}
	}
	printf( " \n Result of expression evaluation : %d \n", pop()) ;
 }

int main(){
	int i ;
	char expr[20] ;
	printf("Enter the expression") ;
	scanf("%s" ,expr) ;
	eval_post(expr) ;
	return 0 ;
}
