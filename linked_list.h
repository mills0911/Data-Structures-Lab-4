#include <iostream>
#include <stdexcept>
#include "node.h"
class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    // Default Constructor no initial elements
    LinkedList() : head(nullptr), tail(nullptr), size(0){}
    
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

    Node* at(int element){ // Search given element return pointer
        try {
            if (element < 0 || element >= size) {
                throw std::runtime_error("Out of range of linked list");
            }

            Node* current = head;
            for (int currElement = 0; currElement < element; currElement++) {
                current = current->next;
            }
            return current;
        }
        catch (const std::runtime_error& e) {
            std::cerr << e.what() << '\n';
            throw;
        }
    }
};