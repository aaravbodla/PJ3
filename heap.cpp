#include "heap.h"
#include "data_structures.h"
#include <iostream>
#include <cmath> 
using namespace std;

// heapifycalls for counting number of heapify calls
int  heapifycalls = 0;

void heapify(HEAP* h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is smaller than parent
    if (left < h->size && h->A[left]->distance < h->A[smallest]->distance) {
        smallest = left;
    }

    // Check if right child is smaller than smallest so far
    if (right < h->size && h->A[right]->distance < h->A[smallest]->distance) {
        smallest = right;
    }

    // If smallest is not the root
    if (smallest != i) {
        // Swap vertices
        pVERTEX temp = h->A[i];
        int temp_heappos = h->A[i]->heappos;

        h->A[i] = h->A[smallest];
        h->A[i]->heappos = temp_heappos;

        h->A[smallest] = temp;
        h->A[smallest]->heappos = smallest;

        // Recursively heapify the affected subtree
        heapify(h, smallest);
    }
}

void buildHeap(HEAP* h, int n){
    int i = n/2-1;
    for(int r = i;r>=0;r--){
        heapify(h,r);
        heapifycalls++;
    }
}

pVERTEX extractMin(HEAP* h) {
    if (h == NULL) {
        cout << "Error: heap is Null";
        return NULL;
    }
    if (h->size <= 0) {
        fprintf(stderr, "Error: heap is empty\n");
        return NULL;
    }
    pVERTEX minVertex = h->A[0];
    h->size = h->size - 1;
    h->A[0] = h->A[h->size]; // Replace the root with the last element
    h->A[0]->heappos = 0; // Update heappos for the root vertex
    heapify(h, 0); // Heapify the heap from the root

    printf("ExtractMin: %d\n", minVertex->index);
    return minVertex;
}

void decreaseKey(HEAP* h, int position, double newKey) {
    int i = position;

    if (h == NULL) {
        cout << "Error: heap is Null" << endl;
        return;
    }

    if (h->size == 0 || i >= h->size || i < 0) {
        cout << "Error: invalid call to DecreaseKey" << endl;
        return;
    }

    if (newKey > h->A[i]->distance) {
        cout << "Error: new key is not smaller than the current key" << endl;
        return;
    }

    h->A[i]->distance = newKey;
    while (i != 0 && h->A[(i - 1) / 2]->distance > h->A[i]->distance) {
        // Swap vertices
        pVERTEX temp = h->A[i];
        int temp_heappos = h->A[i]->heappos;

        h->A[i] = h->A[(i - 1) / 2];
        h->A[i]->heappos = temp_heappos;

        h->A[(i - 1) / 2] = temp;
        h->A[(i - 1) / 2]->heappos = (i - 1) / 2;

        i = (i - 1) / 2;
    }
}

void insertion(HEAP* h, pVERTEX newKey) {
    if (h->capacity == 0) {
        cout << "Error: heap is Empty";
        return;
    }
    if (h->size == h->capacity) {
        cout << "Error: heap is full";
        return;
    } 
    if (h->A[0] == NULL) fprintf(stderr, "0 is NULL.\n");
    h->A[h->size] = newKey;
    newKey->heappos = h->size; // Set heappos for the new vertex
    h->size++;
    int i = h->size - 1;
    while (i > 0 && h->A[(i - 1) / 2]->distance > h->A[i]->distance) {
        // Swap vertices
        pVERTEX temp = h->A[i];
        int temp_heappos = h->A[i]->heappos;

        h->A[i] = h->A[(i - 1) / 2];
        h->A[i]->heappos = temp_heappos;

        h->A[(i - 1) / 2] = temp;
        h->A[(i - 1) / 2]->heappos = (i - 1) / 2;

        i = (i - 1) / 2;
    }
    return ;
}

void printHeap(HEAP* h) {
    if (h == NULL) {
        fprintf(stderr, "heap is empty .\n");
        return; //cout<<"Error: heap is NUll"<<endl;
    } 
    for (int i = 0; i < h->size; i++) {
        printf("index : %d, heappos: %d, Distance :%lf\n", h->A[i]->index, h->A[i]->heappos,h->A[i]->distance);
    }
}
