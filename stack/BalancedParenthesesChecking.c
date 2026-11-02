#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack) {
        stack->top = NULL;
    }
    return stack;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) return '\0';
    struct Node* temp = stack->top;
    char popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

void freeStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(const char* exp) {
    struct Stack* stack = createStack();
    int i = 0;
    bool balanced = true;

    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(stack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(stack)) {
                balanced = false;
                break;
            }
            char topChar = pop(stack);
            if (!isMatchingPair(topChar, exp[i])) {
                balanced = false;
                break;
            }
        }
        i++;
    }

    if (!isEmpty(stack)) {
        balanced = false;
    }

    freeStack(stack);
    return balanced;
}

int main() {
    const char* testCases[] = {
        "(a+b)",
        "{[a+b]*(c-d)}",
        "((a+b)",
        "(a+b])",
        "[{()}]",
        "a+b)"
    };

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; i++) {
        if (isBalanced(testCases[i])) {
            printf("Input: %-20s Result: Balanced\n", testCases[i]);
        } else {
            printf("Input: %-20s Result: Not balanced\n", testCases[i]);
        }
    }

    return 0;
}