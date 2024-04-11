#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, int *ver1, int *ver2){

    int returnV;
    int returnV2;

    fscanf(stdin, "%s", Word); //getting input from user

    if(strcmp(Word, "Stop")==0) return 1;
    if(strcmp(Word, "PrintADJ")==0) return 1;
    
    if(strcmp(Word, "SinglePair")==0){
        returnV = fscanf(stdin,"%d", ver1);
        returnV2 = fscanf(stdin,"%lf", ver2);
        if(returnV==1) return 1;
        else if(returnV2==1) return 1;
        else return 0;
    }

    if(strcmp(Word,"SingleSource")){
        returnV = fscanf(stdin,"%d", ver1);
        if(returnV==1) return 1;
        else return 0;
    }

    if(strcmp(Word,"PrintLength")){
        returnV = fscanf(stdin,"%d", ver1);
        returnV2 = fscanf(stdin,"%lf", ver2);
        if(returnV==1) return 1;
        else if(returnV2==1) return 1;
        else return 0;
    }

    return 0;
}