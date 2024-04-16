#ifndef _heap_cpp
#define _heap_cpp
#include "data_structures.h"

extern int heapifycalls;
void buildHeap(HEAP*,int);
void heapify(HEAP*,int);
pVERTEX extractMin(HEAP* h);
void decreaseKey(HEAP*,int,double);
void insertion(HEAP*,pVERTEX);
void printHeap(HEAP*);

#endif