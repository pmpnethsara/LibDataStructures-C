//queue.c
#include<stdio.h>
#include"queue.h"
#include<stdlib.h>

void init(struct Queue *queue){
	queue -> front = NULL;
	queue -> rear = NULL;
	queue -> size = 0;
}

void Enqueue(struct Queue *queue, void *value){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Memory Allocation is Failed\n");
		return;
	}
	else{
		newNode -> data = value;
		newNode -> next = NULL;

		if(queue -> front == NULL){
			queue -> front = newNode;
			queue -> rear = newNode;
		}
		else{
			queue -> rear -> next = newNode;
			queue -> rear = newNode;
		}

		queue -> size++;
	}
}

void print(struct Queue *queue){
	struct node *current = queue -> front;
	while(current != NULL){
		printf("%d\n", *(int*)(current -> data));
		current = current -> next;
	}
	printf("\n");
}

void Dequeue(struct Queue *queue){
	if(queue -> front == NULL){
		printf("Queue is Empty\n");
		return;
	}
	else if(queue -> front -> next == NULL){
		free(queue -> front);
		queue -> front = NULL;
	}
	else{
		struct node *temp = queue -> front;
		queue -> front = queue -> front -> next;
		free(temp);
		temp = NULL;
	}
}
