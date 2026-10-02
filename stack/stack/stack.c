#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

Stack* creatstack(size_t capacity){
    if(capacity==0){
        capacity=4;
    }
    Stack *st=malloc(sizeof(Stack));
    if(!st){
        printf("stack memory allocation failed\n");
        return NULL;
    }
    StackElement *stEarr=malloc(sizeof(StackElement)*capacity);
    if(!stEarr){
        printf("stack Element memory allocation failed\n");
        free(st);
        st=NULL;
        return NULL;
    }
    st->stack_capacity=capacity;
    st->stEarr=stEarr;
    st->top=0;
    return st;
}

void freestack(Stack *st){
    free(st->stEarr);
    st->stEarr=NULL;
    free(st);
    st=NULL;
}

bool stackpush(Stack *st,StackElement ste){
    if(st->top>=st->stack_capacity){
        size_t new_capacity=st->stack_capacity*2;
        StackElement *nstEarr=realloc(st->stEarr,sizeof(StackElement)*new_capacity);
        if(!nstEarr){
            return false;
        }
        st->stEarr=nstEarr;
        st->stack_capacity=new_capacity;
    }
    st->stEarr[st->top++]=ste;
    return true;
}

bool isstackempty(Stack *st){
    return st->top==0;
}

size_t stack_size(Stack *st){
    return st->top;
}

size_t stack_capacity(Stack *st){
    return st->stack_capacity;
}

StackElement stackpopE(Stack *st){
    if(isstackempty(st)){
        fprintf(stderr,"ERROR:stack underflow:stack empty\n");
        exit(EXIT_FAILURE);
    }
    return st->stEarr[--st->top];
}

StackElement stackpeakE(Stack *st){
    if(isstackempty(st)){
        fprintf(stderr,"ERROR:stack underflow:stack empty\n");
        exit(EXIT_FAILURE);
    }
    return st->stEarr[st->top-1];
}


StackElement create_SE_int(int value){
    StackElement sel;
    sel.type=TYPE_INT;
    sel.data.i_val=value;
    return sel;
} 

StackElement create_SE_double(double value){
    StackElement sel;
    sel.type=TYPE_DOUBLE;
    sel.data.d_val=value;
    return sel;
} 

StackElement create_SE_string(char* value){
    StackElement sel;
    sel.type=TYPE_STRING;
    sel.data.s_val=value;
    return sel;
} 

int strip_int(StackElement ste){
    if(ste.type!=TYPE_INT){
        fprintf(stderr,"ERROR:stack element is not int\n");
        exit(EXIT_FAILURE);
    }
    return ste.data.i_val;
}

double strip_double(StackElement ste){
    if(ste.type!=TYPE_DOUBLE){
        fprintf(stderr,"ERROR:stack element is not double\n");
        exit(EXIT_FAILURE);
    }
    return ste.data.d_val;
}
char* strip_string(StackElement ste){
    if(ste.type!=TYPE_STRING){
        fprintf(stderr,"ERROR:stack element is not string\n");
        exit(EXIT_FAILURE);
    }
    return ste.data.s_val;
}

void stackpeekvale(Stack *st){
    StackElement ste=stackpopE(st);
    switch(ste.type){
        case TYPE_INT:
            printf("Integer:%d\n",ste.data.i_val);
            break;
        case TYPE_DOUBLE:
            printf("Double:%d\n",ste.data.d_val);
            break;
        case TYPE_STRING:
            printf("String:%d\n",ste.data.s_val);
            break;
    }
}

