#include "heap.h"
#include "data_structures.h"
#include <iostream>
using namespace std;

// heapifycalls for counting number of heapify calls
int  heapifycalls = 0;

void heapify(HEAP* h, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int min = i;

    if(left < h->size && h->A[left]->key < h->A[i]->key){
        min = left;
    }else min = i;
    if(right < h->size && h->A[right]->key < h->A[min]->key){
        min = right;
    }
    if(min != i){
        VERTEX* temp = h->A[i];
        h->A[i] = h->A[min];
        h->A[min] = temp;
        heapify(h,min);
        heapifycalls++;
    }
    return;
}

void buildHeap(HEAP* h, int n){
    int i = n/2-1;
    for(int r = i;r>=0;r--){
        heapify(h,r);
        heapifycalls++;
    }
}

void extractMin(HEAP* h){
    if(h == NULL){
        cout<< "Error: heap is Null";
        return;
    }
    if(h->size <= 0)
    {
        fprintf(stderr,"Error: heap is NULL\n");
        return;
    }
    heapifycalls++;
    double minimum = h->A[0]->key;
    h->A[0]->key = h->A[h->size -1]->key;
    h->size = h->size - 1;
    heapify(h,0);
    fprintf(stdout,"ExtractMin: %lf\n",minimum);
}

void decreaseKey(HEAP* h,int position,double newKey){
    int i = position-1;
    if(h->size == 0){
        cout<< "Error: heap is Empty";
        return;
    }
    if(h==NULL){
        cout<<"Heap is Null"<<endl;
        return;
    }
    if(((i > h->size) && (i < 0))  || newKey > h->A[i]->key){
        cout << "Error: invalid call to DecreaseKey" << endl;
        return;
    }

        h->A[i]->key = newKey;
     while(i != 0 && h->A[(i-1)/2]->key > h->A[i]->key ){
            double temp1 = h->A[i]->key;
            h->A[i]->key = h->A[(i-1)/2]->key;
            h->A[(i-1)/2]->key = temp1;
            i = (i-1)/2;
    }
    return;
}

void insertion(HEAP* h,double newKey){
    if(h->size == 0){
        //cout<< "Error: heap is Empty";
        return;
    }
    if(h->size == h->capacity){
        //cout<< "Error: heap is full";
        return;
    }

    h->A[h->size]->key = newKey;
    h->size++;
    int i = h->size-1;
    while(i != 0 && h->A[(i-1)/2]->key > h->A[i]->key ){
            double temp1 = h->A[i]->key;
            h->A[i]->key = h->A[(i-1)/2]->key;
            h->A[(i-1)/2]->key = temp1;
            i = (i-1)/2;
    }
    return ;
}

void printHeap(HEAP* h){
    if(h==NULL) return ; //cout<<"Error: heap is NUll"<<endl;
    fprintf(stdout, "%d", h->size);
    for(int i = 0;i < h->size ; i++){
        fprintf(stdout,"\n");
        fprintf(stdout, "%lf", h->A[i]->key);
    }
}