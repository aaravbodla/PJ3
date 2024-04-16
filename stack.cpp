#include "stack.h"
#include "data_structures.h"
#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

void push(STACK* s, VERTEX* v){
    s->size++;
    STACK_NODE* newNode = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    newNode->ver = v;
    newNode->next = NULL;
    if(s->top == NULL){
        s->top = newNode;
    }else{
        newNode->next = s->top;
        s->top = newNode;
    }
    printf("Pushed into stack.\n");
}


VERTEX* pop(STACK* s){
    if(s->top == nullptr){
        std::cout<<"The stack is empty"<<std::endl;
        return nullptr;
    }
    STACK_NODE* old = s->top;
    VERTEX* dat = s->top->ver;
    s->top = s->top->next;
    s->size--;
    delete old; 
    return dat;
}
