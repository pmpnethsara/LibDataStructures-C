#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node *createNode (int value)
{
    struct Node *newNode = malloc (sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;

    return newNode;
}

struct LinkedList
{
    struct Node*head;
    struct Node*tail;
    
};

struct LinkedList * createList()
{
    
    struct LinkedList *list = malloc(sizeof(struct LinkedList));

    list->head=NULL;
    list->tail=NULL;

    return list;
    
    
}

void insertFront(struct LinkedList* list, int value)
{
    struct Node* newNode = createNode(value);

    if (list->head==NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }

}

void traverse(struct LinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\nHead: %d", list->head->data);
    printf("\nTail: %d", list->tail->data);


    printf("\n\n");
}


void insertRear(struct LinkedList* list, int value)
{
    struct Node* newNode = createNode(value);

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}


void insertAt(struct LinkedList* list, int position, int value)
{
    if (position < 0)
    {
        printf("Invalid position\n");
        return;
    }

    // Insert at beginning
    if (position == 0)
    {
        insertFront(list, value);
        return;
    }

    // Find the node at position - 1
    struct Node* current = list->head;

    for (int i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    // Invalid position
    if (current == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    // Insert at end
    if (current == list->tail)
    {
        insertRear(list, value);
        return;
    }

    // Insert between two nodes
    struct Node* newNode = createNode(value);

    newNode->next = current->next;
    current->next = newNode;
}

int search(struct LinkedList* list, int value)
{
    struct Node* current = list->head;
    int position = 0;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return position;
        }

        current = current->next;
        position++;
    }

    return -1;
}

int update(struct LinkedList* list, int oldValue, int newValue)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        if (current->data == oldValue)
        {
            current->data = newValue;
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int deleteNode(struct LinkedList* list, int value)
{
    struct Node* current = list->head;
    struct Node* previous = NULL;

    while (current != NULL)
    {
        if (current->data == value)
        {
            // Deleting the first node
            if (previous == NULL)
            {
                list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            // Deleting the last node
            if (current == list->tail)
            {
                list->tail = previous;
            }

            free(current);
            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0;
}

int main()
{
    // Create the list
    struct LinkedList* list = createList();

    // Create nodes
    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);
    struct Node* node4 = createNode(40);
    struct Node* node5 = createNode(50);

    // Connect the nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    // Set head and tail
    list->head = node1;
    list->tail = node5;

    traverse(list);

    insertFront(list,70);
    traverse(list);

    insertRear(list,90);
    traverse(list);

    insertAt(list,4,78);
    traverse(list);

    int pos = search(list, 30);
    printf("Position : %d\n\n",pos);

    update(list, 30, 35);
    traverse(list);

    deleteNode(list, 40);
    traverse(list);



    return 0;
}

