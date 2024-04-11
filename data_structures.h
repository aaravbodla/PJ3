#ifndef _data_structures_h
#define _data_structures_h 1
#include <vector>


typedef struct TAG_VERTEX{
    int index;//to be used in heap
    COLOR color; // color for discovered undiscovered 
    double key; //
    int pi;
    int position;
}VERTEX;
typedef VERTEX *pVERTEX;

typedef struct COLOR{
    char color;//color for vertex
}COLOR;

typedef struct TAG_NODE{
    int index; //position
    int u; //start
    int v; //end
    double w; //weight
    TAG_NODE *next;
}NODE;
typedef NODE *pNODE;

typedef struct TAG_ELEMENT {
    double key;
    // other fields as you see fit
}ELEMENT;

typedef struct TAG_HEAP {
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */
    VERTEX** A; /* array of pointers to ELEMENT */
    // other fields as you see fit
}HEAP;


typedef struct TAG_STACK_NODE {
    NODE* ver;
    TAG_STACK_NODE* next;
} STACK_NODE;

typedef struct TAG_STACK {
    STACK_NODE* top; // Pointer to the top of the stack
    int size;        // Current size of the stack
} STACK;

#endif