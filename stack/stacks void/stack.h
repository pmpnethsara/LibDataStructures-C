#ifndef STACK_H
#define STACK_H

#include<stdbool.h>
#include <stddef.h>


typedef struct{
    void** data;
    size_t top;
    size_t capacity;
}Stack;

typedef enum{ TYPE_INT,
    TYPE_DOUBLE,
    TYPE_STRING
}ValueType;

typedef struct {
    ValueType type;
    union {
            int i_val;
            double d_val;
            char* s_val;
        } data;
} DataElement;

Stack* createstack(size_t in_capacity);
void freestack(Stack *st);
bool stackpush(Stack *st,void *value);
bool isstackempty(Stack *st);
size_t stack_size(Stack *st);
size_t stack_capacity(Stack *st);
void* stack_pop(Stack *st);
void* stack_peek(Stack *st);
DataElement* create_DE_int(int value);
DataElement* create_DE_double(double value);
DataElement* create_DE_string(char* value);

#define create_DE(val) _Generic((val), \
    int: create_DE_int, \
    double: create_DE_double, \
    char*: create_DE_string, \
    const char*: create_DE_string \
)(val)

#endif