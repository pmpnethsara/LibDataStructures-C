#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(struct linkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void addElement(struct linkedList *list, void *value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;

    if (list -> head == NULL) {
        list -> head = newnode;
        list -> tail = newnode;
    } else {
        list -> tail -> next = newnode;
        list -> tail = newnode;
    }
    list -> size++;
}

void addAtBeginning(struct linkedList *list, void *value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = list->head;
    list -> head = newnode;

   
    if (list -> tail == NULL) {
        list -> tail = newnode;
    }

    list -> size++;
}

void addAtEnd(struct linkedList *list, void *value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;

    if (list -> head == NULL) {
        list -> head = newnode;
        list -> tail = newnode;
    } else {
        list -> tail -> next = newnode;
        list -> tail = newnode;
    }

    list -> size++;
}

void addAtPosition(struct linkedList *list, void *value, int position) {
    if (position < 0 || position > list -> size) {
        printf("Error: Position %d out of bounds (Size: %d)\n", position, list->size);
    } else if (position == 0) {
        addAtBeginning(list, value);
    } else if (position == list->size) {
        addAtEnd(list, value);
    } else {
        struct node *current = list -> head;
        for (int i = 0; i < position - 1; i++) {
            current = current -> next;
        }

        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode -> data = value;
        newnode -> next = current -> next;
        current -> next = newnode;
        list -> size++;
    }
}

void deleteAtBeginning(struct linkedList *list) {
    if (list->head == NULL) return;

    struct node *temp = list -> head;
    list -> head = list -> head -> next;
    
    if (list -> head == NULL) {
        list -> tail = NULL;
    }
    
    free(temp);
    list -> size--;
}

void deleteAtEnd(struct linkedList *list) {
    if (list->head == NULL) return;

    if (list->head == list->tail) { 
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        struct node *currentNode = list -> head;
        struct node *previousNode = NULL;
        
        while(currentNode -> next != NULL){
            previousNode = currentNode;
            currentNode = currentNode -> next;
        }
        
        previousNode -> next = NULL;
        list -> tail = previousNode; 
        free(currentNode);
    }
    list -> size--;                
}

void deleteAtPosition(struct linkedList *list, int position){
    if (position < 0 || position >= list -> size) {
        printf("Error: Position %d out of bounds (Size: %d)\n", position, list->size);
        return;
    }

    if (position == 0) {
        deleteAtBeginning(list);
    } else if (position == list -> size - 1) {
        deleteAtEnd(list);
    } else {
        struct node *currentNode = list -> head;
        struct node *previousNode = NULL;

        for(int i = 0; i < position; i++){
            previousNode = currentNode;
            currentNode = currentNode -> next;
        }
        
        previousNode -> next = currentNode -> next;
        free(currentNode);
        list -> size--;                
    }
}

void reverseList(struct linkedList *list) {
    struct node *previousNode, *currentNode, *nextNode;
    previousNode = NULL;
    currentNode = nextNode = list -> head;
    list -> tail = list -> head;
    
    while(currentNode != NULL) {
        nextNode = currentNode -> next;
        currentNode -> next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    list -> head = previousNode;
}

void cleanMemory(struct linkedList *list) {
    struct node *current = list -> head;

    while (current != NULL) {
        struct node *next = current -> next;
        free(current);
        current = next;
    }
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0;
}