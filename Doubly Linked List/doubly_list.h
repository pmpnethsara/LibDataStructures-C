#ifndef DLIST_H
#define DLIST_H

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct DoublyLinked{
    struct node *head;
    struct node *tail;
    int size;
    void (*add)(struct DoublyLinked*, int*);
};

void addElement(struct DoublyLinked *list, int *value);

void init(struct DoublyLinked *list);
void print(struct DoublyLinked *list);

#endif
        
