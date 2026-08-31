#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void addElement(struct linkedList *list, int *value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = *value;
    newnode->next = NULL;

    if (list->head == NULL) {
        list->head = newnode;
        list->tail = newnode;
    } else {
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

void print(struct linkedList *list) {
    struct node *temp1;

    temp1 = list -> head;

    while(temp1 != NULL) {

        printf("%d", temp1 -> data);
        temp1 = temp1 -> next;

    }

}
void init(struct linkedList *list) {

    list ->head = NULL;
    list ->tail = NULL;
    list ->ptr = addElement;

}

void cleanMemory(struct linkedList *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
