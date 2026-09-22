#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char title[100];
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode(const char* title) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newNode->title, title);
    newNode->next = NULL;
    return newNode;
}

struct LinkedList* createList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

void addSong(struct LinkedList* list, int position, const char* title) {
    if (list == NULL || position < 1) {
        printf("Invalid list or position.\n");
        return;
    }

    struct Node* newNode = createNode(title);
    if (newNode == NULL) return;

    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    struct Node* current = list->head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d exceeds playlist length. Adding to the end.\n", position);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeSong(struct LinkedList* list, int position) {
    if (list == NULL || list->head == NULL || position < 1) {
        printf("Invalid position or empty playlist.\n");
        return;
    }

    struct Node* temp = list->head;

    if (position == 1) {
        list->head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d not found in the playlist.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayPlaylist(struct LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("The playlist is empty.\n\n");
        return;
    }

    struct Node* temp = list->head;
    int index = 1;
    printf("Current Playlist:\n");
    while (temp != NULL) {
        printf(" %d. %s\n", index, temp->title);
        temp = temp->next;
        index++;
    }
    printf("\n");
}

int main() {
    struct LinkedList* playlist = createList();

    printf("Step 1: Add \"Song A\" at position 1\n");
    addSong(playlist, 1, "Song A");
    displayPlaylist(playlist);

    printf("Step 2: Add \"Song B\" at position 2\n");
    addSong(playlist, 2, "Song B");
    displayPlaylist(playlist);

    printf("Step 3: Add \"Song C\" at position 2\n");
    addSong(playlist, 2, "Song C");
    displayPlaylist(playlist);

    printf("Step 4: Remove the song at position 1\n");
    removeSong(playlist, 1);
    displayPlaylist(playlist);

    struct Node* current = playlist->head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    free(playlist);

    return 0;
}