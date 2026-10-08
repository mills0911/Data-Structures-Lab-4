#include <iostream>
#include "hash_table.cpp"
#include "my_vector.h"

int main(){
    int size{199};

    // Make a pointer to a Hashtable so we can use delete later
    hash_table* hashTable = new hash_table(size); 
    std::cout << "Hash table size: " << size << std::endl;

    Vector<int> userInputs = hashTable->userInputs();
    hashTable->output(userInputs);

    // delete hashtable / Reallocated memory
    delete hashTable;
    hashTable = nullptr;
}