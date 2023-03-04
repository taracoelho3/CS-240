#include <iostream>

using namespace std;

template<class T>
class Node{
    public:
        Node(){
            this->next = NULL;
            this->prev = NULL;
        }
        Node(T val){
            this->next = NULL;
            this->prev = NULL;
            this->val = val;
        }
    
    private:
        T data;
        Node<T> *next;
        Node<T> *prev;

};
