#include "linked_list.h"
#include <cstdlib> // for abs
class hash_table{ // Array of linked lists
private:
    int size;
    /*Restrains*/
    static constexpr int 
        MAX_SIZE = 211,
        MIN_SIZE = 101,
        MAX_ADD_SIZE = 10000,
        MIN_ADD_SIZE = -10000;
    // Hash table
    LinkedList** buckets; //list of ptrs
public:
    // Creation setting size / allocated memory
    hash_table(int size){
        if (size <= 0) // check if >0
            throw std::invalid_argument("Hash table size must be greater than 0");
        if ((size >= MAX_SIZE) || (size <= MIN_SIZE)) // check range 
            throw std::invalid_argument("Hash table size must be in range of 101-211");
        for (int i{2}; i < size; i++)  // check for prime
            if ((size % i) == 0 ) throw std::invalid_argument("Hash table needs to be a Prime Number"); 

        // Creation
        this->size = size;
        buckets = new LinkedList*[size]{}; // buckets start as null
    }
    // Destructor
    ~hash_table() {
        for (int i =0; i<size; i++)
            delete buckets[i];
        delete[] buckets;
    }

    void add(int numberToAdd){
        if ((numberToAdd > MAX_ADD_SIZE) || (numberToAdd < MIN_ADD_SIZE)) 
            throw std::invalid_argument("Number be added is out of range of instructions");
        //calculate idx once 
        int idx = (std::abs(numberToAdd) % size);
        //check if bucket is aleady a LL
        if (buckets[idx] == nullptr){ 
            buckets[idx] = new LinkedList(numberToAdd); 
        }
        else{ 
            buckets[idx]->append(numberToAdd);
        }
    }

    int bucketSize(int num){ // Get size Given index
        // Get bucket to check 
        const LinkedList* currBucket = buckets[(std::abs(num) % size)];
        if (currBucket == nullptr) 
            return 0;
        else 
            return currBucket->getSize();
    }
    int frequency(int num){ // get Freq Given index
        // Get bucket to check 
        const LinkedList* currBucket = buckets[(std::abs(num) % size)];
        if (currBucket == nullptr) 
            return 0;
        else 
            return currBucket->count(num);

    }
};