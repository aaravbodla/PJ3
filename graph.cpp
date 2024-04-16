#include <iostream>
#include <iomanip>
#include "graph.h"
#include "heap.h"
#include "stack.h"
#include <cmath> 
using namespace std;

int sourceVertex = 0;
int Destination = 0;
pVERTEX* listofvertex;
STACK* stack = new STACK; //new stack

void initSingleSource(pVERTEX* V, int numVer, int source) {
    // Initialize single source for Dijkstra's algorithm
    for (int i = 0; i < numVer; i++) {
        V[i]->distance = INFINITY; // Set initial key values to infinity
        V[i]->previous = -1; // Set initial predecessor to NIL
    }
    V[source-1]->distance = 0; // Set key of source vertex to 0
}

// u and v are pointers to the vertex and w is the weight of the edge between them.
bool relax(pVERTEX u, pVERTEX v, double w) {
    bool ifchanged = false;
    if (v->distance > u->distance + w) {
        ifchanged = true;
        v->distance = u->distance + w; // Update vertex v's distance
        v->previous = u->index; // Set vertex v's predecessor to the index of vertex u
    }
    return ifchanged;
}



void dijkistra(pVERTEX* V, int numver, int sourceVer, pNODE* adjList,int destination){
    sourceVertex = sourceVer;
    Destination = destination;

    HEAP* heap = new HEAP; // priority queue - min heap
    heap->capacity = numver;
    heap->size = 0;
    heap->A = new VERTEX*[heap->capacity];
    for(int i=0;i<heap->capacity;i++){
        heap->A[i] = new VERTEX;
    }
    stack->size = 0;
    stack->S = new STACK_NODE*[numver];
    // for(int i = 0; i < numver; i++) {
    //     stack->S[i] = new STACK_NODE; // Allocate memory for each stack node
    //     stack->S[i]->ver = new VERTEX; // Allocate memory for the vertex
    // }
    if(heap == NULL){
        printf("Error: Failed to allocate memory for HEAP.\n");
        return;
    }

    for(int i=0;i<numver;i++){
        insertion(heap,V[i]);
    }
    printf("here\n");
    while(heap->size!=0){
        pVERTEX newV = extractMin(heap);
        push(stack,newV);
        if(newV->index == destination) break;
        pNODE edge = adjList[newV->index-1]; 
        int nodecount = 1;
        while(edge->next!=NULL){
            edge = edge->next;
            nodecount++;
        }
        pNODE Edge = adjList[newV->index-1];
        for(int j= 0;j<nodecount;j++){
            fprintf(stdout,"Distance before relax: %lf\n",V[Edge->v-1]->distance);
            if(relax(newV,V[Edge->v-1],Edge->w)){
                decreaseKey(heap,V[Edge->v-1]->heappos,newV->distance + Edge->w);
            }
            fprintf(stdout,"Distance after relax: %lf\n",V[Edge->v-1]->distance);
            Edge = Edge->next;
        }
    }
    listofvertex = V;
    // STACK_NODE* newStackNode = stack->top;
    // for(int i=0;i<stack->size;i++){
    //     pVERTEX newVV = newStackNode->ver;
    //     fprintf(stdout,"Element %d in stack, %d\n",i,newVV->index);
    //     newStackNode = newStackNode->next;
    // }
}

void initSinglePair(pVERTEX* V, int n, int source, int destination) {
    for (int i = 0; i <n; i++) {
        if (i == source-1) {
            V[i]->distance = 0; // Set key of source vertex to 0
        } else {
            V[i]->distance = INFINITY; // Set initial key values to infinity
        }
        V[i]->previous = -1; // Set initial predecessor to NIL
    }
}

void printlength(int s, int t){
    fprintf(stdout,"Print length method called.\n");
    if(sourceVertex != s){
        fprintf(stdout,"This is wrong source vertex");
        return;
    }
    if(Destination!= t &&Destination!=0 ){
        fprintf(stdout,"This is wrong destination vertex");
        return;
    }
    if(Destination==0){
        if(listofvertex[t-1]->distance == INFINITY){
            printf("There is no path from %d to %d.\n",s,t);
        }
        else{
            printf("There is a path.");
            
            fprintf(stdout,"The of the shortest path from %d to %d is: %lf\n",s,t,listofvertex[t-1]->distance);
        }
    }else {
        fprintf(stdout,"The length of the shortest path from %d to %d is: %lf\n",s,t,listofvertex[t-1]->distance);
    }
}

void printPath(int s, int t){
    fprintf(stdout,"Print path method called.\n");
    if(sourceVertex != s){
        fprintf(stdout,"This is wrong source vertex");
        return;
    }
    if(Destination!= t &&Destination!=0 ){
        fprintf(stdout,"This is wrong destination vertex");
        return;
    }
    if(Destination==0){
        if(listofvertex[t-1]->distance == INFINITY){
            printf("There is no path from %d to %d.\n",s,t);
        }
        else{
            printf("There is a path.");
        }
    }else {
        fprintf(stdout,"The length of the shortest path from %d to %d is: %lf\n",s,t,stack->top->ver->distance);
    }
}