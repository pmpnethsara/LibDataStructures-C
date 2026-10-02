#include<stdio.h>
#include "circularDoubly.h"

int main(){

	struct circularDoubly list;

	init(&list);

	int value1 = 34;
	int value2 = 76;
	int value3 = 814;
	int value4 = 77004;
	int value5 = 44995560;

	addElement(&list, value1);
	addElement(&list, value2);
	addElement(&list, value3);
	addElement(&list, value4);
	print(&list);

	addBeginning(&list, value4);
	print(&list);

	addEnd(&list, value3);
	print(&list);

	addPosition(&list, value5, 3);
	print(&list);

	deleteBeginning(&list);
	print(&list);

	deleteEnd(&list);
	print(&list);
	
	deletePosition(&list, 3);
	print(&list);
	memoryClean(&list);

}
