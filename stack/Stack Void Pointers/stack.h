//stack.h
#ifndef STACK_H
#define STACK_H

struct node{
	void *data;
	struct node *next;
};

struct Stack{
	struct node *top;
	int size;
};


void Push(struct Stack *stack, void *value);
void init(struct Stack *stack);

void print(struct Stack *stack);
void Pop(struct Stack *stack);

#endif
