#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void addElement(struct node *newnode, int *value){
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = *value;
    newnode -> next = NULL;

    if(head == NULL){

        head = temp = newnode;

    }
    else
        temp -> next = newnode;
        temp = newnode;

}

void print(struct node *list) {

    temp = head;
    while(temp != NULL) {
        printf("%d", temp -> data);
        temp = temp -> next;

    }

}
void init() {

    head = NULL;
    temp = NULL;

}
