#include <iostream>
#include <string>
#include "hash_table.cpp"
#include "my_vector.h"

// input adds to hash table (use vector to record inputs??)

int main(){
    int size{199};

    // for testing
    int inputs[7] {10,15,10,-5,15,20,-5};
    // Make a pointer to a Hashtable so we can use delete later
    hash_table* hashTable = new hash_table(size); 
    
    /*
    Input hashtable->add error checks for a few things
    */

    hashTable->add(10);
    hashTable->add(15);
    hashTable->add(10);
    hashTable->add(-5);
    hashTable->add(15);
    hashTable->add(20);
    hashTable->add(-5);

    //std::cout <<"Frequency at 5 is: "<< hashTable->frequency(5) << std::endl;

    /*
    need to make a output section here and a retrival in hash_table->cpp
    */
    hashTable->output(inputs);

    // delete hashtable / Reallocated memory
    delete hashTable;
    hashTable = nullptr;


}