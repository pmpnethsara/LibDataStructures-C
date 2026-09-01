#ifndef LIST_H
#define LIST_H

struct node {
    int data;
    struct node *next;
};

struct linkedList {
    struct node *head;
    struct node *tail;
    int size;
};

void addElement(struct linkedList *list, int *value);
void init(struct linkedList *list);
void addAtBeginning(struct linkedList *list, int *value);
void addAtEnd(struct linkedList *list, int *value);
void addAtPosition(struct linkedList *list, int *value, int position);
void print(struct linkedList *list);
void deleteAtBeginning(struct linkedList *list);
void deleteAtEnd(struct linkedList *list);
void cleanMemory(struct linkedList *list);

#endif
    
