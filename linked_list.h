#include <iostream>
#include <stdexcept>
#include "node.h"
class LinkedList { //singley linked list
private:
    Node* head;
    Node* tail;
    int size;
public:
    // Default Constructor no initial elements
    LinkedList() : head(nullptr), tail(nullptr), size(0){}
    // Deconstructor
    ~LinkedList() {
        MakeEmpty();
    }
    // Functions
    int getSize(){return size;};
    void append(int num){    // ADD TO BACK
        Node* node = new Node(num);

        if (size == 0) {
            head = node;
            tail = node;
        } 
        else {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    
    void MakeEmpty(){ 
        Node* temp;
        while (head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
        tail = nullptr;
    }

    Node* at(int index){ // Search given index return pointer
        if (index < 0 || index >= size) {
            throw std::runtime_error("Out of range of linked list");
        }

        Node* current = head;
        for (int currIndex = 0; currIndex < index; currIndex++) {
            current = current->next;
        }
        return current;
    
    }

};