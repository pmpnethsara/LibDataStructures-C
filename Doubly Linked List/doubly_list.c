//doubly_list.c

#include<stdio.h>
#include<stdlib.h>
#include "doubly_list.h"

void addElement(struct DoublyLinked *list, int *value){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode -> data = *value;
    newNode -> next = NULL;
    
    if(list -> head == NULL){

       list -> head = newNode;
       list -> tail = newNode;
       newNode -> prev = NULL;
    }
    else{
        list -> tail -> next = newNode;
        newNode -> prev = list -> tail;
        list -> tail = newNode;

    }
    list -> size++;


}

void init(struct DoublyLinked *list) {

    list -> head = NULL;
    list -> tail = NULL;
    list -> add = addElement;
    list -> size = 0;

}

void print(struct DoublyLinked *list) {
    
    struct node *currentNode = list -> head;
    while(currentNode != NULL) {
    
        printf("%d\n", currentNode -> data);
        currentNode = currentNode -> next;


    }

}

void insertAtBeginning(struct DoublyLinked *list, int *value){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = *value;
    newNode -> prev = NULL;
    newNode -> next = list -> head;
    list -> head -> prev = newNode;
    list -> head = newNode;
    list -> size++;

}

void insertAtEnd(struct DoublyLinked *list, int *value){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    list -> tail -> next = newNode;
    newNode -> prev = list -> tail;
    newNode -> next = NULL;
    newNode -> data = *value;

    list -> tail = newNode;

    list -> size++;


}

void insertAtPosition(struct DoublyLinked *list, int position, int *value){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *currentNode = list -> head;

    for(int i = 0; i < position - 1; i++) {

        currentNode = currentNode -> next;

    }
    newNode -> data = *value;
    newNode -> next = currentNode;
    newNode -> prev = currentNode -> prev;
    currentNode -> prev -> next = newNode;
    currentNode -> prev = newNode;

    list -> size++;


}

void insertAtAfterPosition(struct DoublyLinked *list, int position, int *value){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *currentNode = list -> head;

    for(int i = 0; i < position; i++) {

        currentNode = currentNode -> next;

    }
    newNode -> data = *value;
    newNode -> next = currentNode;
    newNode -> prev = currentNode -> prev;
    currentNode -> prev -> next = newNode;
    currentNode -> prev = newNode;

    list -> size++;


}
void memoryClean(struct DoublyLinked *list){

        struct node *currentNode = list -> head;

        while(currentNode != NULL){

            struct node *nextNode = currentNode -> next;
            free(currentNode);
            currentNode = nextNode;


        }
        list -> head = NULL;
        list -> tail = NULL;


}
