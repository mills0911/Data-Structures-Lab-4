#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector() {
        arrSize = 1;
        length = 0;
        vector = new T[arrSize];
    }

    virtual ~Vector() {
        delete []vector;
    }

    void pushback(const T &element) {
        if (length == arrSize) {
            resize();
        }
        vector[length++] = element;
    }

    T at(int index) {
        if (index < length && index >= 0) {
            return vector[index];
        } else {
            throw std::out_of_range("Index exceeds range");
        }
    }

    void replace(int index, T element) {
        if (index < length && index >= 0) {
            vector[index] = element;
        } else {
            throw std::out_of_range("Index exceeds range");
        }
    }

    int size() const {
        return length;
    }

    void display() const {
        if (length == 0) {
            std::cout << "Vector is empty" << std::endl;
        } else {
            for (int i = 0; i < length; i++) {
                std::cout << vector[i] << ", ";
            }
            std::cout << std::endl;
        }
    }

private:
    int arrSize;
    int length;
    T *vector;

    void resize() { // if input exceeds default size, transfers to newly sized array
        int newSize = arrSize * 2;
        T *newVector = new T[newSize]; // new array
        for (int i = 0; i < arrSize; i++) {
            newVector[i] = vector[i]; // copy existing data
        }

        delete []vector; // dealloc data at array pointer
        vector = newVector; // array pointer now points to the new array
        arrSize = newSize;
    }
};