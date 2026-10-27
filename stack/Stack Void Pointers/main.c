#include"stack.h"

int main(){

	int value1 = 10;
	int value2 = 20;
	int value3 = 30;
	struct Stack stack;
	init(&stack);
	Push(&stack, &value1);
	Push(&stack, &value2);
	Push(&stack, &value3);

	print(&stack);

	Pop(&stack);
	print(&stack);


}
