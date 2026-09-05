//main.c

#include<stdio.h>
#include "doubly_list.h"

int main() {

    struct DoublyLinked list;
    init(&list);
    int value1 = 10;
    int value2 = 304;
    int value3 = 2001;
    addElement(&list, &value1);
    addElement(&list, &value2);
    addElement(&list, &value3);
    print(&list);

}
