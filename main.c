#include "list.h"
#include "list.c"

int main() {
    
    struct node list;
    init();
    int value1 = 12;
    int value2 = 42;

    addElement(&list, &value1);
    addElement(&list, &value2);
    print(&list);
    return 0;
}
