#include<stdio.h>
#include<stdlib.h>
#include "circularDoubly.h"

void init(struct circularDoubly *list){
    list -> tail = NULL;
    list -> size = 0;
}


void addElement(struct circularDoubly *list, int value){

    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
	printf("Allocation is failed \n");
	return;
    }

    newNode -> data = value;

    if(list -> tail == NULL){
	newNode -> next = newNode;
	newNode -> prev = newNode;
    }
    else{
	newNode -> prev = list -> tail;
	newNode -> next = list -> tail -> next;
	list -> tail -> next -> prev = newNode;
	list -> tail -> next = newNode;
    }
    list -> tail = newNode;

    list -> size++;
}

void memoryClean(struct circularDoubly *list){
    struct node *current = list -> tail -> next;
    struct node *temp;
    struct node *head = list -> tail -> next;
    do{
	temp = current -> next;
	free(current);
	current = temp;
    }while(current != head);

    list -> tail = NULL;
    list -> size = 0;


}
void addBeginning(struct circularDoubly *list, int value){

    if(list -> tail == NULL || list -> tail == list -> tail -> next){

	addElement(list, value);
    }

    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
	printf("Allocation is Failed\n");
	return;
    }
    else{
	newNode -> data = value;
	newNode -> next = list -> tail -> next;
	newNode -> prev = list -> tail;
	list -> tail -> next -> prev = newNode;
	list -> tail -> next = newNode;
	list -> size++;
    }
}

void addEnd(struct circularDoubly *list, int value){
	if(list -> tail == NULL){
		printf("List is Empty\n");
		return;
	}
	else if(list -> tail == list -> tail -> next){
		addElement(list, value);
	}

	else{
		struct node *newNode = malloc(sizeof(struct node));
		if(newNode == NULL){
			printf("Allocation is Failed\n");
			return;
		}
		newNode -> data = value;
		newNode -> prev = list -> tail;
		newNode -> next = list -> tail -> next;
		list -> tail -> next -> prev = newNode;
		list -> tail -> next = newNode;
		list -> tail = newNode;

		list -> size++;
	}
}

void addPosition(struct circularDoubly *list, int value, int position){
	if(position > list -> size){
		printf("Position is out of bound \n");
		return;
	}
	else if(position < 0){
		printf("Invalid Position\n");
		return;
	}
	
	else if(position == 1 || position == list -> size){
		addElement(list, value);
	}
	struct node *current = list -> tail -> next;
	struct node *newNode = malloc(sizeof(struct node));
		for(int i = 1; i < position - 1; i++){
			current = current -> next;
		}
		newNode -> data = value;
		newNode -> prev = current;
		newNode -> next = current -> next;
		current -> next = newNode;


	list -> size++;



}



void print(struct circularDoubly *list){
    struct node *current = list -> tail -> next;
    do{
	printf("%d\n", current -> data);
	current = current -> next;
    }while(current != list ->tail -> next);

    printf("\n\n");
}
