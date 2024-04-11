#ifndef _heap_cpp
#define _heap_cpp
#include "data_structures.h"

extern int heapifycalls;
void buildHeap(HEAP*,int);
void heapify(HEAP*,int);
void extractMin(HEAP*);
void decreaseKey(HEAP*,int,double);
void insertion(HEAP*,double);
void printHeap(HEAP*);

#endif