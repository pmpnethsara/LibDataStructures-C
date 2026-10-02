#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


Stack* createstack(size_t in_capacity){
    if(in_capacity==0)in_capacity=2;

    Stack *st=malloc(sizeof(Stack));
    if(!st){
        return NULL;
    }
    st->data=malloc(in_capacity*sizeof(void*));
    if(!st->data){
        free(st);
        return NULL;
    }
    st->top=0;
    st->capacity=in_capacity;
    return st;
}

void freestack(Stack *st){
    free(st->data);
    st->data=NULL;
    free(st);
    st=NULL;

}

bool stackpush(Stack *st,void *value){
    if(st->top>=st->capacity){
        size_t newcapacity=st->capacity*2;
        void **temp=realloc(st->data,newcapacity*sizeof(void*));
        if(!temp){
            return false;
        }
        st->data=temp;
        st->capacity=newcapacity;
    }
    st->data[st->top++]=value;
}

bool isstackempty(Stack *st){
    return st->top==0;
}

size_t stack_size(Stack *st){
    return st->top;
}

size_t stack_capacity(Stack *st){
    return st->capacity;
}

void* stack_pop(Stack *st){
    if(isstackempty(st)){
        printf("stack is empty\n");
        return NULL;
    }
     return st->data[--st->top];
}

void* stack_peek(Stack *st){
    if(isstackempty(st)){
        printf("stack is empty\n");
        return NULL;
    }
    return st->data[st->top-1];
}

/*DataElement* create_intE(int value){
    DataElement *del=malloc(sizeof(DataElement));
    del->type=TYPE_INT;
    del->data.i_val=value;
    return del;
} 

DataElement* create_doubleE(double value){
    DataElement *del=malloc(sizeof(DataElement));
    del->type=TYPE_DOUBLE;
    del->data.d_val=value;
    return del;
} 

DataElement* create_stringE(char* value){
    DataElement *del=malloc(sizeof(DataElement));
    del->type=TYPE_STRING;
    del->data.s_val=value;
    return del;
} */
DataElement* create_DE_int(int value){
    DataElement *del=malloc(sizeof(DataElement));
    del->type=TYPE_INT;
    del->data.i_val=value;
    return del;
} 

DataElement* create_DE_double(double value){
    DataElement *del=malloc(sizeof(DataElement));
    del->type=TYPE_DOUBLE;
    del->data.d_val=value;
    return del;
} 

DataElement* create_DE_string(char* value){
    DataElement *del=malloc(sizeof(DataElement));
    del->type=TYPE_STRING;
    del->data.s_val=value;
    return del;
} 

