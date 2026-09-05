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


}

void init(struct DoublyLinked *list) {

    list -> head = NULL;
    list -> tail = NULL;
    list -> add = addElement;

}

void print(struct DoublyLinked *list) {
    
    struct node *currentNode = list -> head;
    while(currentNode != NULL) {
    
        printf("%d\n", currentNode -> data);
        currentNode = currentNode -> next;


    }

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
