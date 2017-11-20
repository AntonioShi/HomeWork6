//
// Created by antonio on 17-11-19.
//

#ifndef HOMEWORK6_SEQSTACK_H
#define HOMEWORK6_SEQSTACK_H

#include <malloc.h>
#define MaxStackSize 50

typedef int DataType ;
typedef struct{
    DataType stack[MaxStackSize] ;
    int top ;
}SeqStack;

void StackInitiate(SeqStack *S){
    S->top = 0 ;
}

int StackNotEmpty(SeqStack S){
    if(S.top <= 0){
        return 0 ;
    }

    else return 1 ;
}


int StackPush(SeqStack *S, DataType x){
    //push the data into the stack
    if(S->top >= MaxStackSize){
        printf("FULL\n") ;
        return 0 ;
    }
    else{
        S->stack[S->top] = x ;
        S->top ++ ;
        return 1 ;
    }

}


int StackPop(SeqStack *S, DataType *x){
    if(S->top <= 0){
        printf("NULL \n") ;
        return 0 ;
    }
    else{
        S->top -- ;
        *x = S->stack[S->top] ;
        return 1 ;
    }
}


int StackTop(SeqStack S, DataType *x){
    if(S.top <= 0){
        printf("NULL \n") ;
        return 0 ;
    }
    else{
        *x = S.stack[S.top - 1] ;
        return 1 ;
    }
}




#endif //HOMEWORK6_SEQSTACK_H
