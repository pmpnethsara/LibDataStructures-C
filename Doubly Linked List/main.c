//main.c

#include<stdio.h>
#include "doubly_list.h"

int main() {

    struct DoublyLinked list;
    init(&list);

    int value1 = 10;
    int value2 = 304;
    int value3 = 2001;
    int value4 = 5000;
    int position = 3;

    addElement(&list, &value1);
    addElement(&list, &value2);
    addElement(&list, &value3);
    print(&list);

    insertAtBeginning(&list, &value3);
    print(&list);
    printf("\n");

    insertAtEnd(&list, &value1);
    print(&list);
    printf("\n");

    insertAtPosition(&list, position, &value4);
    print(&list);
    printf("\n");
    insertAtAfterPosition(&list, position, &value4);
    print(&list);
}
