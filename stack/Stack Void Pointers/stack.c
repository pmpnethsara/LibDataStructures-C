//stack.c
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void init(struct Stack *stack){
	stack -> top = NULL;
	stack -> size = 0;
}


void Push(struct Stack *stack, void *value){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Memory Allocation is Failed");
		return;
	}
	else{
		newNode -> data = value;
		if(stack -> top == NULL){
			newNode -> next = NULL; 
		}
		else{
			newNode -> next = stack -> top;	
		}

		stack -> top = newNode;
	}

}

void print(struct Stack *stack){

	struct node *currentNode = stack -> top;

	while(currentNode != NULL){
		printf("%d\n", *(int*)(currentNode -> data));
		currentNode = currentNode -> next;
	}
	printf("\n");
}

void Pop(struct Stack *stack){
	if(stack -> top == NULL){
		printf("Stack is Empty\n");
		return;
	}
	else{
		struct node *temp = stack -> top;
		stack -> top = stack -> top -> next;
		free(temp);
		temp = NULL;
	}
}
