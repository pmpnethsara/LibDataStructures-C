#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(struct linkedList *list) {

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void addElement(struct linkedList *list, int *value) {

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = *value;
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

void addAtBeginning(struct linkedList *list, int *value) {

    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode -> data = *value;
    newnode -> next = list->head;
    list -> head = newnode;

    list -> size++;
}

void addAtEnd(struct linkedList *list, int *value) {

    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode -> data = *value;
    newnode -> next = NULL;

    list -> tail -> next = newnode;

    list -> size++;
}

void addAtPosition(struct linkedList *list, int *value, int position) {

    if (position < 0 || position > list -> size) {
        printf("Error: Position %d out of bounds (Size: %d)\n", position, list->size);
    }

    else if (position == 0) {
        addAtBeginning(list, value);
    }

    else if (position == list->size) {
        addAtEnd(list, value);
    }

    else{
        struct node *current = list -> head;
        for (int i = 0; i < position - 1; i++) {
            current = current -> next;
        }

        struct node *newnode = (struct node*)malloc(sizeof(struct node));

        newnode -> data = *value;
        newnode -> next = current -> next;
        current -> next = newnode;
        list -> size++;
    }
}

void print(struct linkedList *list) {

    struct node *current = list -> head;

    while (current != NULL) {
        printf("%d\n", current -> data);
        current = current -> next;
    }
    printf("\n");
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
