#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"
#include "heap.h"
#include "graph.h"
#include <cmath> 
using namespace std;

int main(int argc, char **argv){
    FILE *fp = NULL;
    int ver1;
    int ver2;
    int returnV;
    char Word[100];
    int numVer=0;

    if (argc < 3){
        fprintf(stdout, "Usage: %s <inputfile> <Graphtype> <Flag>\n", argv[0]);
        exit(0);
    }
    //fp = fopen(argv[1],"r");
    ifstream file(argv[1]);
    if(file.is_open()){
        string line;
        int num1,num2;
        getline(file, line);
            istringstream iss(line);
                if (iss >> num1 >> num2) {
                    numVer = num1;
                }
    }
    fclose(fp);

    fp = fopen(argv[1],"r");
    pNODE *ADJ = new pNODE[numVer];
    for (int i = 0; i < numVer; i++) {
        ADJ[i] = NULL; // Allocate memory for each element
    }
    pVERTEX *vertexList = new pVERTEX[numVer];
    for(int i=0;i<numVer;i++){
        vertexList[i] = new VERTEX;
        vertexList[i]->index = i+1;
    }
    if(fp){
        string line2;
        int index,u,v;
        double w;
        while (getline(file, line2)) {
            istringstream iss(line2);
            iss >> index >> u >> v >> w;
            pNODE newEdge = new NODE;
            newEdge->index = index;
            newEdge->u = u;
            newEdge->v = v;
            newEdge->w = w;

                if(strcmp(argv[2], "DirectedGraph") == 0){
                    //directed
                    if(ADJ[u-1] == NULL){
                        //fprintf(stdout,"I was here ADJ[u] == NULL\n");
                        ADJ[u-1] = newEdge; // add the new edge to the front of the list
                    }else{
                        if(strcmp(argv[3], "1")==0){
                            // directed + flag 1
                                newEdge->next = ADJ[u - 1];
                                ADJ[u - 1] = newEdge; // Update head of the list
                                //fprintf(stdout,"flag 1 not NULL\n");
                        }else{
                            //directed + flag 2
                            pNODE loop = ADJ[u - 1];
                            while (loop->next != NULL) {
                                loop = loop->next;
                            }
                            loop->next = newEdge; // Add to the rear
                        }
                    }
                }else {
                    pNODE otherEdge = new NODE;
                    otherEdge->index = index;
                    otherEdge->v = u;
                    otherEdge->u = v;
                    otherEdge->w = w;

                    if (ADJ[u - 1] == NULL && ADJ[v - 1] == NULL) {
                    // Both vertices have empty adjacency lists
                    ADJ[u - 1] = newEdge;
                    ADJ[v - 1] = otherEdge;
                    } else if (ADJ[u - 1] == NULL && ADJ[v - 1] != NULL) {
                    // Vertex u has an empty adjacency list
                    ADJ[u - 1] = newEdge;
                    pNODE loop2 = ADJ[v - 1];
                        while (loop2->next != NULL) {
                            loop2 = loop2->next;
                        }
                        loop2->next = otherEdge;
                } else if (ADJ[u - 1] != NULL && ADJ[v - 1] == NULL) {
                // Vertex v has an empty adjacency list
                    ADJ[v - 1] = otherEdge;
                    pNODE loop = ADJ[u - 1];
                        while (loop->next != NULL) {
                           loop = loop->next;
                        }
                        loop->next = newEdge;
                } else {
                    // Both vertices have non-empty adjacency lists
                    if (strcmp(argv[3], "1") == 0) {
                        // Undirected with flag 1
                        newEdge->next = ADJ[u - 1];
                        ADJ[u - 1] = newEdge;

                        otherEdge->next = ADJ[v - 1];
                        ADJ[v - 1] = otherEdge;
                    } else {
                        // Undirected with flag 2
                        pNODE loop = ADJ[u - 1];
                        while (loop->next != NULL) {
                           loop = loop->next;
                        }
                        loop->next = newEdge;

                        pNODE loop2 = ADJ[v - 1];
                        while (loop2->next != NULL) {
                            loop2 = loop2->next;
                        }
                        loop2->next = otherEdge;
                    }
                }
            }
    }
    fclose(fp);
    while (1){

        returnV = nextInstruction(Word, &ver1, &ver2);
        //if the funtion returns 0 the instruction is invalid
        if (returnV == 0){
            printf("Warning: Invalid instruction\n");
            continue;
        }
        // end if STOP is entered
        if (strcmp(Word, "Stop")==0){
            return 0;
        }
        // print command is entered
        if (strcmp(Word, "PrintADJ") == 0) {  

    for (int i = 0; i < numVer; i++) {
        printf("ADJ[%d]:-->", i + 1);
        pNODE loop = ADJ[i];
        while (loop != NULL) {
            fprintf(stdout, "[%d %d: %f]", loop->u, loop->v, loop->w);
            loop = loop->next;
            if (loop != NULL) {
                fprintf(stdout, "-->");
            }
        }
        fprintf(stdout, "\n");
    }
    fclose(stdout);  // Close file after writing
    continue;    // Continue to the next iteration of the loop
}

        // SinglePair command is entered
        if(strcmp(Word, "SinglePair")==0){
            initSinglePair(vertexList,numVer,ver1,ver2);
            dijkistra(vertexList,numVer,ver1,ADJ,ver2);
            continue;
        }

        //SingleSource commanmd is entered
        if(strcmp(Word, "SingleSource")==0){
            fprintf(stdout, "i was here\n");
            initSingleSource(vertexList,numVer,ver1);
            dijkistra(vertexList,numVer,ver1,ADJ,0);//pNODE to arrayS
            continue;
        }

        //PrintLength commanmd is entered
        if(strcmp(Word, "PrintLength")==0){
            fprintf(stdout,"PrintLength is pressed.\n");
            printlength(ver1,ver2);
            continue;
        }

        if(strcmp(Word, "PrintPath")==0){
            printPath(ver1,ver2);
            continue;
        }
        return 1;
    }
}
}