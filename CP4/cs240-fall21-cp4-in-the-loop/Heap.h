#pragma once
#include "Vote.h"
#include <string>


class Heap {
   private:
      Vote *arr;
      int capacity; 
      int size;
      Vote parent(int i);
      Vote left(int i);
      Vote right(int i);
   public:
      Heap();
      Heap(int cap);
      ~Heap();
      void insert(Vote &v);
      Vote extractMax();
      int getSize();
      bool isEmpty();
      void buildHeap();
      void maxHeapify(int i);
      void increase_key(Vote& ptr, int inc);
      void display();
};