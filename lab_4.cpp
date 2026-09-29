#include <iostream>
#include <string>
#include <limits>
#include "hash_table.cpp"

int main(){
    int size{199};
    /*
    Input
    */
    hash_table hashTable(size);
    hashTable.add(5);
    hashTable.add(15);
    hashTable.add(45);
    hashTable.add(55);
    hashTable.add(5);
    hashTable.add(57);

    hashTable
}