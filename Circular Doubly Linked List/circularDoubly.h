#ifndef LIST_H
#define LIST_H

struct node{
	void *data;
	struct node *prev;
	struct node *next;
};

struct circularDoubly{
	struct node *tail;
	int size;
};

void addElement(struct circularDoubly *list, void *value);
void memoryClean(struct circularDoubly *list);
void init(struct circularDoubly *list);
void addBeginning(struct circularDoubly *list, void *value);
void print(struct circularDoubly *list);
void addEnd(struct circularDoubly *list, void *value);

void addPosition(struct circularDoubly *list, void *value, int position);
void deleteBeginning(struct circularDoubly *list);
void deleteEnd(struct circularDoubly *list);
void deletePosition(struct circularDoubly *list, int position);
#endif
