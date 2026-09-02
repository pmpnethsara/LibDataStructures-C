
#include "list.h"
int main() {
    
    struct linkedList list;
    init(&list);
    int value1 = 124;
    int value2 = 873;
    int value3 = 4070;
    int position = 2;
    int value4 = 200002;

    addElement(&list, &value1);
    addElement(&list, &value2);
    addElement(&list, &value3);

    print(&list);

    addAtBeginning(&list, &value3);
    print(&list);
    
    addAtEnd(&list, &value2);
    print(&list);

    addAtPosition(&list, &value4, position);
    print(&list);
    
    deleteAtBeginning(&list);
    print(&list);
    
    deleteAtEnd(&list);
    print(&list);
    
    deleteAtPosition(&list, position);
    print(&list);

    cleanMemory(&list);
    return 0;
}
