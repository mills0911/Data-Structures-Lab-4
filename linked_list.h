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
    // Constructor with 1 initial elements
    LinkedList(int number) : head(new Node(number)), tail(head), size(1){}
    // Deconstructor
    ~LinkedList() {
        MakeEmpty();
    }
    // Functions
    int getSize() const { return size; };
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
    int count(auto num) const {// return count of a given number 
        int count = 0;
        for (Node* curr = head; curr != nullptr; curr=curr->next){
            if (curr->data == num){
                count++;
            }
        }
        return count;
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