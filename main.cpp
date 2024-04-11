#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"
#include "heap.h"
using namespace std;

int main(int argc, char **argv){
    FILE *fp;
    NODE* edge;
    NODE* head = edge;
    int ver1;
    int ver2;
    int returnV;
    char Word[100];

    if (argc < 3){
        fprintf(stderr, "Usage: %s <inputfile> <edgetype> <Flag>\n", argv[0]);
        exit(0);
    }

    fp = fopen(argv[1],"r");
    ifstream file(argv[1]);
    bool firstline = true;
    if(!fp){
        fprintf(stderr,"Error cannot opean file.");
        string line;
        int num1,num2,num3;
        double num4;
        while (getline(file, line)) {
            istringstream iss(line);
            if(firstline){
                if (iss >> num1 >> num2) {
                    cout<<"nums read:" + num1 +num2 <<endl;

                } else {
                    cerr << "Error reading integers from the line." << std::endl;
                }
            }
            else{
                edge = edge->next;
                if (iss >> num1 >> num2 >> num3 >> num4) {
                    cout<<"nums read: "<< num1<<" "<<num2<<" "<<num3<<" "<<num4<<endl;
                    edge->index = num1;
                    edge->u = num2;
                    edge->v = num3;
                    edge->w = num4;
                }
            }
        }
        exit(0);
    }
    fclose(fp);


    while (1){
        returnV = nextInstruction(Word, &ver1, &ver2);
        //if the funtion returns 0 the instruction is invalid
        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }
        // end if STOP is entered
        if (strcmp(Word, "Stop")==0){
            return 0;
        }
        // print command is entered
        if(strcmp(Word, "Print")==0){

            continue;
        }
        // SinglePair command is entered
        if(strcmp(Word, "SinglePair")==0){

            continue;
        }

        //SingleSource commanmd is entered
        if(strcmp(Word, "SingleSource")==0){


            continue;
        }

        //PrintLength commanmd is entered
        if(strcmp(Word, "PrintLength")==0){


            continue;
        }
    }
}