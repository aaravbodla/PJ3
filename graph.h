#ifndef _graph_cpp
#define _graph_cpp
#include "data_structures.h"

void initSingleSource(pVERTEX* V, int numVer, int source);
bool relax(pVERTEX u, pVERTEX v, double w);
void dijkistra(pVERTEX* V, int numver, int sourceVer, pNODE* adjList,int destination);
void initSinglePair(pVERTEX* V, int n, int source, int destination);
void printlength(int s, int t);
void printPath(int s, int t);

#endif