#include "list.h"

int main() {
    
    struct linkedList list;
    init(&list);
    int value1 = 12;
    int value2 = 42;
    int value3 = 43;

    addElement(&list, &value1);
    addElement(&list, &value2);
    addElement(&list, &value3);
    print(&list);
    cleanMemory(&list);
    return 0;
}
