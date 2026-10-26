#include<stdio.h>
#include "circularDoubly.h"

//Onlychange the print function depending on the data type you choose 

int main(){

	struct circularDoubly list;

	init(&list);

	char value1[] = "The Stranger";
	char value2[] = "Kala Nadee Gala Basi";
	char value3[] = "White Tiger";
	char value4[] = "pitastharaya";
	char value5[] = "Bathtalangunduwa";

	addElement(&list, &value1);
	addElement(&list, &value2);
	addElement(&list, &value3);
	addElement(&list, &value4);
	print(&list);

	addBeginning(&list, &value4);
	print(&list);

	addEnd(&list, &value3);
	print(&list);

	addPosition(&list, &value5, 3);
	print(&list);

	deleteBeginning(&list);
	print(&list);

	deleteEnd(&list);
	print(&list);
	
	deletePosition(&list, 3);
	print(&list);
	memoryClean(&list);

}

