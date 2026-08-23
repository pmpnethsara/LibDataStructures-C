#ifndef LIST_H
#define LIST_H
    
struct node{
    int data;
    struct node *next;
};

struct node *head;
struct node *temp;

void addElement(struct node *newnode, int *value);
void print(struct node *list);

#endif
    
