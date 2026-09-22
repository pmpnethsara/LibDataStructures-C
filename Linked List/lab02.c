#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList {
    struct Node* head;
};

struct LinkedList* createList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insertFront(struct LinkedList* list, int value) {
    if (list == NULL) return;
    
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    newNode->next = list->head;
    list->head = newNode;
}

void insertRear(struct LinkedList* list, int value) {
    if (list == NULL) return;
    
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAt(struct LinkedList* list, int position, int value) {
    if (list == NULL || position < 0) {
        printf("Invalid list or position.\n");
        return;
    }

    if (position == 0) {
        insertFront(list, value);
        return;
    }

    struct Node* current = list->head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;
    
    newNode->next = current->next;
    current->next = newNode;
}

void traverse(struct LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(struct LinkedList* list, int value) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }

    struct Node* temp = list->head;
    int position = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1;
}

int update(struct LinkedList* list, int oldValue, int newValue) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }

    struct Node* temp = list->head;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int deleteNode(struct LinkedList* list, int value) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }

    struct Node* temp = list->head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        list->head = temp->next;
        free(temp);
        return 1;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0;
    }

    prev->next = temp->next;
    free(temp);
    return 1;
}

int main() {
    struct LinkedList* myList = createList();

    printf("Initial List:\n");
    traverse(myList);

    printf("\nInserting 10, 20 at Rear and 5 at Front:\n");
    insertRear(myList, 10);
    insertRear(myList, 20);
    insertFront(myList, 5);
    traverse(myList);

    printf("\nInserting 15 at index 2:\n");
    insertAt(myList, 2, 15);
    traverse(myList);

    printf("\nSearching for 15:\n");
    int pos = search(myList, 15);
    if (pos != -1) printf("Found at position: %d\n", pos);
    else printf("Not found.\n");

    printf("\nUpdating 15 to 100:\n");
    if (update(myList, 15, 100)) {
        traverse(myList);
    } else {
        printf("Update failed.\n");
    }

    printf("\nDeleting 100:\n");
    if (deleteNode(myList, 100)) {
        traverse(myList);
    } else {
        printf("Deletion failed.\n");
    }

    printf("\nDeleting Head (5) and Tail (20):\n");
    deleteNode(myList, 5);
    deleteNode(myList, 20);
    traverse(myList);

    free(myList);
    return 0;
}