#include "stack.h"
#include "data_structures.h"
#include <iostream>
#include <vector>

using namespace std;

void push(STACK* s, NODE* v){
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
}


NODE* pop(STACK* s){
    if(s->top == nullptr){
        std::cout<<"The stack is empty"<<std::endl;
        return nullptr;
    }
    STACK_NODE* old = s->top;
    NODE* dat = s->top->ver;
    s->top = s->top->next;
    delete old; 
    return dat;
}
