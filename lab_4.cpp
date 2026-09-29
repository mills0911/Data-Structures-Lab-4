#include <iostream>
#include <string>
#include <limits>
#include "hash_table.cpp"

int main(){
    int size{199};
    /*
    Input hashtable.add error checks for a few things
    */
    hash_table hashTable(size);
    hashTable.add(5);
    hashTable.add(15);
    hashTable.add(45);
    hashTable.add(55);
    hashTable.add(5);
    hashTable.add(57);

    /*
    need to make a output section here and a retrival in hash_table.cpp
    */
    
}