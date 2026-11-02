#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    int position;
    struct Node* next;
};

struct Node* createNode(char data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->position = position;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, char data, int position) {
    struct Node* newNode = createNode(data, position);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top, char* data, int* position) {
    if (*top == NULL) {
        return 0;
    }
    struct Node* temp = *top;
    *data = temp->data;
    *position = temp->position;
    *top = temp->next;
    free(temp);
    return 1;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void freeStack(struct Node** top) {
    while (*top != NULL) {
        struct Node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

void checkBalance(const char* expr) {
    struct Node* stack = NULL;
    int mismatchPos = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        int pos = i + 1;

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch, pos);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(stack)) {
                mismatchPos = pos;
                break;
            }
            char topChar;
            int topPos;
            pop(&stack, &topChar, &topPos);
            if (!isMatchingPair(topChar, ch)) {
                mismatchPos = pos;
                break;
            }
        }
    }

    if (mismatchPos != -1) {
        printf("Not Balanced - Position %d\n", mismatchPos);
    } else if (!isEmpty(stack)) {
        struct Node* temp = stack;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        printf("Not Balanced - Position %d\n", temp->position);
    } else {
        printf("Balanced\n");
    }

    freeStack(&stack);
}

int main() {
    char expr[1000];
    if (fgets(expr, sizeof(expr), stdin) != NULL) {
        size_t len = strlen(expr);
        while (len > 0 && (expr[len - 1] == '\n' || expr[len - 1] == '\r')) {
            expr[len - 1] = '\0';
            len--;
        }
        checkBalance(expr);
    }
    return 0;
}