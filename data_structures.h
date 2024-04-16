#ifndef _data_structures_h
#define _data_structures_h 1
#include <vector>

typedef struct COLOR{
    char color;//color for vertex
}COLOR;

typedef struct TAG_VERTEX{
    int index;
    COLOR color; // color for discovered undiscovered 
    double distance; //
    int previous;
    int position;
    int heappos;
}VERTEX;
typedef VERTEX *pVERTEX;


typedef struct TAG_NODE{
    int index; //position
    int u; //start
    int v; //end
    double w; //weight
    TAG_NODE *next;
}NODE;
typedef NODE *pNODE;

typedef VERTEX ELEMENT;
typedef ELEMENT *pELEMENT;

typedef struct TAG_HEAP{
    int capacity;
    int size;
    pELEMENT *A;
}HEAP;



typedef struct TAG_STACK_NODE {
    VERTEX* ver;
    TAG_STACK_NODE* next;
} STACK_NODE;

typedef struct TAG_STACK {
    STACK_NODE** S; // Array of Stack nodes
    STACK_NODE* top; // Pointer to the top of the stack
    int size;        // Current size of the stack
} STACK;

#endif