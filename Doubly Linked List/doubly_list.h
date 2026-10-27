#ifndef DLIST_H
#define DLIST_H

struct node{
    void *data;
    struct node* next;
    struct node* prev;
};

struct DoublyLinked{
    struct node *head;
    struct node *tail;
    int size;
};

void addElement(struct DoublyLinked *list, void *value);

void init(struct DoublyLinked *list);
void print(struct DoublyLinked *list);
void insertAtBeginning(struct DoublyLinked *list, void *value);
void insertAtEnd(struct DoublyLinked *list, void *value);
void insertAtPosition(struct DoublyLinked *list, int position, void *value);
void insertAtAfterPosition(struct DoublyLinked *list, int position, void *value);
void deleteAtBeginning(struct DoublyLinked *list);
void deleteAtEnd(struct DoublyLinked *list);
void deleteAtPosition(struct DoublyLinked *list, int position);
void reverseList(struct DoublyLinked *list);
void memoryClean(struct DoublyLinked *list);

#endif
        
