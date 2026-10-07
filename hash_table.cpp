#include "linked_list.h"
#include <cstdlib> // for abs
#include "my_vector.h"

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
    hash_table(const int &size){
        if (size <= 0) // check if >0
            throw std::invalid_argument("Hash table size must be greater than 0");
        if ((size >= MAX_SIZE) || (size <= MIN_SIZE)) // check range 
            throw std::invalid_argument("Hash table size must be in range of 101-211");
        for (int i{2}; i < size; i++)  // check for prime
            if ((size % i) == 0 ) throw std::invalid_argument("Hash table needs to be a Prime Number");

        // Creation
        this->size = size;
        buckets = new LinkedList*[size]{}; // array of pointers; buckets start as null
    }
    // Destructor
    ~hash_table() {
        for (int i{0}; i < size; i++)
            delete buckets[i]; // delete pointer to LL at each index
        delete[] buckets;
    }

    void add(int numberToAdd){
        // validation
        if ((numberToAdd > MAX_ADD_SIZE) || (numberToAdd < MIN_ADD_SIZE))
            throw std::invalid_argument("Number to be added is out of range of instructions");
        //calculate idx once
        int idx = (std::abs(numberToAdd) % size);
        //check if bucket is already a LL
        if (buckets[idx] == nullptr) {
            buckets[idx] = new LinkedList(numberToAdd); // initialize + add at same time
        }
        else {
            buckets[idx]->append(numberToAdd);
        }
    }

    int bucketSize(const int &num){ // Get size of LL Given index
        // Get bucket to check
        const LinkedList* currBucket = buckets[(std::abs(num) % size)];
        if (currBucket == nullptr)
            return 0;
        else
            return currBucket->getSize(); // LL function, not hash function
    }
    int frequency(const int &num){ // get Freq of a number given index
        // Get bucket to check
        const LinkedList* currBucket = buckets[(std::abs(num) % size)];
        if (currBucket == nullptr)
            return 0;
        else
            return currBucket->count(num);
    }

    void output(const int input[]) {

        Vector<int> uniqueNums; // would have same # as inputs
        bool unique;

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
            std::cout << "Value: " << uniqueNums.at(i) << " -> Frequency: " << frequency(uniqueNums.at(i)) << std::endl;
        }

    }
};
