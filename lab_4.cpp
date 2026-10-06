#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <limits>
#include "hash_table.cpp"
#include "my_vector.h"

// input adds to hash table

void output(int input[], hash_table &hashTable) {

    Vector<int> uniqueNums; // would have same # as inputs
    bool unique;

// ok maybe i can do this based on frequency somehow?? idk it's late 🫩

// make vector with only unique elements

    // for every element in input
    for (int i = 0; i < 7; i++) {
        unique = true;
        // compare input element against every uniqueNums element
        for (int j = 0; j < uniqueNums.size(); j++) {
            // if one matches --> breaks out, goes to next input[i]
            if (input[i] == uniqueNums.at(j)) {
                unique = false;
                break;
            }
        }
        // only runs if # appears once in input array
        if (unique) {
            uniqueNums.pushback(input[i]);
        }
    }

    uniqueNums.display(); // just for testing

    // use uniqueNums vector to see each input's frequency
    for (int i = 0; i < uniqueNums.size(); i++) {
        std::cout << "Value: " << uniqueNums.at(i) << " -> Frequency: " << hashTable.frequency(uniqueNums.at(i)) << std::endl;
    }

}

int main(){
    int size{199};

    // for testing
    int inputs[7] {10,15,10,-5,15,20,-5};

    /*
    Input hashtable.add error checks for a few things
    */
    hash_table hashTable(size);
    // hashTable.add(5);
    // hashTable.add(15);
    // hashTable.add(45);
    // hashTable.add(55);
    // hashTable.add(5);
    // hashTable.add(57);

    hashTable.add(10);
    hashTable.add(15);
    hashTable.add(10);
    hashTable.add(-5);
    hashTable.add(15);
    hashTable.add(20);
    hashTable.add(-5);

    //std::cout <<"Frequency at 5 is: "<< hashTable.frequency(5) << std::endl;

    /*
    need to make a output section here and a retrival in hash_table.cpp
    */
    output(inputs, hashTable);

}