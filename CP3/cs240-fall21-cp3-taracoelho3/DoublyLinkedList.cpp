#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP
#include <iostream>

using namespace std;

template<typename T>
class DoublyLinkedList{
    public:
        DoublyLinkedList(){head = tail = nullptr; };
        DoublyLinkedList(const DoublyLinkedList<T> &u){
        cout << "copy constructor" << endl;

           if(u.head == nullptr){
               head = nullptr;
                tail = nullptr;
           }
           else{
               head = new Node<T>(u.head->data);
               Node<T> *curr = head;
               Node<T> *uhead = u.head;
               Node<T> *currU = uhead;
               while(currU->next != nullptr){
                   curr->next = new Node<T>(currU->next->data);
                   currU = currU->next;
                   curr = curr->next;
               }
           }
        }
        void add(const T &newData){
            Node<T> *newNode = new Node<T>(newData);
        
            if(tail != nullptr)
                tail->next = newNode;
            else
                head = newNode;
            tail = newNode;
            
        }
        void display(){
            Node<T> *tmp = head;
            while(tmp){
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
        }

        bool search(const T &key){
            Node<T> *tmp = head;
            bool flag = false;
            while(tmp){
                T curr = tmp->data;
                if(curr == key){
                    flag = true;
                }
                tmp = tmp->next;
            }
            return flag; 
        }

        int searchAndReturnIndex(const T &key){
           Node<T> *tmp = head;
           bool flag = false;
           int i = 1;
           int index = 0;
           while(tmp){
               T curr = tmp->data;
               if(curr == key){
                   flag = true;
                   index = i;
                }
                i++;
                tmp = tmp->next;
            }
           return index;
        }

       bool check(const T &n){
           Node<T> *tmp = head;
           bool flag = false;
           while(tmp){
               T curr = tmp->data;
                if(curr && n){
                    flag = true;
                    return flag;
                }
                else{
                    tmp = tmp->next;
                }
           }
           return flag;
       }

       T& returnAt(int a){
           Node<T> *tmp = head;
          // T curr = tmp->data;
           int inc = 1;
           bool flag = false;
           while(tmp){
              // curr = tmp->data;
               if(inc == a){
                   flag = true;
                   break;
               }
               else{
                   inc++;
                   tmp = tmp->next;
               }
           }
           if(flag == false){
           
               return *head->data;
           }
     
           return *tmp->data;
       }

       DoublyLinkedList<T>& operator=(const DoublyLinkedList<T> &d){
            tail = nullptr;
            head = nullptr;
       }

       ~DoublyLinkedList(){
           Node<T> *temp = head;
           for(;head; temp = head){
               head = head->next;
               delete temp;
           }
       } 


    private:
        template<typename U>
        class Node{
            public:
                Node(T d){data = d; prev = next = nullptr;}
                T data;
                Node<T> *next;
                Node<T> *prev;

        };

        Node<T> *head;
        Node<T> *tail;
};

#endif
