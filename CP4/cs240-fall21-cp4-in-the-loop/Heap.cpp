#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
    arr = new Vote[10000];
    capacity = 10000;
    size = 0;
}

Heap::Heap(int cap) {
    arr = new Vote[cap];
    capacity = cap;
    size = 0;
}

Heap::~Heap() {
    delete[] arr;
}
Vote Heap::parent(int i) {
    return arr[(i-1)/2];
}

Vote Heap::left(int i) {
    return arr[2*i+1];
}

Vote Heap::right(int i) {
    return arr[2*i+2];
}

int Heap::getSize() {
    return size;
}

bool Heap::isEmpty() {
    return size == 0;
}

void Heap::maxHeapify(int i) {
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if (l < size && arr[l] > arr[i]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        Vote temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(largest);
    }
}

void Heap::buildHeap() {
    for (int i = size/2; i >= 0; i--) {
        maxHeapify(i);
    }
}

void Heap::insert(Vote &v) {
    if (size == capacity) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[size] = v;
    size++;
    buildHeap();
}

Vote Heap::extractMax() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        //return;
    }
    Vote v = arr[0];
    arr[0] = arr[size-1];
    size--;
    maxHeapify(0);
    return v;
}

void Heap::increase_key(Vote& ptr, int inc){
    for(int i = 0; i < size; i++){
        if(arr[i] == ptr){
            arr[i].incVote(inc);
            ptr.incVote(inc);
        }
    }
    buildHeap();
}

void Heap::display(){
   
    for(int i = 0; i < size; i++){
        std::cout << "element " << arr[i] << std::endl;
    }
}