#ifndef STACK_H
#define STACK_H

#include<stdbool.h>
#include <stddef.h>

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
} StackElement;

typedef struct{
    size_t stack_capacity;
    size_t top;
    StackElement *stEarr;
    
}Stack;

Stack* creatstack(size_t capacity);
void freestack(Stack *st);
bool stackpush(Stack *st,StackElement ste);
bool isstackempty(Stack *st);
size_t stack_size(Stack *st);
size_t stack_capacity(Stack *st);
StackElement stackpopE(Stack *st);
StackElement stackpeakE(Stack *st);
StackElement create_SE_int(int value);
StackElement create_SE_double(double value);
StackElement create_SE_string(char* value);
int strip_int(StackElement ste);
double strip_double(StackElement ste);
char* strip_string(StackElement ste);
void stackpeekvale(Stack *st);

#define create_SE(val) _Generic((val), \
    int: create_SE_int, \
    double: create_SE_double, \
    char*: create_SE_string, \
    const char*: create_SE_string \
)(val)

#define STRIP_VALUE(stel)\
    ((stel).type==TYPE_INT? (stel).data.i_val:\
    (stel).type==TYPE_DOUBLE?(stel).data.d_val:\
    (stel).data.s_val)

#endif