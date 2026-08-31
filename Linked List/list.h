#ifndef LIST_H
#define LIST_H
    
struct node{
    int data;
    struct node *next;
};

struct linkedList{
    struct node *head;
    struct node *tail;
    void (*ptr)(struct linkedList *list, int *value);

};
void init(struct linkedList *list);
void addElement(struct linkedList *list, int *value);
void print(struct linkedList *list);
void print(struct linkedList *list);
void cleanMemory(struct linkedList *list);

#endif
    
