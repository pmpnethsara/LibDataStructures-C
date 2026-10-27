//queue.h
#ifndef QUEUE_H
#define QUEUE_H

struct node{
	void *data;
	struct node *next;
};

struct Queue{
	struct node *front;
	struct node *rear;
	int size;
};

void init(struct Queue *queue);
void Enqueue(struct Queue *queue, void *value);
void print(struct Queue *queue);
void Dequeue(struct Queue *queue);

#endif
