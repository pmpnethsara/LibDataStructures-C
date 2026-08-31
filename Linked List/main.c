#include "list.h"

int main() {
    
    struct linkedList list;
    init(&list);
    int value1 = 124;
    int value2 = 873;
    int value3 = 4070;

    addElement(&list, &value1);
    addElement(&list, &value2);
    addElement(&list, &value3);

    print(&list);

    addAtBeginning(&list, &value3);
    print(&list);
    
    addAtEnd(&list, &value2);
    print(&list);

    cleanMemory(&list);
    return 0;
}
