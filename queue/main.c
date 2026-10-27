//main.c
#include<stdio.h>
#include"queue.h"

int main(){
	struct Queue queue;
	init(&queue);
	
	int value1 = 100;
	int value2 = 200;
	int value3 = 400;
	Enqueue(&queue, &value1);
	Enqueue(&queue, &value2);
	Enqueue(&queue, &value3);

	print(&queue);

	Dequeue(&queue);
	print(&queue);

}
