#include<stdio.h>
#include "list.h"

void print(struct linkedList *list);
int main() {

struct linkedList list;
init(&list);

char songA[] = "Mal Pan Podak";
char songB[] = "Heal the World";
char songC[] = "Darck beach";

addAtPosition(&list, songA, 0);
addAtPosition(&list, songB, 1);
addAtPosition(&list, songC, 2);
deleteAtPosition(&list, 0);

print(&list);
cleanMemory(&list);

return 0;

}

void print(struct linkedList *list) {

    struct node *current = list -> head;

    while (current != NULL) {
        printf("%s\n", (char*)current -> data);
        current = current -> next;
    }
    printf("\n");
}